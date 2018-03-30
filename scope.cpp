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
    int size = tempMemory;
    for (const auto &var : variables) {
        size += var.second->size;
    }
    return size;
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
            isFunctionScope 
                    ? (-1) * (4 + (paramCount * 4) + outer->size() - found->offset) 
                    : size() - 4 + found->offset,
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

Var *Scope::changeVarName(string newVarName, function<bool(Var *)> predicate) {
    if (variables.find(newVarName) != variables.end()) {
        throw VariableRedefinitionError(newVarName);
    }

    for (const auto &var : variables) {
        if (predicate(var.second)) {
            variables[newVarName] = var.second;
            variables.erase(var.first);
            return var.second;
        }
    }

    throw invalid_argument("No matching variable found.");
}
