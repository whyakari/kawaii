#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

class Parser {
public:
    Parser(Lexer& lexer);
    void parse();
private:
    Lexer& lexer;
    Token currentToken;

    void eat(TokenType type);
    void statement();
    void expression();
	void functionDeclaration();
};

#endif // PARSER_H

