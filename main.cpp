#include <iostream>
#include "ast.h"

using namespace std;

int main() {
   auto expr = new Block(list<Expression *> {
           new Declaration{
                   "some_variable",
                   ReturnType::INTEGER,
                   new IntExpression{ 5 }
           },
           new FunctionDeclaration{
                   "add",
                   vector<FunctionDeclaration::Param> {
                           FunctionDeclaration::Param { "b", ReturnType::INTEGER }
                   },
                   ReturnType::INTEGER,
                   new Block(list<Expression *>{
                           new While{
                                   new BoolExpression{ true },
                                   new Block(list<Expression*> {
                                           new Declaration{
                                                   "while_var",
                                                   ReturnType::INTEGER,
                                                   new IntExpression{ 60 }
                                           }
                                   })
                           },
                           new Return{
                                   new AddExpression{
                                           new IdExpression{ "while_var" },
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
                                   new IntExpression{ 12 }
                           }
                   }
           },
           new Print(vector<Expression *> {
                   new IdExpression{ "result" }
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