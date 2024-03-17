#include "../include/lexer.h"
#include "../include/parser.h"
#include <iostream>

int main() {
    std::string input = "kudasai minhaFuncao(p: int) yamete {}";
    Lexer lexer(input);
    Parser parser(lexer);
    try {
        AstNode rootNode = parser.parseFunction();
		std::cout << "Function type: " << rootNode.type << std::endl;
        std::cout << "Parsed function name: " << rootNode.name << std::endl;
        std::cout << "Parameter name: " << rootNode.parameterName << std::endl;
        std::cout << "Parameter type: " << rootNode.parameterType << std::endl;
        std::cout << "Return type: " << rootNode.returnType << std::endl;
    } catch (const std::runtime_error& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }

    return 0;
}

