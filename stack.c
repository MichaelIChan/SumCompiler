/*
    > File Name: stack.c
    > Author: Michael
    > Email: loveandloss@hotmail.com
    > Created Time: 2017-03-11
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void InitStack(SqStack *S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));

    if (S->base == NULL) {
        printf("Error: InitStack malloc fault\n");
        exit(0);
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

void Push(SqStack *S, SElemType e)
{
    if (S->top - S->base >= S->stacksize) {
        S->base = (SElemType *)realloc(S->base,
                (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (S->base == NULL) {
            printf("Error: Push realloc fault");
            exit(0);
        }
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
}

void Pop(SqStack *S, SElemType *e)
{
    if (S->top == S->base) {
        printf("Error: Stack is empty\n");
        exit(0);
    }
    *e = *--S->top;
}

void DestroyStack(SqStack *S)
{
    S->top = NULL;
    S->stacksize = 0;
    free(S->base);
    free(S);
}
