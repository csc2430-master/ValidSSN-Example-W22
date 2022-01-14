// Title:   IsValidLine.cpp
//
// Purpose: Contains a function used to check whether a line contains a comman
//          followed by a characters that make up a valid US Social Security Number
//
// Class:   CSC 2430 Winter 2022
// Author:  Max Benson
// Date:    2022-01-13
//
#include <string>
using std::string;

// Forward declarations of functions
bool IsValidSSN(const string& s);

/**
 * Check Line
 * Searches for the position of the comma.  Then forms the substring starting after the comma
 * and runing to end of line.  Checks if that substring is formatted like a valid US Social Security Number.
 * @param line  - a line read from the input file
 * @return true if the comma found and the SSN field is valid, false otherwise
 */
bool IsValidLine(const string& line) {
    size_t position;
    string possibleSSN;

    position = line.find(',');
    if (position == string::npos) {
        return false;
    }

    possibleSSN = line.substr(position + 1, line.length() - position);
    return IsValidSSN(possibleSSN);
}

/**
 * Is Valid SSN
 * Determines if a string has format of the a valid US Social Security Number
 * i.e ###-##-#### where # is a digit from 0-9.
 * @param s the string to validate
 * @return true if s is correctly formatted, false otherwise
 */
bool IsValidSSN(const string& s) {
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
