#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<iomanip>
using namespace std;

// ������������� �������� ��������� ������� Task1!
// ������������� ��������������� �������� ����!

// ������� ���������� ������� ������������ ����� �� ������ � ��������
// �� ������� ���������� ���������. �������� ����� ������, �����, ������ �� 
// ���� �� ���� ������.

int CalculationsTask1(vector<vector<int>>& lab, int rows, int cols, int currRow, int currCol, int currSteps) {

    if (lab[currRow][currCol] == 9)  return currSteps;
    lab[currRow][currCol] = 1;

    vector<pair<int, int>> way = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    int minPath = INT_MAX;

    for (int i = 0; i < way.size(); ++i) {
        int nextRow = currRow + way[i].first;
        int nextCol = currCol + way[i].second;

        if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && lab[nextRow][nextCol] != 1) {
            int length = CalculationsTask1(lab, rows, cols, nextRow, nextCol, currSteps + 1);
            if (length != INT_MAX) {
                minPath = min(minPath, length);
            }
        }
    }
    lab[currRow][currCol] = 0;
    return minPath;
}

// �������� 1
// 
// ������� ������ � ����� ���������: 
// * ����� ������ (�����) ����� textFile, ���� ������ ����� �������� 
//   (���������� ������ � ������ ����������� ������ 0, 1 �� 9, ��������� 
//   �������� �� ���������� �� ����� �����, ��� ����� �� ���� ������� ��� 
//   ����������:
//   0 - ������� ��� ������� ������, 
//   1 - ����,
//   9 - ����� (�� ������ � � ������)); 
// * ������ ����� ������: rowsCount (������� �����) �� 
//                         colsCount (������� ��������);
// * �������� ����������: startRow (����� ���������� �����, ��������� �� 0, 
//                                   �� � �������) ��
//                         startCol (����� ���������� �������, ��������� �� 0, 
//                                   �� � �������).
// ���������� ������� ������������ ����� �� ������ ��������� ����� �� ������ 
// ����������� �� ��������� ���������� ������� CalculationsTask1.
// 
string Task1(string textFile, int rowsCount, int colsCount, int startRow, int startCol) {
    stringstream functionOutput;

    if (rowsCount <= 0 || colsCount <= 0)  return "Wrong dimensions";

    if (startRow < 0 || startRow >= rowsCount || startCol < 0 || startCol >= colsCount) {
        return "The starting point is outside the maze";
    }

    ifstream mazeFile(textFile);
    if (!mazeFile.is_open()) return "No such file or file is corrupted";

    vector<vector<int>> maze(rowsCount, vector<int>(colsCount, 0));

    for (int i = 0; i < rowsCount; i++) {
        for (int j = 0; j < colsCount; j++)  mazeFile >> maze[i][j];
    }

    if (maze[startRow][startCol] == 1) return "The starting point is in the wall";

    functionOutput << "The shortest path consists of " << CalculationsTask1(maze, rowsCount, colsCount, startRow, startCol, 0) << " steps";
    return functionOutput.str();
}



int main()
{
    std::cout << "Task1: " << Task1("jungle.txt", 5, 10, 2, 2);
}
