#include <iostream>
#include "ast.h"

using namespace std;

int main() {
    auto expr = new Block(vector<Expression *> {
            new Declaration{
                    "arr",
                    ReturnType::INT_ARRAY,
                    new Array(vector<Expression *> {
                            new AddExpression{
                                    new IntExpression{ 1 },
                                    new IntExpression{ 5 }
                            },
                            new IntExpression{ 2 },
                            new IntExpression{ 3 },
                    })
            },
            new ArraySet{
                    "arr",
                    new IntExpression{ 1 },
                    new IntExpression{ 50 }
            },

            new For{
                    "x",
                    new IntExpression{ 0 },
                    new IntExpression{ 3 },
                    new Block(vector<Expression *> {
                            new Print(vector<Expression *>{
                                    new ArrayAccess{
                                            "arr",
                                            new IdExpression{ "x" }
                                    }
                            })
                    })
            }
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