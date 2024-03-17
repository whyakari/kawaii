#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {
    TOK_KUDASAI,
    TOK_LPAREN,
    TOK_IDENTIFIER,
    TOK_COLON,
    TOK_STRING,
    TOK_INT,
	TOK_NUMBER,
    TOK_RPAREN,
    TOK_YAMETE,
    TOK_LBRACE,
    TOK_RBRACE,
    TOK_SEMICOLON,
    TOK_EOF,
	UNKNOWN_TOKEN
};

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
public:
    Lexer(const std::string& input);
    Token getNextToken();
private:
    std::string input;
    size_t position;
    char currentChar;

    void advance();
    void skipWhitespace();
    Token parseIdentifier();
    Token parseString();
	Token parseNumber();
};

#endif
