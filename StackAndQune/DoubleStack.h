#pragma once
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>
typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct DoubleStack{
	ElemType data[MAXSIZE];
	int top1, top2; //两个栈的栈顶索引位置
}DoubleStack;

Status init(DoubleStack& S) {
	S.top1 = -1;
	S.top2 = MAXSIZE;
	return OK;
}

//isEmpty(L) : 若线性表为空，返回ture, 否则false
Status isEmpty(DoubleStack S) {
	if (S.top1 == -1 && S.top2 == MAXSIZE)
	{
		return true;
	}
	return false;
}

//clearStack(L) : 清空
Status clear(DoubleStack& S) {
	S.top1 = -1;
	S.top2 = MAXSIZE;
	return OK;
}

//getTop(L) : 返回栈顶

//pop(L, *e) : 出栈操作
Status pop(DoubleStack& S, ElemType& e, int stackNum) {
	if (S.top1 == -1 || S.top2 == MAXSIZE) //不具备出栈条件
	{
		return ERROR;
	}
	if (stackNum == 1)
	{
		e = S.data[S.top1];
		--S.top1;
	}
	if (stackNum == 2)
	{
		e = S.data[S.top2];
		++S.top2;
	}
	return 1;
}

//push(L, e) : 入栈操作
Status push(DoubleStack& S, ElemType& e, int stackNum) {
	if (S.top1 >= S.top2 || S.top2-S.top1<=1) //无法入栈情形
	{
		return ERROR;
	}
	if (stackNum == 1)//栈1插入
	{
		++S.top1;
		S.data[S.top1] = e;
	}
	if (S.top2 <= 0)
	{
		return ERROR;
	}
	if (stackNum == 2)//栈2插入
	{
		--S.top2;
		S.data[S.top2] = e;
	}
	return OK;
}


//length(L) : 返回长度
int length(DoubleStack S) {
	return S.top1 + 1 + (MAXSIZE - S.top2);
}

//OStack(L)  输出所有的元素
void OStack(DoubleStack S) {
	int i = 0;
	while (i <= S.top1)
	{
		std::cout << S.data[i++] << " ";
	}
	i = S.top2;
	while (i < MAXSIZE)  //MAXSIZE从1开始，i从0开始
	{
		std::cout << S.data[i] << " ";
		++i;
	}
}
