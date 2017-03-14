#include <stdio.h>
#include <stdlib.h>
#include "SumCompiler.h"

int main(int argc, char const *argv[]) {
    struct Expression *exp = (struct Expression *)malloc(sizeof(struct Expression));
    exp->operas = (struct ExpNode *)malloc(sizeof(struct ExpNode));
    exp->count = 0;

    exp->operas = getSumNode(getSumNode(getNumNode(2, exp), getNumNode(3, exp), exp), getNumNode(4, exp), exp);
    struct Operators *operas = initOperators(exp);
    getExpression(exp->operas, operas);
    printf("The expression is:\n");
    for (int i = 0; i < operas->index; i++) {
        printf("%c ", operas->operators[i]);
    }
    printf("\n");

    SqStack *S = InitStack();
    compile(exp->operas, S);

    return 0;
}
