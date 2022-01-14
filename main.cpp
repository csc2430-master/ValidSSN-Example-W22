// Title:   main.cpp
//
// Purpose: Read a file containing lines of the form "name, SSN"
//          Print out the lines that have the correct format and for which the SSN field is valid
//
// Class:   CSC 2430 Winter 2022
// Author:  Max Benson
// Date:    2022-01-11
//
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ostream;
using std::string;

#include "IsValidLine.h"

int main() {
    ifstream in;
    string fileName;

    cout << "Input File Name:";
    getline(cin, fileName);
    in.open(fileName);
    if (!in.is_open()) {
        cout << "Can't open '" << fileName << "'" << endl;
    }
    else {
        string line;

        while (getline( in, line )) {
            if (IsValidLine(line)) {
                cout << line << endl;
            }
        }
        in.close();
    }
    return 0;
}

