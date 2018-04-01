//
// Created by Edwin Herrera on 3/20/18.
//

#include "utils.h"

#include <regex>
#include <sstream>
#include <iostream>

static int counter = 0;

string ebp(int offset) {
    string value = (offset >= 0) ? "-" + to_string(offset) : "+" + to_string(-offset);
    return "DWORD [ebp" + value + "]";
}

string newLabel() {
    return string("L") + to_string(counter++);
}

string escapedString(const string &str) {
    string escaped = regex_replace(str, regex("\\\\n"), "\n");
    return escaped;
}

char *charPtr(const string &str) {
    auto writable = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), writable);
    writable[str.size()] = '\0';
    return writable;
}


std::string joinExpressions(const vector<Expression *> &vector) {
    stringstream output;
    for (const auto &item : vector) {
        output << item << " ";
    }
    return output.str();
}

std::string toASMLiteral(const string &str) {    
    // stringstream literal;
    // literal << '"';
    // for (const auto &c : str) {
    //     if (c == '\n') {
    //         literal << '"' << ", 10, " << '"'; 
    //     }
    //     else if (c == '"') {
    //         literal << '"' << ", 8, " << '"';
    //     }
    //     else {
    //         literal << c;
    //     }
    // }
    // literal << '"' << ", 0";

    return "`" + str + "`, 0";
}

