#ifndef CODEGEN_H
#define CODEGEN_H

#include "parser.h"

class CodeGenerator {
public:
    void generate(const AstNode& rootNode);

private:
    void generateFunction(const AstNode& node);
};

#endif // CODEGEN_H

