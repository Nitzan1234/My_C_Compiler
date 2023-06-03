#include <stdio.h>
#include <stdlib.h>

typedef struct {
    TokenType type;
    char* value;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

enum AssemblyInstruction {
    ADD,
    SUB,
    MOV,
    CMP,
    JMP,
    JZ,
    JNZ,
    CALL,
    RET,
    PUSH,
    POP,
    LOAD,
    STORE,
    IN,
    OUT
};

void generateAssembly(ASTNode* node, const char* filename) {
    const char* filename= "test.txt";
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        return;
    }

    // Generate assembly code based on the AST node type
    switch (node->instruction) {
        case ADD:
            // Generate assembly code for addition
            fprintf(fp, "add eax, %s\n", node->operand);
            break;
        case SUB:
            // Generate assembly code for subtraction
            fprintf(fp, "sub eax, %s\n", node->operand);
            break;
        case MOV:
            // Generate assembly code for move
            fprintf(fp, "mov eax, %s\n", node->operand);
            break;
        case CMP:
            // Generate assembly code for comparison
            fprintf(fp, "cmp eax, %s\n", node->operand);
            break;
        case JMP:
            // Generate assembly code for unconditional jump
            fprintf(fp, "jmp %s\n", node->operand);
            break;
        case JZ:
            // Generate assembly code for conditional jump (zero)
            fprintf(fp, "jz %s\n", node->operand);
            break;
        case JNZ:
            // Generate assembly code for conditional jump (not zero)
            fprintf(fp, "jnz %s\n", node->operand);
            break;
        case CALL:
            // Generate assembly code for function call
            fprintf(fp, "call %s\n", node->operand);
            break;
        case RET:
            // Generate assembly code for return
            fprintf(fp, "ret\n");
            break;
        case PUSH:
            // Generate assembly code for push
            fprintf(fp, "push %s\n", node->operand);
            break;
        case POP:
            // Generate assembly code for pop
            fprintf(fp, "pop %s\n", node->operand);
            break;
        case LOAD:
            // Generate assembly code for load
            fprintf(fp, "mov eax, [%s]\n", node->operand);
            break;
        case STORE:
            // Generate assembly code for store
            fprintf(fp, "mov [%s], eax\n", node->operand);
            break;
        case IN:
            // Generate assembly code for input
            fprintf(fp, "in eax, %s\n", node->operand);
            break;
        case OUT:
            // Generate assembly code for output
            fprintf(fp, "out %s, eax\n", node->operand);
            break;
        default:
            // Handle unsupported instruction or errors
            printf("Error: Unsupported assembly instruction\n");
            fclose(fp);
            return;
    }

    // Recursively generate assembly code for child nodes
    generateAssembly(node->left, filename);
    generateAssembly(node->right, filename);

    fclose(fp);
}

