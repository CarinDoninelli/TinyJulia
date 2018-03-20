//
// Created by Edwin Herrera on 3/20/18.
//

#include "utils.h"

#include <ctime>
#include <regex>

string ebp(int offset) {
    return "DWORD [ebp-" + to_string(offset) + "]";
}

string newLabel() {
    srand(static_cast<unsigned int>(time(nullptr)));
    auto random = rand() % 20000 + 1; // NOLINT
    return string("L") + to_string(random);
}

string escapedString(const string &str) {
    string escaped = regex_replace(str, regex("\\\\n"), "\n");
    return escaped;
}

char *charPtr(const string &str) {
    char * writable = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), writable);
    writable[str.size()] = '\0';
    return writable;
}



