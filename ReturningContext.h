#ifndef TINYJULIAPP_RETURNINGCONTEXT_H
#define TINYJULIAPP_RETURNINGCONTEXT_H

#include <string>
#include <utility>
#include <vector>
#include <map>
#include "types.h"

using namespace std;

struct ReturningContext {
    string place;
    string code;
    ReturnType type;

    ReturningContext(string place, ReturnType type) : place(move(place)), type(type), code("") {}

    ReturningContext(string place, ReturnType type, string code) : place(move(place)), type(type), code(move(code)) {}

    explicit ReturningContext(string code) : code(move(code)), place(""), type(ReturnType::UNIT) {}
};

struct FunctionMeta {
    string name;
    string label;
    vector<ReturnType> paramTypes;
    string code;
    ReturnType returnType;

    FunctionMeta(string name, string label, vector<ReturnType> paramTypes, string code, ReturnType returnType) :
            name(move(name)),
            label(move(label)),
            paramTypes(move(paramTypes)),
            code(move(code)),
            returnType(returnType) {}
};

class FunctionCode {
    static vector<FunctionMeta> codeBlocks;
    static vector<string> externFunctions;
public:
    static void add(FunctionMeta meta);

    static void replaceCode(const std::string &functionName, std::string code);

    static string joined();

    static FunctionMeta find(const string &name, const vector<ReturnType> &argumentTypes);

    static string externFunctionCode();
};

class LiteralCode {
    static map<string, string> *literals;

public:
    static void add(string literal, string label);

    static string findLabel(const string &literal);

    static string joined();
};

#endif //TINYJULIAPP_RETURNINGCONTEXT_H
