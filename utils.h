//
// Created by Edwin Herrera on 3/20/18.
//

#ifndef TINYJULIAPP_UTILS_H
#define TINYJULIAPP_UTILS_H

#include <string>

using namespace std;

string ebp(int offset);

string newLabel();

string escapedString(const string &str);

char *charPtr(const string &str);

char toASMLiteral(const string &str);

#endif //TINYJULIAPP_UTILS_H
