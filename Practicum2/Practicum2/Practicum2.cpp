#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


// Функція знаходження суми ряду для заданої кількості членів. 
double CalculationsTask1(int n) {
    if (n == 0) return 0;
    else {
        return 1.0 / pow(n, 4) + CalculationsTask1(n - 1);
    }
}

// Функція знаходження значення ланцюгового дробу для заданої кількості членів. 
double CalculationsTask2(int n, double res) {
    if (n == 0)  return res + 2;
    else {
        return  CalculationsTask2(n - 1, 1 / (res + ((pow(n + 2, 2) - 2))));
    }
}


// Функція знаходження суми ряду для заданої кількості членів (кількості у 
// кожній із сум). 
double CalculationsTask3(int n, double res = 0.0) {

    if (n == -1)
    {
        return res * 4;
    }
    else if (n % 2 != 0)
    {
        res -= (1 / ((2.0 * n) + 1)) * ((1 / pow(2.0, (2.0 * n) + 1)) + (1 / pow(3.0, (2.0 * n) + 1)));
    }
    else {
        res += (1 / ((n * 2.0) + 1)) * ((1 / pow(2.0, (n * 2.0) + 1)) + (1 / pow(3.0, (n * 2.0) + 1)));
    }

    return CalculationsTask3(n - 1, res);
}



// Завдання 1
string Task1(int n) {
    stringstream resultStream;

    if (n <= 0) return "Error";

    double res = sqrt(sqrt(90.0 * CalculationsTask1(n)));

    resultStream << setprecision(12) << res;

    return resultStream.str();
}



// Завдання 2

string Task2(int precision) {
    stringstream functionOutput;

    if (precision < 0) return "Error";
    double res = CalculationsTask2(precision, 0);
    functionOutput << setprecision(15) << res;
    return functionOutput.str();
}

// Завдання 3

string Task3(int precision) {
    stringstream functionOutput;

    if (precision < 0) return "Error";
    functionOutput << setprecision(15) << CalculationsTask3(precision);

    return functionOutput.str();
}

int main()
{
    std::cout << "Task1: " << Task1(30);
    std::cout << "\nTask2: " << Task2(30);
    std::cout << "\nTask3: " << Task3(30);
}
