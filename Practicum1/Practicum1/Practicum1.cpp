#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


long long FibonacciTask1(int num) {
    if (num == 1 || num == 2) return 1;
    return FibonacciTask1(num - 2) + FibonacciTask1(num - 1);

}

long long FibonacciTask2(int k, int num, long long prev1, long long prev2) {
    if (k == num) return prev2;
    else if (k < num) {
        return  FibonacciTask2(k + 1, num, prev2, prev1 + prev2);
    }
}


string Task1(int num) {
    stringstream functionOutput;
    if (num > 40) {
        functionOutput << "Invalid input data" << endl;
    }
    else if (num <= 0) {
        functionOutput << "Error" << endl;
    }
    else {
        int i = 1;
        while (i <= num) {
            functionOutput << FibonacciTask1(i) << " "; ++i;

        }
    }
    string result = functionOutput.str();
    result.pop_back();
    return result;
}


string Task2(int num) {
    stringstream functionOutput;
    if (num > 40) functionOutput << "Invalid input data" << endl;
    else if (num <= 0) functionOutput << "Error" << endl;
    else {
        int i = 1;
        while (i <= num) {
            functionOutput << FibonacciTask2(1, i, 0, 1) << " ";
            i++;
        }

    }
    string result = functionOutput.str();
    result.pop_back();
    return result;
}




int main()
{
    cout << "Task 1: " << Task1(13);
    cout << "\nTask 2: " << Task2(19);

    return 0;
}