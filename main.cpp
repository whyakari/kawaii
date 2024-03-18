#include "include/lexer.h"
#include "include/parser.h"
#include "include/codegen.h"
#include <iostream>

int main() {
    std::string sourceCode = "let a = 10;";
    Lexer lexer(sourceCode);
    Parser parser(lexer);
    CodeGenerator codegen(parser);

    Token token = lexer.getNextToken();
    std::cout << "Current token: Type " << static_cast<int>(token.type) << ", Lexeme: " << token.lexeme << "\n";

    parser.parse();
    codegen.generate();

    return 0;
}

