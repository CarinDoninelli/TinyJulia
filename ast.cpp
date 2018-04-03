//
// Created by Edwin Herrera on 3/20/18.
//

#include <sstream>
#include "ast.h"
#include <iostream>
#include "checks.h"
#include "utils.h"


static string lastLoopStart;
static string lastLoopEnd;

static int arrs = 0;

ReturningContext IntExpression::evaluate(Scope *scope) {
    return ReturningContext{to_string(value), ReturnType::INTEGER};
}

ReturningContext StringExpression::evaluate(Scope *scope) {
    auto label = LiteralCode::findLabel(value);
    return ReturningContext{label, ReturnType::STRING};
}

ReturningContext BoolExpression::evaluate(Scope *scope) {
    return ReturningContext{(value ? "1" : "0"), ReturnType::BOOL};
}

ReturningContext Array::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        stringstream code;

        auto place = scope->createNewVariable(newLabel(), ReturnType::INT_ARRAY);
        vector<ReturningContext> contexts;
        for (auto expression : values) {
            auto context = expression->evaluate(scope);
            checkType(context.type, ReturnType::INTEGER);
            contexts.push_back(context);

            code << context.code;
        }

        string temp = arrs % 2 == 0 ? "edi" : "esi";
        arrs += 1;

        code << "sub esp, 200" << endl
             << "lea edx, [ebp-" << (place->offset + defaultSize(ReturnType::INT_ARRAY)) << "]" << endl
             << "mov eax, 0" << endl
             << "mov ecx, 50" << endl
             << "mov edi, edx" << endl
             << "rep stosd" << endl;

        for (int i = 0; i < contexts.size(); i++) {
            auto context = contexts[i];
            auto contextPlace = place->offset + defaultSize(ReturnType::INT_ARRAY) - (4 * i);
            code << context.code
                 << "mov eax, " << context.place << endl
                 << "mov " << ebp(contextPlace) << ", eax" << endl;
        }

        return ReturningContext{to_string(place->offset), ReturnType::INT_ARRAY, code.str()};
    });
}

ReturningContext IdExpression::evaluate(Scope *scope) {
    auto variable = scope->find(varName);
    return ReturningContext{ebp(variable->offset), variable->type};
}

ReturningContext AddExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl 
             << "mov " << ebp(place) << ", eax" << endl
             << rightContext.code
             << "mov eax, " << rightContext.place << endl
             << "add " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext SubExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << rightContext.code
             << "sub eax, " << rightContext.place << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext MulExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << "cdq" << endl
             << rightContext.code
             << "mov ecx, " << rightContext.place << endl
             << "imul ecx" << endl
             << "mov " << ebp(place) << ", eax" << endl
             << "nop" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext DivExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << "cdq" << endl
             << rightContext.code
             << "mov ecx, " << rightContext.place << endl
             << "idiv ecx" << endl
             << "mov " << ebp(place) << ", eax" << endl
             << "nop" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext AndExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::BOOL);
        checkType(rightContext.type, ReturnType::BOOL);

        auto falseLabel = newLabel();
        auto endLabel = newLabel();

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << "cmp eax, 0" << endl
             << "je " << falseLabel << endl
             << rightContext.code
             << "mov eax, " << rightContext.place << endl
             << "cmp eax, 0" << endl
             << "je " << falseLabel << endl
             << "mov eax, 1" << endl
             << "jmp " << endLabel << endl
             << falseLabel << ": " << endl
             << "mov eax, 0" << endl
             << endLabel << ":" << endl
             << "movzx eax, al" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext OrExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::BOOL);
        checkType(rightContext.type, ReturnType::BOOL);

        auto trueLabel = newLabel();
        auto falseLabel = newLabel();
        auto endLabel = newLabel();

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << "cmp eax, 0" << endl
             << "jne " << trueLabel << endl
             << rightContext.code
             << "mov eax, " << rightContext.place << endl
             << "cmp eax, 0" << endl
             << "je " << falseLabel << endl
             << trueLabel << ":" << endl
             << "mov eax, 1" << endl
             << "jmp " << endLabel << endl
             << falseLabel << ":" << endl
             << "mov eax, 0" << endl
             << endLabel << ":" << endl
             << "movzx eax, al" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext XorExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, vector<ReturnType>{ReturnType::INTEGER, ReturnType::BOOL});
        checkType(rightContext.type, vector<ReturnType>{ReturnType::INTEGER, ReturnType::BOOL});

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << rightContext.code
             << "xor eax, " << rightContext.place << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext LessThanExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << rightContext.code
             << "cmp eax, " << rightContext.place << endl
             << "setl cl" << endl
             << "and cl, 1" << endl
             << "movzx eax, cl" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext GreaterThanExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << rightContext.code
             << "cmp eax, " << rightContext.place << endl
             << "setg cl" << endl
             << "and cl, 1" << endl
             << "movzx eax, cl" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext LessThanOrEqualExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << rightContext.code
             << "cmp eax, " << rightContext.place << endl
             << "setle cl" << endl
             << "and cl, 1" << endl
             << "movzx eax, cl" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext GreaterThanOrEqualExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << rightContext.code
             << "cmp eax, " << rightContext.place << endl
             << "setge cl" << endl
             << "and cl, 1" << endl
             << "movzx eax, cl" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext EqualExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << rightContext.code
             << "cmp eax, " << rightContext.place << endl
             << "sete cl" << endl
             << "and cl, 1" << endl
             << "movzx eax, cl" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext NotEqualExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << rightContext.code
             << "cmp eax, " << rightContext.place << endl
             << "setne cl" << endl
             << "and cl, 1" << endl
             << "movzx eax, cl" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext LeftShiftExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << rightContext.code
             << "mov eax, " << leftContext.place << endl
             << "mov ecx, " << rightContext.place << endl
             << "shl eax, cl" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext RightShiftExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << rightContext.code
             << "mov eax, " << leftContext.place << endl
             << "mov ecx, " << rightContext.place << endl
             << "sar eax, cl" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext ModExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << leftContext.code
             << "mov eax, " << leftContext.place << endl
             << "cdq" << endl
             << rightContext.code
             << "mov ecx, " << rightContext.place << endl
             << "idiv ecx" << endl
             << "mov eax, edx" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext PowExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        stringstream code;
        code << rightContext.code
             << leftContext.code
             << "push " << rightContext.place << endl
             << "push " << leftContext.place << endl
             << "call pow_helper_function" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext BitwiseOrExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, vector<ReturnType>{ReturnType::INTEGER, ReturnType::BOOL});
        checkType(rightContext.type, vector<ReturnType>{ReturnType::INTEGER, ReturnType::BOOL});

        stringstream code;
        code << leftContext.code
             << rightContext.code
             << "mov eax, " << leftContext.place << endl
             << "or eax, " << rightContext.place << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext BitwiseAndExpression::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, vector<ReturnType>{ReturnType::INTEGER, ReturnType::BOOL});
        checkType(rightContext.type, vector<ReturnType>{ReturnType::INTEGER, ReturnType::BOOL});

        stringstream code;
        code << leftContext.code
             << rightContext.code
             << "mov eax, " << leftContext.place << endl
             << "and eax, " << rightContext.place << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext Block::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        stringstream code;
        for (auto statement : statements) {
            code << statement->evaluate(scope).code << endl;
        }
        return ReturningContext{code.str()};
    });
}

ReturningContext Declaration::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {

        ReturningContext context = expression != nullptr
                                   ? expression->evaluate(scope)
                                   : ReturningContext{defaultValue(type), type, ""};

        checkType(context.type, type);

        auto newVariable = scope->createNewVariable(varName, type);
        auto newVariablePlace = ebp(newVariable->offset);

        stringstream code;
        code << context.code
             << "sub esp, " << defaultSize(type) << endl;

        if (!context.place.empty()) {
            code << "mov eax, " << context.place << endl
                 << "mov " << newVariablePlace << ", eax" << "\t\t; " << varName << "::" << to_string(type) << endl;
        }

        return ReturningContext{newVariablePlace, type, code.str()};
    });
}

ReturningContext Assignment::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto context = expression->evaluate(scope);

        auto locationContext = location->evaluate(scope);
        checkType(context.type, locationContext.type);

        stringstream code;
        code << context.code
             << "mov eax, " << context.place << endl
             << locationContext.code
             << "mov " << locationContext.place << ", eax" << endl;

        return ReturningContext{locationContext.place, locationContext.type, code.str()};
    });
}

ReturningContext FunctionDeclaration::evaluate(Scope *scope) {
    auto functionScope = new Scope(scope, static_cast<int>(params.size()));
    functionScope->setIsFunctionScope(true);
    return functionScope->withSnapshot([this, functionScope]() {
        auto label = newLabel();

        stringstream code;
        code << label << ":" << "\t\t; decl " << name << endl
             << "push ebp" << endl
             << "mov ebp, esp" << endl;

        for (int i = 0; i < params.size(); i++) {
            auto newVariable = functionScope->createNewVariable(params[i].name, params[i].type);
            code << "mov eax, DWORD [ebp + " << to_string(8 + (4 * i)) << "]" << endl
                 << "sub esp, " << defaultSize(newVariable->type) << endl
                 << "mov " << ebp(newVariable->offset) << ", eax" << endl;
        }

        FunctionCode::add(FunctionMeta{name, label, this->paramTypeList(), "", type});

        code << body->evaluate(functionScope).code;
        if (type != ReturnType::UNIT) {
            auto error = new Print(
                    vector<Expression *>{new StringExpression("non-void function end reached without return.")}, true);
            code << error->evaluate(functionScope).code;
            code << "ud2" << "\t\t; End of function reached without return." << endl;
            delete error;
        }
        code << "mov eax, 0" << endl
             << "leave" << endl
             << "ret" << endl;

        FunctionCode::replaceCode(name, code.str());
        return ReturningContext{""};
    });
}

vector<ReturnType> FunctionDeclaration::paramTypeList() {
    vector<ReturnType> types;
    for (const auto &param : params) {
        types.push_back(param.type);
    }
    return types;
}

ReturningContext FunctionCall::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        vector<ReturnType> argumentTypes;
        vector<ReturningContext> contexts;
        for (auto argument : this->arguments) { // NOLINT
            auto context = argument->evaluate(scope);
            argumentTypes.push_back(context.type);
            // auto space = ebp(scope->newTempSpace());
            // context.code = context.code + "mov eax, " + context.place + "\n" + "mov " + space + ", eax\n";
            // context.place = space;
            contexts.push_back(context);
        }

        auto function = FunctionCode::find(functionName, argumentTypes);

        stringstream code;
        for (const auto &context : contexts) {
            code << context.code;
        }

        code << "sub esp, " << to_string(arguments.size() * 8) << endl;
        for (const auto &context : contexts) {
            code << "push " << context.place << endl;
        }

        code << "call " << function.label << "\t\t; call " << functionName << endl
             << "add esp, " << to_string(arguments.size() * 8) << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), function.returnType, code.str()};
    });
}

ReturningContext Return::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto context = expression->evaluate(scope);
        stringstream code;
        code << context.code
             << "mov eax, " << context.place << endl
             << "leave" << endl
             << "ret" << endl;
        return ReturningContext{code.str()};
    });
}

ReturningContext Print::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        vector<ReturningContext> contexts;
        for (auto expression : expressions) {
            contexts.push_back(expression->evaluate(scope));
        }

        stringstream code;
        for (const auto &context : contexts) {
            code << context.code;
        }

        for (const auto &context : contexts) {
            if (context.type == ReturnType::STRING) {
                code << "sub esp, 4" << endl
                     << "push " << context.place << endl
                     << "call printf" << endl
                     << "add esp, 4" << endl;
            }
            else if (context.type == ReturnType::BOOL) {
                auto falseLabel = newLabel();
                auto endLabel = newLabel();
                code << "cmp " << context.place << ", 1" << endl
                     << "jne " << falseLabel << endl
                     << "sub esp, 4" << endl
                     << "push true" << endl
                     << "jmp " << endLabel << endl
                     << falseLabel << ":" << endl
                     << "sub esp, 4" << endl
                     << "push false" << endl
                     << endLabel << ":" << endl
                     << "call printf" << endl
                     << "add esp, 4" << endl;
            } 
            else {
                code << "sub esp, 8" << endl
                     << "push " << context.place << endl
                     << "push print_fmt_int" << endl
                     << "call printf" << endl
                     << "add esp, 8" << endl;
            }
        }

        if (addNewLine) {
            code << "sub esp, 4" << endl
                 << "push new_line" << endl
                 << "call printf" << endl
                 << "add esp, 4" << endl;
        }

        return ReturningContext{code.str()};
    });
}

ReturningContext If::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto conditionContext = condition->evaluate(scope);
        checkType(conditionContext.type, ReturnType::BOOL);

        auto bodyContext = body->evaluate(scope);

        auto falseLabel = newLabel();
        auto trueLabel = newLabel();

        stringstream code;
        code << conditionContext.code
             << "mov eax, " << conditionContext.place << endl
             << "cmp eax, 0" << "\t\t; if { true: " << trueLabel << ", false: " << falseLabel << " }" << endl
             << "je " << falseLabel << endl
             << bodyContext.code
             << "jmp " << trueLabel << endl
             << falseLabel << ":" << endl;
        if (alternative != nullptr) {
            code << alternative->evaluate(scope).code;
        }
        code << trueLabel << ":" << endl;

        return ReturningContext{code.str()};
    });
}

ReturningContext While::evaluate(Scope *scope) {
    scope = new Scope(scope);
    scope->setInheritSize(true);
    return scope->withSnapshot([this, scope]() {
        auto conditionContext = condition->evaluate(scope);
        checkType(conditionContext.type, ReturnType::BOOL);

        auto whileLabel = newLabel();
        auto endWhileLabel = newLabel();

        lastLoopStart = whileLabel;
        lastLoopEnd = endWhileLabel;

        stringstream code;
        code << whileLabel << ":" << "\t\t; while { end: " << endWhileLabel << "}" << endl
             << conditionContext.code
             << "mov eax, " << conditionContext.place << endl
             << "cmp eax, 0" << endl
             << "je " << endWhileLabel << endl
             << body->evaluate(scope).code
             << "jmp " << whileLabel << endl
             << endWhileLabel << ":" << "\t\t; end of " << whileLabel;

        return ReturningContext{code.str()};
    });
}

ReturningContext For::evaluate(Scope *scope) {
    scope = new Scope(scope);
    scope->setInheritSize(true);
    return scope->withSnapshot([this, scope]() {
        auto lowerBoundContext = lowerBound->evaluate(scope);
        auto upperBoundContext = upperBound->evaluate(scope);

        checkType(lowerBoundContext.type, ReturnType::INTEGER);
        checkType(upperBoundContext.type, ReturnType::INTEGER);

        auto loopingVariable = scope->createNewVariable(varName, ReturnType::INTEGER);
        auto loopingVariablePlace = ebp(loopingVariable->offset);

        auto forLabel = newLabel();
        auto endForLabel = newLabel();

        lastLoopStart = forLabel;
        lastLoopEnd = endForLabel;

        stringstream code;
        code << lowerBoundContext.code
             << upperBoundContext.code
             << "mov eax, " << lowerBoundContext.place << endl
             << "sub esp, 4" << endl
             << "mov " << loopingVariablePlace << ", eax" << endl
             << forLabel << ":" << "\t\t; For { end: " << endForLabel << " }" << endl
             << "mov eax, " << loopingVariablePlace << endl
             << "cmp eax, " << upperBoundContext.place << endl
             << "setle cl" << endl
             << "and cl, 1" << endl
             << "jz " << endForLabel << endl
             << body->evaluate(scope).code
             << "inc " << loopingVariablePlace << endl
             << "jmp " << forLabel << endl
             << endForLabel << ":" << "\t\t; end of " << forLabel << endl
             << "add esp, 4";

        return ReturningContext{code.str()};
    });
}

ReturningContext UnaryMinus::evaluate(Scope *scope) {
    auto multiplication = new MulExpression{
            new IntExpression{-1},
            expression
    };

    auto result = multiplication->evaluate(scope);
    delete multiplication;
    return result;
}

ReturningContext Negation::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto context = expression->evaluate(scope);
        checkType(context.type, ReturnType::BOOL);

        stringstream code;
        code << context.code
             << "mov eax, " << context.place << endl
             << "cmp eax, 0" << endl
             << "setne al" << endl
             << "xor al, -1" << endl
             << "and al, 1" << endl
             << "movzx eax, al" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::BOOL, code.str()};
    });
}

ReturningContext BitNegation::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto context = expression->evaluate(scope);
        checkType(context.type, ReturnType::INTEGER);

        stringstream code;
        code << context.code
             << "mov eax, " << context.place << endl
             << "xor eax, -1" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext ArrayAccess::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto varPlace = scope->find(varName);
        checkType(varPlace->type, vector<ReturnType>{ReturnType::INT_ARRAY, ReturnType::STRING});

        auto varPlaceOffset = varPlace->offset;

        string temp = arrs % 2 == 0 ? "edi" : "esi";
        arrs += 1;

        auto indexContext = index->evaluate(scope);
        stringstream code;
        code << indexContext.code
             << "mov " << temp << ", " << indexContext.place << endl;

        return ReturningContext{
                "DWORD[ebp - " + to_string(varPlaceOffset) + " + " + temp + " * 4]",
                ReturnType::INTEGER,
                code.str()
        };
    });
}

ReturningContext ArraySet::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto varPlace = scope->find(varName);
        checkType(varPlace->type, vector<ReturnType>{ReturnType::INT_ARRAY, ReturnType::STRING});

        auto varPlaceOffset = varPlace->offset >= 0 ? varPlace->offset : (varPlace->offset * -1);

        auto indexContext = index->evaluate(scope);

        auto expressionContext = expression->evaluate(scope);
        checkType(expressionContext.type, ReturnType::INTEGER);

        stringstream code;
        code << indexContext.code
             << expressionContext.code
             << "mov eax, " << indexContext.place << endl
             << "mov ecx, " << expressionContext.place << endl
             << "mov DWORD[ebp - " << varPlaceOffset << " + eax * 4], ecx" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext BitwiseNegation::evaluate(Scope *scope) {
    auto place = scope->newTempSpace();
    return scope->withSnapshot([this, scope, place]() {
        auto context = expression->evaluate(scope);
        if (context.type == ReturnType::BOOL) {
            return Negation(expression).evaluate(scope);
        }

        stringstream code;
        code << context.code
             << "mov ecx, " << context.place << endl
             << "xor ecx, -1" << endl
             << "mov " << ebp(place) << ", ecx" << endl;

        return ReturningContext{ebp(place), ReturnType::INTEGER, code.str()};
    });
}

ReturningContext Break::evaluate(Scope *scope) {
    return ReturningContext{"jmp " + lastLoopEnd + "\n"};
}

ReturningContext Continue::evaluate(Scope *scope) {
    return ReturningContext{"jmp " + lastLoopStart + "\n"};
}

// streams


ostream &operator<<(ostream &os, const Expression &expression) {
    return os;
}

ostream &operator<<(ostream &os, const IntExpression &expression) {
    os << static_cast<const Expression &>(expression) << " value: " << expression.value;
    return os;
}

ostream &operator<<(ostream &os, const StringExpression &expression) {
    os << static_cast<const Expression &>(expression) << " value: " << expression.value;
    return os;
}

ostream &operator<<(ostream &os, const Array &array1) {
    os << static_cast<const Expression &>(array1) << " values: " << joinExpressions(array1.values);
    return os;
}
