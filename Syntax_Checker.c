#include <stdio.h>
#include <stdlib.h>

typedef struct {
    TokenType type;
    char* value;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

void checkErrors(ASTNode* node) {
    if (node == NULL) {
        return;
    }

  if (node->type == AST_DIVISION && node->right->type == AST_NUMBER && atoi(node->right->value) == 0) {
        printf("Error: Division by zero\n");
    }
    if (node->type == AST_VARIABLE && node->left == NULL) {
        printf("Error: Missing assignment for variable '%s'\n", node->value);
    }
    if (node->type == AST_FUNCTION_CALL && node->left == NULL) {
        printf("Error: Missing function name in function call\n");
    }
    if (node->type == AST_CONDITIONAL && node->right == NULL) {
        printf("Error: Missing 'if' condition in conditional statement\n");
    }
    if (node->type == AST_LOOP && node->right == NULL) {
        printf("Error: Missing loop condition in loop statement\n");
    }
    if (node->type == AST_RETURN && node->left == NULL) {
        printf("Error: Missing return value in return statement\n");
    }
    if (node->type == AST_ARRAY_INDEX && node->left == NULL) {
        printf("Error: Missing array identifier in array index\n");
    }
    if (node->type == AST_ARRAY_INDEX && node->right == NULL) {
        printf("Error: Missing index value in array index\n");
    }
    if (node->type == AST_INVALID) {
        printf("Error: Encountered invalid node\n");
    }
    if (node->type == AST_UNKNOWN) {
        printf("Error: Encountered unknown node\n");
    }S

    // Recursively check child nodes
    checkErrors(node->left);
    checkErrors(node->right);
}
