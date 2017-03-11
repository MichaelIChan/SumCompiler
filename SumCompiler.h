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

struct ExpNode {
    enum ExpKind kind;
    char operater;
    struct ExpNode *left;
    struct ExpNode *right;
};

#endif
