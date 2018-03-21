//
// Created by Edwin Herrera on 3/20/18.
//

#ifndef TINYJULIAPP_ERRORS_H
#define TINYJULIAPP_ERRORS_H

#include <string>
#include <utility>

using namespace std;

struct TypeError : public exception {
    string message;

    TypeError(string expected, string actual) {
        message = "Invalid Type. Expected " + move(expected) + ", found " + move(actual);
    }

    const char *what() const throw() override {
        return message.c_str();
    }
};

struct UndefinedVariableError : public exception {
    string message;

    explicit UndefinedVariableError(string variable) {
        message = "Undefined variable " + move(variable);
    }

    const char *what() const throw() override {
        return message.c_str();
    }
};

struct VariableRedefinitionError : public exception {
    string message;

    explicit VariableRedefinitionError(string variable) {
        message = "Variable " + move(variable) + " already declared.";
    }

    const char *what() const throw() override {
        return message.c_str();
    }
};

struct FunctionRedeclarationError : public exception {
    string message;

    explicit FunctionRedeclarationError(string functionName) {
        message = "Function " + move(functionName) + " already declared.";
    }

    const char *what() const throw() override {
        return message.c_str();
    }
};

struct UndefinedFunctionError : public exception {
    string message;

    explicit UndefinedFunctionError(string function) {
        message = "Undefined function " + move(function);
    }

    const char *what() const throw() override {
        return message.c_str();
    }
};

struct InvalidRangeError : public exception {
};

#endif //TINYJULIAPP_ERRORS_H
