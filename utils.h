#ifndef TINYJULIAPP_UTILS_H
#define TINYJULIAPP_UTILS_H

#include <string>
#include <vector>
#include "ast.h"

using namespace std;

string ebp(int offset);

string newLabel();

string escapedString(const string &str);

char *charPtr(const string &str);

char toASMLiteral(const string &str);

std::string joinExpressions(const vector<Expression *> &vector);

#endif //TINYJULIAPP_UTILS_H
