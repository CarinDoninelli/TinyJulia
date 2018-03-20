//
// Created by Edwin Herrera on 3/20/18.
//

#include "utils.h"

#include <regex>

static int counter = 0;

string ebp(int offset) {
    return "DWORD [ebp-" + to_string(offset) + "]";
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



