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
            new FunctionCall{
                    "add",
                    vector<Expression *> {
                            new IntExpression{ 12 },
                            new IntExpression{ 10 }
                    }
            }
    });

    cout << expr->evaluate(new Scope()).code << endl;
    cout << FunctionCode::joined();

    return 0;
}