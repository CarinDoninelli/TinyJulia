#ifndef TINYJULIAPP_AST_H
#define TINYJULIAPP_AST_H


#define DEFINE_BINARY_EXPR(name) \
    class name##Expression: public BinaryExpression { \
    public:                                  \
        name##Expression(Expression *left, Expression *right): BinaryExpression(left, right) {} \
        ReturningContext evaluate(Scope *scope) override;        \
    };


#include <string>
#include <vector>
#include <ostream>
#include "ReturningContext.h"
#include "scope.h"

using namespace std;

string toASMLiteral(const std::string &);

class Expression {
public:
    virtual ReturningContext evaluate(Scope *scope) = 0;

    friend ostream &operator<<(ostream &os, const Expression &expression);
};

struct IntExpression : public Expression {
    int value;

    explicit IntExpression(int value) : value(value) {}

    ReturningContext evaluate(Scope *scope) override;

    friend ostream &operator<<(ostream &os, const IntExpression &expression);

};

struct StringExpression : public Expression {
    string value;

    explicit StringExpression(string value) : value(toASMLiteral(move(value))) {}

    ReturningContext evaluate(Scope *scope) override;

    friend ostream &operator<<(ostream &os, const StringExpression &expression);
};

struct Array : public Expression {
    vector<Expression *> values;

    explicit Array( vector<Expression *> values) : values(move(values)) {}

    ReturningContext evaluate(Scope *scope) override;

    friend ostream &operator<<(ostream &os, const Array &array1);
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

DEFINE_BINARY_EXPR(Or);

DEFINE_BINARY_EXPR(Xor);

DEFINE_BINARY_EXPR(LessThan);

DEFINE_BINARY_EXPR(GreaterThan);

DEFINE_BINARY_EXPR(LessThanOrEqual);

DEFINE_BINARY_EXPR(GreaterThanOrEqual);

DEFINE_BINARY_EXPR(Equal);

DEFINE_BINARY_EXPR(NotEqual);

DEFINE_BINARY_EXPR(Pow);

DEFINE_BINARY_EXPR(LeftShift);

DEFINE_BINARY_EXPR(RightShift);

DEFINE_BINARY_EXPR(Mod);

DEFINE_BINARY_EXPR(BitwiseOr);

DEFINE_BINARY_EXPR(BitwiseAnd);

struct Block : public Expression {
    vector<Expression *> statements;

    explicit Block(vector<Expression *> statements) : statements(move(statements)) {}

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
    Expression *location;
    Expression *expression;

    Assignment(Expression *location, Expression *expression) : location(location), expression(expression) {}

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
            functionName(move(functionName)), arguments(move(arguments)) {
        
        reverse(this->arguments.begin(), this->arguments.end());
    }

    ReturningContext evaluate(Scope *scope) override;
};

struct Return : public Expression {
    Expression *expression;

    explicit Return(Expression *expression) : expression(expression) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct Print : public Expression {
    vector<Expression *> expressions;
    bool addNewLine;

    Print(vector<Expression *> expressions, bool addNewLine) : expressions(move(expressions)), addNewLine(addNewLine) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct If : public Expression {
    Expression *condition;
    Expression *body;
    Expression *alternative;

    If(Expression *condition, Expression *body, Expression *alternative) :
            condition(condition), body(body), alternative(alternative) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct While : public Expression {
    Expression *condition;
    Expression *body;

    While(Expression *condition, Expression *body) : condition(condition), body(body) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct For : public Expression {
    string varName;
    Expression *lowerBound;
    Expression *upperBound;
    Expression *body;

    For(string varName, Expression *lowerBound, Expression *upperBound, Expression *body) :
            varName(move(varName)), lowerBound(lowerBound), upperBound(upperBound), body(body) {}
    
    ReturningContext evaluate(Scope *scope) override;
};

struct UnaryMinus : public Expression {
    Expression *expression;

    explicit UnaryMinus(Expression *expression) : expression(expression) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct Negation : public Expression {
    Expression *expression;

    explicit Negation(Expression *expression) : expression(expression) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct BitNegation : public Expression {
    Expression *expression;

    explicit BitNegation(Expression *expression) : expression(expression) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct ArrayAccess : public Expression {
    string varName;
    Expression *index;

    ArrayAccess(string varName, Expression *index) : varName(move(varName)), index(index) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct ArraySet : public Expression {
    string varName;
    Expression *index;
    Expression *expression;

    ArraySet(string varName, Expression *index, Expression *expression) : 
            varName(move(varName)), index(index), expression(expression) {}

    ReturningContext evaluate(Scope *scope) override;
};

struct BitwiseNegation : public Expression {
    Expression *expression;

    explicit BitwiseNegation(Expression *expression) : expression(expression) {}

    ReturningContext evaluate(Scope *scope) override;
};

#endif //TINYJULIAPP_AST_H
