#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

string Task1(string textFile, string keyFile) {
    stringstream functionOutput;

    char* X = new char[1000];
    char* Y = new char[1000];
    char* Z = new char[1000];
    char K[32];

    ifstream textF(textFile);
    if (!textF.is_open()) return "Error";

    ifstream keytF(keyFile);
    if (!keytF.is_open())  return "Error";

    string text; char c;
    while (textF.get(c)) {
        text += c;
    }
    textF.close();


    keytF.getline(K, 32);
    keytF.close();


    strcpy(X, text.c_str());

    for (int i = 0; i < strlen(X); i++) {
        Y[i] = X[i] ^ K[i % strlen(K)];
    }


    for (int i = 0; i < strlen(X); i++) {
        Z[i] = Y[i] ^ K[i % strlen(K)];
    }

    for (int i = 0; i < strlen(X); i++) {
        if (Y[i] < 32) {
            functionOutput << '.';
        }
        else {
            functionOutput << Y[i];
        }
    }
    functionOutput << "\n";

    for (int i = 0; i < strlen(X); i++) {
        functionOutput << Z[i];
    }

    return functionOutput.str();
}

int main()
{
    std::cout << Task1("message.txt", "keytext.txt");
}
