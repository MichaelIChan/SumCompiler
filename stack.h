/*
    > File Name: stack.h
    > Author: Michael
    > Email: loveandloss@hotmail.com
    > Created Time: 2017-03-11
 */

#ifndef _STACK_H__
#define _STACK_H__

#include <stdbool.h>
#include "SumCompiler.h"

typedef char SElemType;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

void InitStack(SqStack *S);

void Push(SqStack *s, SElemType e);

void Pop(SqStack *S, SElemType *e);

void DestroyStack(SqStack *S);

#endif
