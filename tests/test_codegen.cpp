#include "../include/codegen.h"
#include "../include/parser.h"
#include <iostream>

int main() {
    // Create an example AST node representing a function
    AstNode rootNode;
    rootNode.type = "Function";
    rootNode.name = "myFunction";
    rootNode.parameterName = "param";
    rootNode.parameterType = "int";
    rootNode.returnType = "void";

    // Initialize the CodeGenerator
    CodeGenerator codegen;

    // Generate code for the function and display it
    std::cout << "Generated code:" << std::endl;
    codegen.generate(rootNode);

    return 0;
}

