#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <string>

struct AstNode {
    std::string type;
    std::string name;
    std::string parameterName;
    std::string parameterType;
    std::string returnType;
};

class Parser {
public:
    Parser(Lexer& lexer);
    AstNode parseFunction();
private:
    Lexer& lexer;
    Token currentToken;

    void eat(TokenType type);
};

#endif

