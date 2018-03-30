#ifndef TINYJULIAPP_SCOPE_H
#define TINYJULIAPP_SCOPE_H

#include <functional>
#include <map>
#include <string>

#include "types.h"
#include "ReturningContext.h"

using namespace std;

struct Var {
    int offset;
    ReturnType type;
    int size;

    Var(int offset, ReturnType type) : offset(offset), type(type), size(defaultSize(type)) {}

    Var(int offset, ReturnType type, int size) : offset(offset), type(type), size(size) {}
};

class Scope {
    Scope *outer;
    int tempMemory{ 4 };
    int paramCount;
    map<string, Var *> variables;
    bool isFunctionScope{ false };

public:
    Scope(Scope *outer, int paramCount) : outer(outer), paramCount(paramCount) {}

    explicit Scope(Scope *outer) : outer(outer), paramCount(0) {}

    Scope() : outer(nullptr), paramCount(0) {}

    ReturningContext withSnapshot(function<ReturningContext()> action);

    Var *changeVarName(string newVarName, function<bool(Var*)> predicate);

    int newTempSpace();

    int size();

    Var *find(const string &variable);

    Var *createNewVariable(const string &name, ReturnType type);

    void setIsFunctionScope(bool isFunctionScope) { this->isFunctionScope = isFunctionScope; }
};

#endif //TINYJULIAPP_SCOPE_H
