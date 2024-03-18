#include "../include/lexer.h"
#include "../include/parser.h"
#include <iostream>

void testLexer(const std::string& source) {
    Lexer lexer(source);
/*     Parser parser(lexer); */

    // try {
    //     parser.parse();
    //     std::cout << "Parse successful\n\n";
    // } catch (const std::exception& e) {
    //     std::cerr << "Parse error: " << e.what() << "\n";
    // }

    Token token;

    std::cout << "Source code: " << source << "\n";
    std::cout << "\nTokens:\n";

    do {
        token = lexer.getNextToken();
        std::cout << "Type: ";

        switch (token.type) {
			case TokenType::FUNCTION: std::cout << "FUNCTION"; break;
            case TokenType::IDENTIFIER: std::cout << "IDENTIFIER"; break;
            case TokenType::INTEGER: std::cout << "INTEGER"; break;
            case TokenType::FLOAT: std::cout << "FLOAT"; break;
            case TokenType::PLUS: std::cout << "PLUS"; break;
            case TokenType::MINUS: std::cout << "MINUS"; break;
            case TokenType::TIMES: std::cout << "TIMES"; break;
            case TokenType::DIVIDE: std::cout << "DIVIDE"; break;
            case TokenType::SEMICOLON: std::cout << "SEMICOLON"; break;
			case TokenType::COLON: std::cout << "COLON"; break;
            case TokenType::ASSIGN: std::cout << "ASSIGN"; break;
            case TokenType::LPAREN: std::cout << "LPAREN"; break;
            case TokenType::RPAREN: std::cout << "RPAREN"; break;
            case TokenType::LBRACE: std::cout << "LBRACE"; break;
            case TokenType::RBRACE: std::cout << "RBRACE"; break;
            case TokenType::COMMA: std::cout << "COMMA"; break;
            // case TokenType::FUNCTION: std::cout << "FUNCTION"; break;
            case TokenType::LET: std::cout << "LET"; break;
            case TokenType::RETURN: std::cout << "RETURN"; break;
            case TokenType::ARROW: std::cout << "ARROW"; break;
            case TokenType::EOF_TOKEN: std::cout << "EOF"; break;
            case TokenType::INVALID: std::cout << "INVALID"; break;
        }

        std::cout << ", Lexeme: " << token.lexeme << "\n";
    } while (token.type != TokenType::EOF_TOKEN);

    std::cout << "\n";
}


int main() {
    testLexer("let x = 10;");
    testLexer("fn add(a: int, b: int) -> int { return a + b; }");
    testLexer("let y = 3.14;");

    return 0;
}
