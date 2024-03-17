#include "../include/codegen.h"
#include <iostream>

void CodeGenerator::generate(const AstNode& rootNode) {
    generateFunction(rootNode);
}

void CodeGenerator::generateFunction(const AstNode& node) {
    std::cout << "Function " << node.name << " with parameter "
              << node.parameterName << " of type " << node.parameterType
              << " and return type " << node.returnType << std::endl;
}

