//
// Created by Edwin Herrera on 3/20/18.
//

#include <sstream>
#include "ast.h"
#include "checks.h"
#include "utils.h"

ReturningContext IntExpression::evaluate(Scope *scope) {
    return ReturningContext { to_string(value), ReturnType::INTEGER };
}

ReturningContext StringExpression::evaluate(Scope *scope) {
    auto label = LiteralCode::findLabel(value);
    return ReturningContext { label, ReturnType::STRING };
}

ReturningContext BoolExpression::evaluate(Scope *scope) {
    return ReturningContext { (value ? "1" : "0"), ReturnType::BOOL };
}

ReturningContext IdExpression::evaluate(Scope *scope) {
    auto variable = scope->find(varName);
    return ReturningContext{ ebp(variable->offset), variable->type };
}

ReturningContext AddExpression::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        auto place = scope->newTempSpace();
        stringstream code;
        code << leftContext.code
             << rightContext.code
             << "mov eax, " << leftContext.place << endl
             << "add eax, " << rightContext.place << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ ebp(place), ReturnType::INTEGER, code.str() };
    });
}

ReturningContext SubExpression::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        auto place = scope->newTempSpace();
        stringstream code;
        code << leftContext.code
             << rightContext.code
             << "mov eax, " << leftContext.place << endl
             << "sub eax, " << rightContext.place << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext{ ebp(place), ReturnType::INTEGER, code.str() };
    });
}

ReturningContext MulExpression::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        auto place = scope->newTempSpace();
        stringstream code;
        code << leftContext.code
             << rightContext.code
             << "mov eax, " << leftContext.place << endl
             << "cdq" << endl
             << "mov ecx, " << rightContext.place << endl
             << "imul ecx" << endl
             << "mov " << ebp(place) << ", eax" << endl
             << "nop" << endl;

        return ReturningContext{ ebp(place), ReturnType::INTEGER, code.str() };
    });
}

ReturningContext DivExpression::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::INTEGER);
        checkType(rightContext.type, ReturnType::INTEGER);

        auto place = scope->newTempSpace();
        stringstream code;
        code << leftContext.code
             << rightContext.code
             << "mov eax, " << leftContext.place << endl
             << "cdq" << endl
             << "mov ecx, " << rightContext.place << endl
             << "idiv ecx" << endl
             << "mov " << ebp(place) << ", eax" << endl
             << "nop" << endl;

        return ReturningContext{ ebp(place), ReturnType::INTEGER, code.str() };
    });
}

ReturningContext AndExpression::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto leftContext = left->evaluate(scope);
        auto rightContext = right->evaluate(scope);

        checkType(leftContext.type, ReturnType::BOOL);
        checkType(rightContext.type, ReturnType::BOOL);

        auto falseLabel = newLabel();
        auto trueLabel = newLabel();

        auto place = scope->newTempSpace();
        stringstream code;
        code << leftContext.code
             << rightContext.code
             << "cmp " << leftContext.place << ", 0" << endl
             << "je " << falseLabel << endl
             << "cmp " << rightContext.place << ", 0" << endl
             << "je " << falseLabel << endl
             << "mov eax, 1" << endl
             << "jmp " << trueLabel << endl
             << falseLabel << ": " << endl
             << "mov eax, 0" << endl
             << "movzx eax, al" << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext { ebp(place), ReturnType::BOOL, code.str() };
    });
}

ReturningContext Block::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        stringstream code;
        for (auto statement : statements) {
            code << statement->evaluate(scope).code << endl;
        }
        return ReturningContext { code.str() };
    });
}

ReturningContext Declaration::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto context = expression->evaluate(scope);
        checkType(context.type, type);

        auto newVariable = scope->createNewVariable(varName, type);
        stringstream code;
        code << context.code
             << "sub esp, 4" << endl
             << "mov eax, " << context.place << endl
             << "mov " << ebp(newVariable->offset) << ", eax\t; " << varName << "::" << to_string(type) << endl;

        return ReturningContext { ebp(newVariable->offset), type, code.str() };
    });
}

ReturningContext Assignment::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto context = expression->evaluate(scope);

        auto variable = scope->find(varName);
        checkType(context.type, variable->type);

        stringstream code;
        code << context.code
             << "mov eax, " << context.place << endl
             << "mov " << ebp(variable->offset) << ", eax\t; " << varName << endl;

        return ReturningContext { ebp(variable->offset), variable->type, code.str() };
    });
}

ReturningContext FunctionDeclaration::evaluate(Scope *scope) {
    auto functionScope = new Scope(scope, static_cast<int>(params.size()));
    return functionScope->withSnapshot([this, functionScope]() {
        auto label = newLabel();

        stringstream code;
        code << label << ":\t; " << name << endl
             << "push ebp" << endl
             << "mov ebp, esp" << endl;

        for (int i = 0; i < params.size(); i++) {
            auto newVariable = functionScope->createNewVariable(params[i].name, params[i].type);
            code << "mov eax, DWORD [ebp + " << to_string(8 + (4 * i)) << "]" << endl
                 << "mov " << ebp(newVariable->offset) << ", eax" << endl;
        }

        code << body->evaluate(functionScope).code
             << "leave" << endl
             << "ret" << endl;

        FunctionCode::add(FunctionMeta{ name, label, this->paramTypeList(), code.str(), type });
        return ReturningContext { "" };
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
    return scope->withSnapshot([this, scope]() {
        vector<ReturnType> argumentTypes;
        vector<ReturningContext> contexts;
        for (auto argument : this->arguments) { // NOLINT
            auto context = argument->evaluate(scope);
            argumentTypes.push_back(context.type);
            contexts.push_back(context);
        }

        auto function = FunctionCode::find(functionName, argumentTypes);

        stringstream code;
        for (const auto &context : contexts) {
            code << context.code;
        }

        for (const auto &context : contexts) {
            code << "push " << context.place << endl;
        }

        auto place = scope->newTempSpace();
        code << "call " << function.label << " ; " << functionName << endl
             << "add esp, " << to_string(arguments.size() * 8) << endl
             << "mov " << ebp(place) << ", eax" << endl;

        return ReturningContext { ebp(place), function.returnType, code.str() };
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
        return ReturningContext { code.str() };
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
            } else {
                code << "sub esp, 8" << endl
                     << "push " << context.place << endl
                     << "push print_fmt_int" << endl
                     << "call printf" << endl
                     << "add esp, 8" << endl;
            }
        }

        return ReturningContext { code.str() };
    });
}

ReturningContext If::evaluate(Scope *scope) {
    return scope->withSnapshot([this, scope]() {
        auto conditionContext = condition->evaluate(scope);
        checkType(conditionContext.type, ReturnType::BOOL);

        auto bodyContext = body->evaluate(scope);

        auto elseLabel = newLabel();
        auto ifLabel = newLabel();

        stringstream code;
        code << conditionContext.code
             << "cmp " << conditionContext.place << ", 0" << endl
             << "je " << elseLabel << endl
             << bodyContext.code
             << "jmp " << ifLabel << endl
             << elseLabel << ":" << endl;
        if (alternative != nullptr) {
            code << alternative->evaluate(scope).code;
        }
        code << ifLabel << ":" << endl;

        return ReturningContext { code.str() };
    });
}
