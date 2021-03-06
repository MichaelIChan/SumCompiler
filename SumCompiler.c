#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "SumCompiler.h"

void initExpression(struct Expression* exp) {
    exp = (struct Expression*)malloc(sizeof(struct Expression));
    exp->operas = (struct ExpNode *)malloc(sizeof(struct ExpNode));
    exp->count = 0;
}

struct ExpNode *getNumNode(int i, struct Expression* exp) {
    struct ExpNode *p = (struct ExpNode *)malloc(sizeof(struct ExpNode));
    p->kind = EXP_INT;
    p->opera = i + 48;
    exp->count++;
    return p;
}

struct ExpNode *getSumNode(struct ExpNode *left, struct ExpNode *right, struct Expression* exp) {
    struct ExpNode *p = (struct ExpNode *)malloc(sizeof(struct ExpNode));
    p->kind = EXP_SUM;
    p->left = left;
    p->right = right;
    p->opera = ADD;
    exp->count++;
    return p;
}

struct Operators *initOperators(struct Expression *exp) {
    if (exp->count == 0) {
        printf("Error!There is no expression.\n");
        return NULL;
    } else {
        struct Operators *operas = (struct Operators *)malloc(sizeof(struct Operators));
        operas->operators = (char *)malloc(sizeof(char) * exp->count);
        operas->index = 0;
        return operas;
    }
}

void getExpression(struct ExpNode *expression, struct Operators *operas) {
    if (expression->kind == EXP_INT) {
        operas->operators[operas->index] = expression->opera;
        operas->index++;
    } else if (expression->kind == EXP_SUM) {
        getExpression(expression->left, operas);
        operas->operators[operas->index] = expression->opera;
        operas->index++;
        getExpression(expression->right, operas);
    } else {
        printf("Error! 'opera' is wrong\n");
    }
}

void Add(SqStack *S) {
    SElemType *numA = (SElemType *)malloc(sizeof(SElemType));
    SElemType *numB = (SElemType *)malloc(sizeof(SElemType));
    Pop(S, numA); Pop(S, numB);
    printf("Add\n");
    Push(S, *numA + *numB);
}

void compile(struct ExpNode *exp, SqStack *S) {
    switch (exp->kind) {
        case EXP_INT: {
            struct ExpNode *p = exp;
            Push(S, p->opera);
            printf("Push %c\n", p->opera);
            break;
        }
        case EXP_SUM: {
            struct ExpNode *p = exp;
            compile(p->left, S);
            compile(p->right, S);
            Add(S);
            break;
        }
        default:
            break;
    }
}
