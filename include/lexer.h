#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <cctype>

enum class TokenType {
    IDENTIFIER,
    INTEGER,
    FLOAT,
    PLUS,
    MINUS,
    TIMES,
    DIVIDE,
    SEMICOLON,
	COLON,
    ASSIGN,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    COMMA,
    FUNCTION,
    LET,
    RETURN,
    ARROW,
    EOF_TOKEN,
    INVALID
};


struct Token {
    TokenType type;
    std::string lexeme;
};

class Lexer {
public:
    Lexer(const std::string& source);
    Token getNextToken();
    char peek() const;
private:
    std::string sourceCode;
    size_t currentPosition;
    char currentChar;
    std::string input;
    int position;
    int index;

    void advance();
    Token processIdentifier();
    Token processNumber();
    void skipWhitespace();
};

#endif // LEXER_H
