/*
    > File Name: SumCompiler.h
    > Author: Michael
    > Email: loveandloss@hotmail.com
    > Created Time: 2017-03-11
 */

#ifndef _SUMCOMPILER_H__
#define _SUMCOMPILER_H__

#define ADD '+'

#include "stack.h"

enum ExpKind {
    EXP_INT, EXP_SUM
};

struct Expression {
    struct ExpNode *operas;
    int count;
};

struct ExpNode {
    enum ExpKind kind;
    char opera;
    struct ExpNode *left;
    struct ExpNode *right;
};

struct Operators {
    char *operators;
    int index;
};

void initExpression(struct Expression* exp);

// �������������
struct ExpNode *getNumNode(int i, struct Expression* exp);

// �������������
struct ExpNode *getSumNode(struct ExpNode *left, struct ExpNode *right, struct Expression* exp);

// ��ʼ��Operators, �����洢�������������ɵĲ���������
struct Operators *initOperators(struct Expression *exp);

// �������������ɵĲ���������, �洢��Operators��
void getExpression(struct ExpNode *expression, struct Operators *operas);


void compile(struct ExpNode *exp, SqStack *S);

#endif
