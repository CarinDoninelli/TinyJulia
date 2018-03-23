#include <iostream>
#include <vector>
#include "ast.h"

using namespace std;

int main() {
    auto expr = new Block(vector<Expression *> {
            new FunctionDeclaration{
                    "f",
                    vector<FunctionDeclaration::Param>{
                            FunctionDeclaration::Param{ "a", ReturnType::INTEGER },
                            FunctionDeclaration::Param{ "b", ReturnType::INTEGER }
                    },
                    ReturnType::INTEGER,
                    new Block(vector<Expression *>{
                            new Return{
                                    new AddExpression{
                                            new IdExpression{ "a" },
                                            new IdExpression{ "b" }
                                    }
                            }
                    })
            },

            new Print(vector<Expression*>{
                    new FunctionCall{
                            "f",
                            vector<Expression*>{
                                new AddExpression{
                                        new IntExpression{ 1 },
                                        new IntExpression{ 3 }
                                },
                                new AddExpression{
                                        new IntExpression{ 5 },
                                        new IntExpression{ 5 }
                                }
                            }
                    }
            })

    });

//     auto expr = new Block(list<Expression *> {
//             new Declaration{ "condition", ReturnType::BOOL, new BoolExpression{ false }},
//             new If{
//                     new IdExpression{ "condition" },
//                     new Block(list<Expression *> {
//                             new Print(vector<Expression *> {
//                                     new StringExpression{ "\"Is True!\", 10, 0" }
//                             })
//                     }),
//                     new Block(list<Expression *> {
//                             new Print(vector<Expression *> {
//                                     new StringExpression{ "\"is false!\", 10, 0" }
//                             })
//                     })
//             }
//     });

    auto result = expr->evaluate(new Scope());

    cout << "global main" << endl
         << FunctionCode::externFunctionCode() << endl
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