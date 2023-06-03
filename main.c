#include <stdio.h>
#include <stdlib.h>
#include "lexer.c"
#include "Parser.c"
#include "Syntax_Checker.c"
#include "Assembly_Generator.c"

typedef struct {
    TokenType type;
    char* value;
} Token;

typedef struct {
    TokenType type;
    char* value;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

const char* filename="test.txt";
FILE* file = fopen(filename, "r");
int* num_tokens = getFileSize(file);
Token* Tokens[tokenize_file_contents(file,num_tokens)];

int main()
{
    int numTokens = sizeof(Tokens) / sizeof(Token);
    ASTNode* ast = parse(Tokens, num_tokens);
    checkErrors(ast);
    generateAssembly(ast,filename);
    freeNode(ast);

    return 0;
}
