//
// Created by Edwin Herrera on 3/20/18.
//

#ifndef TINYJULIAPP_AST_H
#define TINYJULIAPP_AST_H


#define DEFINE_BINARY_EXPR(name) \
    class name##Expression: public BinaryExpression { \
    public:                                  \
        name##Expression(Expression *left, Expression *right): BinaryExpression(left, right) {} \
        ReturningContext evaluate(Scope *scope) override;        \
    };


#include <string>
#include <list>
#include <vector>
#include "ReturningContext.h"
#include "scope.h"

using namespace std;

class Expression {
public:
    virtual ReturningContext evaluate(Scope *scope) = 0;
};

struct IntExpression : public Expression {
    int value;

    explicit IntExpression(int value) : value(value) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct StringExpression : public Expression {
    string value;

    explicit StringExpression(string value) : value(move(value)) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct BoolExpression : public Expression {
    bool value;

    explicit BoolExpression(bool value) : value(value) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct IdExpression : public Expression {
    string varName;

    explicit IdExpression(string varName) : varName(move(varName)) {}

    ReturningContext evaluate(Scope *scope) override;
};

class BinaryExpression : public Expression {
public:
    Expression *left;
    Expression *right;

    BinaryExpression(Expression *left, Expression *right) : left(left), right(right) {}
};

DEFINE_BINARY_EXPR(Add);

DEFINE_BINARY_EXPR(Sub);

DEFINE_BINARY_EXPR(Mul);

DEFINE_BINARY_EXPR(Div);

DEFINE_BINARY_EXPR(And);

struct Block : public Expression {
    list<Expression *> statements;

    explicit Block(list<Expression *> statements) : statements(move(statements)) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct Declaration : public Expression {
    string varName;
    ReturnType type;
    Expression *expression;

    Declaration(string varName, ReturnType type, Expression *expression) :
            varName(move(varName)), type(type), expression(expression) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct Assignment : public Expression {
    string varName;
    Expression *expression;

    Assignment(string varName, Expression *expression) : varName(move(varName)), expression(expression) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct FunctionDeclaration : public Expression {
    struct Param {
        string name;
        ReturnType type;

        Param(string name, ReturnType type) : name(move(name)), type(type) {}
    };

    string name;
    vector<Param> params;
    ReturnType type;
    Expression *body;

    FunctionDeclaration(string name, vector<Param> params, ReturnType type, Expression *body) :
            name(move(name)), params(move(params)), type(type), body(body) {}

    ReturningContext evaluate(Scope *scope) override;

private:
    vector<ReturnType> paramTypeList();
};

struct FunctionCall : public Expression {
    string functionName;
    vector<Expression *> arguments;

    FunctionCall(string functionName, vector<Expression *> arguments) :
            functionName(move(functionName)), arguments(move(arguments)) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct Return : public Expression {
    Expression *expression;

    explicit Return(Expression *expression) : expression(expression) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct Print : public Expression {
    vector<Expression *> expressions;

    explicit Print(vector<Expression *> expressions) : expressions(move(expressions)) {}

    ReturningContext evaluate(Scope *scope) override;
};

#endif //TINYJULIAPP_AST_H
