#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <climits>
using namespace std;


// Завдання 1

string Task1(int n) {
    stringstream functionOutput;
    if (n <= 0) return "Error";

    int* d_arr = new int[n];

    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            d_arr[i] = i + 1;
        }
        else {
            d_arr[i] = n - i;
        }
    }

    for (int i = 0; i < n; i++) functionOutput << d_arr[i] << " ";

    delete[] d_arr;

    return functionOutput.str();
}



// Завдання 2
// 
// Функція має повертати рядок, який міститиме вивід мільйонного елемента 
// масиву послідовних простих чисел. Наприклад:
// Task2() - "15485863" (без лапок)
string Task2() {
    stringstream functionOutput;
    int* listOfPrimes = new int[1000000];
    listOfPrimes[0] = 2;
    listOfPrimes[1] = 3;

    int num = 2;

    for (int i = 5; num < 1000000; i += 2) {
        bool isPrime = true;
        for (int j = 0; listOfPrimes[j] * listOfPrimes[j] <= i && j < num; ++j) {
            if (i % listOfPrimes[j] == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            listOfPrimes[num++] = i;
        }
    }

    functionOutput << listOfPrimes[999999];
    delete[] listOfPrimes;

    return functionOutput.str();
}


// Завдання 3
// 
// Функція приймає у якості аргументів кількість рядків rows та кількість 
// стовпців cols двовимірного масиву.
// 
// У випадку коректного значення розмірів масиву, функція має повертати рядок,
// який міститиме вивід елементів масиву по рядках: між елементами рядка не 
// повинні знаходитись розділові знаки, а після останнього рядка теж повинен 
// бути присутній перехід на новий рядок. Наприклад:
// Task3(5,6) - "111111\n122221\n125521\n122221\n111111\n" (без лапок)
// 
// У випадку некоректного значення розмірів масиву, функція має повертати вивід
// "Error" (без лапок).
string Task3(int rows, int cols) {
    if (rows <= 0 || cols <= 0) {
        return "Error";
    }
    int** d_arr = new int* [rows];
    for (int i = 0; i < rows; ++i)  d_arr[i] = new int[cols];

    stringstream functionOutput;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                functionOutput << 1;
            }
            else if (i > 1 && i < rows - 2 && j > 1 && j < cols - 2) {
                functionOutput << 5;
            }
            else { functionOutput << 2; }
        }
        functionOutput << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] d_arr[i];
    }
    delete[] d_arr;

    // Конвертування об'єкту stringstream у рядок для відповідності сигнатурі функції
    return functionOutput.str();
}



// Завдання 4
// 
// Функція приймає у якості аргумента рядок адреси (назви) файлу з набором 
// цілих чисел у діапазоні від 0 до 999 (включно), які розділені пробілами - 
// textFile та кількість рядків rows і кількість стовпців cols двовимірного 
// масиву.

void FindMax(int** arr, int rows, int cols, int* row_max, int* col_max) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            row_max[i] = max(row_max[i], arr[i][j]);
            col_max[j] = max(col_max[j], arr[i][j]);
        }
    }
}

string FormatTable(int** arr, int rows, int cols, int* row_max, int* col_max) {
    stringstream functionOutput;

    for (int i = 0; i < rows; ++i) {
        functionOutput << setw(3) << arr[i][0];
        for (int j = 1; j < cols; ++j)  functionOutput << " " << setw(3) << arr[i][j];
        functionOutput << "  |" << setw(5) << row_max[i] << " " << '\n';
    }
    for (int i = 0; i < cols; ++i)  functionOutput << "----";
    functionOutput << "-+-----\n";

    functionOutput << setw(3) << col_max[0];
    for (int i = 1; i < cols; ++i)  functionOutput << " " << setw(3) << col_max[i];

    int general_max = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            general_max = max(general_max, arr[i][j]);
        }
    }
    functionOutput << "  |" << setw(5) << general_max << " " << '\n';
    return functionOutput.str();
}

string Task4(const string& text_file, int rows, int cols) {
    if (rows <= 0 || cols <= 0) return "Error";

    ifstream file(text_file);
    if (!file.is_open())  return "No such file or file is corrupted";

    int** arr = new int* [rows];
    for (int i = 0; i < rows; ++i) arr[i] = new int[cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(file >> arr[i][j])) {
                return "Insufficient data";
            }
        }
    }

    int* row_max = new int[rows];
    int* col_max = new int[cols];
    for (int i = 0; i < rows; ++i) row_max[i] = INT_MIN;
    for (int j = 0; j < cols; ++j) col_max[j] = INT_MIN;
    FindMax(arr, rows, cols, row_max, col_max);

    string result = FormatTable(arr, rows, cols, row_max, col_max);
    return result;
}



int main()
{
    std::cout << "Task1: " << Task1(30);
    std::cout << "\nTask2: " << Task2();
    std::cout << "\nTask3: \n" << Task3(5, 6);
    std::cout << "\nTask4: \n" << Task4("numbers.txt", 5, 6);
}