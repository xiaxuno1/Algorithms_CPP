#pragma once
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>
typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node {
	ElemType data;
	Node* next;
}Node,*StackNodePtr;

typedef struct LinkStack {
	int count;
	StackNodePtr top;
}Head; //定义的头结点存储头指针

//init(L) : 初始化操作
Status init(LinkStack& S) {
	S.top = (StackNodePtr)malloc(sizeof(Node));//为入栈分配空间
	if (!S.top)
	{
		return 0;
	}
	S.count = 0;
	S.top->next = NULL;//栈顶指针指向内容为空
	return 1;
}

//isEmpty(L) : 若线性表为空，返回ture, 否则false
Status isEmpty(LinkStack & S) {
	if ((S.count)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//clearStack(L) : 清空
Status clear(LinkStack& S) {
	StackNodePtr p,q;
	p = S.top;//栈顶元素
	while (p)
	{
		q = p;
		p = p->next;//栈顶元素下移
		free(q);//释放
	}
	S.count = 0;
	return 1;
}


//getTop(L) : 返回栈顶

//pop(L, *e) : 出栈操作
Status pop(LinkStack& S,ElemType& e) {
	StackNodePtr p;
	if ((S.count) == 0)
	{
		return 0;
	}
	p = S.top;//栈顶元素，出栈
	e = p->data;
	S.top = S.top->next;
	free(p);//释放栈顶元素
	--S.count; //长度减1
	return 1;
}


//push(L, e) : 入栈操作
Status push(LinkStack& S,ElemType& e) {
	StackNodePtr q;
	q = (StackNodePtr)malloc(sizeof(Node)); //分配空间
	q->data=e;
	q->next = S.top;//q为新的栈顶，
	S.top = q; //栈顶指向新结点
	++S.count;
	return 1;
}

//length(L) : 返回长度
int length(LinkStack& S) {
	return S.count;
}

//OStack(L)  输出所有的元素
void OStack(LinkStack& S) {
	StackNodePtr p;
	p = S.top;
	while (p->next)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
}