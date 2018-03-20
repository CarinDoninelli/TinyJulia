//
// Created by Edwin Herrera on 3/20/18.
//

#include "scope.h"
#include "errors.h"

ReturningContext Scope::withSnapshot(function<ReturningContext()> action) {
    int snapshot = this->tempMemory;
    auto result = action();
    this->tempMemory = snapshot;
    return result;
}

int Scope::newTempSpace() {
    auto space = size();
    tempMemory += 4;
    return space;
}

int Scope::size() {
    return static_cast<int>(tempMemory + (variables.size() * 4));
}

Var *Scope::find(const string &variable) {
    if (variables.find(variable) != variables.end()) {
        return variables[variable];
    }

    if (outer == nullptr) {
        throw UndefinedVariableError(variable);
    }

    auto found = outer->find(variable);
    return new Var{
            8 - found->offset + outer->size() + (paramCount * 4),
            found->type
    };
}

Var *Scope::createNewVariable(const string &name, ReturnType type) {
    if (variables.find(name) != variables.end()) {
        throw VariableRedefinitionError(name);
    }

    auto newVariable = new Var{ size(), type };
    variables[name] = newVariable;
    return newVariable;
}
