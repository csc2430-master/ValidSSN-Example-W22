// Title:   main.cpp
//
// Purpose: Read a file containing lines of the form "name, SSN"
//          Print out the lines that have the correct format and for which the SSN field is valid
//
// Class:   CSC 2430 Winter 2022
// Author:  Max Benson
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

// Forward declarations of functions
bool CheckLine(const string& line);
bool IsSSN(const string& s);

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
            if (CheckLine(line)) {
                cout << line << endl;
            }
        }
        in.close();
    }
    return 0;
}

/**
 * Check Line
 * Searches for the position of the comma.  Then forms the substring starting after the comma
 * and runing to end of line.  Checks if that substring is formatted like a valid US Social Security Number.
 * @param line  - a line read from the input file
 * @return true if the comma found and the SSN field is valid, false otherwise
 */
bool CheckLine(const string& line) {
    size_t position;
    string possibleSSN;

    position = line.find(',');
    if (position == string::npos) {
        return false;
    }

    possibleSSN = line.substr(position + 1, line.length() - position);
    return IsSSN(possibleSSN);
}

/**
 * Is SSN
 * Determines if a string has format of the a valid US Social Security Number
 * i.e ###-##-#### where # is a digit from 0-9.
 * @param s the string to validate
 * @return true if s is correctly formatted, false otherwise
 */
bool IsSSN(const string& s) {
    string format = "###-##-####";

    if (s.length() != format.length()) {
        return false;
    }
    for (size_t i = 0; i < format.length(); i ++) {
        if (format[i] == '#') {
            if (!isdigit(s[i])) {
                return false;
            }
        }
        else if (s[i] != '-'){
            return false;
        }
    }
    return true;
}
