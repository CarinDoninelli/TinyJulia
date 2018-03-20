//
// Created by Edwin Herrera on 3/20/18.
//

#include "ReturningContext.h"
#include "errors.h"
#include <sstream>

vector<FunctionMeta> FunctionCode::codeBlocks;

void FunctionCode::add(FunctionMeta meta) {
    for (const auto &block : codeBlocks) {
        if (block.name == meta.name && block.paramTypes == meta.paramTypes) {
            throw FunctionRedeclarationError(meta.name);
        }
    }

    codeBlocks.push_back(move(meta));
}

string FunctionCode::joined() {
    stringstream ss;
    for (const auto &block : codeBlocks) {
        ss << block.code << endl;
    }
    return ss.str();
}

FunctionMeta FunctionCode::find(const string &name, const vector<ReturnType> &argumentTypes) {
    for (const auto &block : codeBlocks) {
        if (block.name == name && block.paramTypes == argumentTypes) {
            return block;
        }
    }

    throw UndefinedFunctionError(name);
}
