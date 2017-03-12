/*
    > File Name: SumCompiler.h
    > Author: Michael
    > Email: loveandloss@hotmail.com
    > Created Time: 2017-03-11
 */

#ifndef _SUMCOMPILER_H__
#define _SUMCOMPILER_H__

#define ADD '+'

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

// 建立操作数结点
struct ExpNode *getNumNode(int i);

// 建立操作符结点
struct ExpNode *getSumNode(struct ExpNode *left, struct ExpNode *right);

// 初始化Operators, 用来存储按后续遍历生成的操作符序列
struct Operators *initOperators(struct Expression *exp);

// 按后续遍历生成的操作符序列, 存储在Operators中
void getExpression(struct ExpNode *expression, struct Operators *operas);

#endif
