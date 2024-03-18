#ifndef CODEGEN_H
#define CODEGEN_H

#include "parser.h"

class CodeGenerator {
public:
    CodeGenerator(Parser& parser);
    void generate();
private:
    Parser& parser;

    void generateStatement(const Token& token);
    void generateExpression(const Token& token);
};

#endif // CODEGEN_H

