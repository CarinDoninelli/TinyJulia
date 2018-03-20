//
// Created by Edwin Herrera on 3/20/18.
//

#include <sstream>
#include "ast.h"
#include "checks.h"
#include "utils.h"

ReturningContext IntExpression::evaluate(Scope *scope) {
    return ReturningContext(to_string(value), ReturnType::INTEGER);
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
             << "mov " << ebp(newVariable->offset) << ", eax" << endl;

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
             << "mov " << ebp(variable->offset) << ", eax" << endl;

        return ReturningContext { ebp(variable->offset), variable->type, code.str() };
    });
}

ReturningContext FunctionDeclaration::evaluate(Scope *scope) {
    auto functionScope = new Scope(scope, static_cast<int>(params.size()));
    return functionScope->withSnapshot([this, functionScope]() {
        auto label = newLabel();

        stringstream code;
        code << label << ":  ; " << name << endl;

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
