#include <iostream>
#include "ast.h"

using namespace std;

int main() {
    auto expr = new Block(list<Expression *> {
            new FunctionDeclaration{
                    "add",
                    vector<FunctionDeclaration::Param> {
                            FunctionDeclaration::Param{ "a", ReturnType::INTEGER },
                            FunctionDeclaration::Param { "b", ReturnType::INTEGER }
                    },
                    ReturnType::INTEGER,
                    new Block(list<Expression *>{
                            new Return{
                                    new AddExpression{
                                            new IdExpression{ "a" },
                                            new IdExpression{ "b" }
                                    }
                            }
                    })
            },
            new Declaration{
                    "result",
                    ReturnType::INTEGER,
                    new FunctionCall{
                            "add",
                            vector<Expression *> {
                                    new IntExpression{ 12 },
                                    new IntExpression{ 10 }
                            }
                    }
            },
            new Declaration{
                    "text",
                    ReturnType::STRING,
                    new StringExpression{ "\"hello!\", 10, 0" }
            },
            new Print(vector<Expression *> {
                    new IdExpression{ "result" },
                    new IdExpression{ "text" }
            })
    });

    auto result = expr->evaluate(new Scope());

    cout << "global main" << endl
         << "extern printf" << endl
         << "section .data" << endl
         << LiteralCode::joined() << endl
         << "section .text" << endl
         << "main:" << endl
         << "push ebp" << endl
         << "mov ebp, esp" << endl
         << result.code
         << "leave" << endl
         << "ret" << endl
         << FunctionCode::joined();

    return 0;
}