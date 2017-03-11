/*
    > File Name: stack.h
    > Author: Michael
    > Email: loveandloss@hotmail.com
    > Created Time: 2017-03-11
 */

#ifndef _STACK_H__
#define _STACK_H__

#include <stdbool.h>

typedef char SElemType;
#define STACK_INIT_SIZE 100     // 存储空间初始分配量
#define STACKINCREMENT  10      // 存储空间分配增量

typedef struct {
    SElemType *base;    // 在栈构造之前和销毁之后，base的值为NULL
    SElemType *top;     // 栈顶指针
    int stacksize;      // 当前已分配的存储空间，以元素为单位
}SqStack;

void InitStack(SqStack *S);

void Push(SqStack *s, SElemType e);

void Pop(SqStack *S, SElemType *e);

void DestroyStack(SqStack *S);

#endif
