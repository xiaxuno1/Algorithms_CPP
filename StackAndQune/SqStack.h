#pragma once
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>

constexpr auto OK = 1;
constexpr auto ERROR = 0;

constexpr auto MAXSIZE = 100 /* 存储空间初始分配量 */;

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct 
{
	ElemType data[MAXSIZE];
	int top;
}SqStack;

//init(L) : 初始化操作
Status init(SqStack &S) {
	S.top = -1;
	return true;
}

//isEmpty(L) : 若线性表为空，返回ture, 否则false
Status isEmpty(SqStack S) {
	if (S.top = -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//clearStack(L) : 清空
Status clear(SqStack &S) {
	S.top = -1;
	return OK;
}

//getTop(L) : 返回栈顶
ElemType getTop(SqStack S) {
	return S.data[S.top];
}

//pop(L, *e) : 出栈操作
ElemType pop(SqStack &S,ElemType &e) {
	e = S.data[S.top];
	--S.top;
	return e;
}

//push(L, e) : 入栈操作
Status push(SqStack &S,ElemType &e) {
	if (S.top>=MAXSIZE-1) //无法满足入栈条件,top从0开始
	{
		return ERROR;
	}
	++S.top;
	S.data[S.top] = e;
	return OK;
}

//OStack(L)  输出所有的元素
void OStack(SqStack S) {
	while (S.top != -1)
	{
		std::cout << S.data[S.top] << " ";
		--S.top;
	}
}

//length(L):返回长度
int length(SqStack S) {
	return S.top++;
}
