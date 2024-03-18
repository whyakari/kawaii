#include "codegen.h"
#include <iostream>

CodeGenerator::CodeGenerator(Parser& parser) : parser(parser) {}

void CodeGenerator::generate() {
    parser.parse();
}

void CodeGenerator::generateStatement(const Token& token) {
    if (token.type == TokenType::LET) {
        std::cout << "Generating code for LET statement\n";
    } else if (token.type == TokenType::RETURN) {
        std::cout << "Generating code for RETURN statement\n";
    } else {
        std::cerr << "Error: Invalid statement\n";
        exit(1);
    }
}

void CodeGenerator::generateExpression(const Token& token) {
    if (token.type == TokenType::INTEGER) {
        std::cout << "Push " << token.lexeme << " onto the stack (int)\n";
    } else if (token.type == TokenType::FLOAT) {
        std::cout << "Push " << token.lexeme << " onto the stack (float)\n";
    } else if (token.type == TokenType::IDENTIFIER) {
        std::cout << "Push value of variable " << token.lexeme << " onto the stack\n";
    } else if (token.type == TokenType::PLUS) {
        std::cout << "Add two values on the stack\n";
    } else if (token.type == TokenType::MINUS) {
        std::cout << "Subtract two values on the stack\n";
    } else if (token.type == TokenType::TIMES) {
        std::cout << "Multiply two values on the stack\n";
    } else if (token.type == TokenType::DIVIDE) {
        std::cout << "Divide two values on the stack\n";
    } else if (token.type == TokenType::ARROW) {
        std::cout << "Function return type: " << token.lexeme << "\n";
    } else {
        std::cerr << "Error: Invalid expression\n";
        exit(1);
    }
}

