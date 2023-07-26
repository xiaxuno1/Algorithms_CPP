#pragma once
#include <stdio.h>
#include <stdlib.h>

constexpr int OK = 1;
constexpr int ERROR = 0;

typedef int ElemType;//数据的类型
typedef int Status;

typedef struct Node
{
	ElemType value;
	Node* next, * prev;
}Node;

typedef Node* DoublelyLinkList; //定义结点的指针形式

//initList(L):    初始化操作，建立一个空的线性表
 Status initList(DoublelyLinkList &L) {
	L = (DoublelyLinkList)malloc(sizeof(Node));
	if (L)
	{
		return ERROR;
	}
	L->value = 0;
	//用头结点存储长度，但是这里可能会被修改值，导致错误，因此不用
	L->next = nullptr;
	L->prev = nullptr;
}

 //isEmpty(L):   若线性表为空，返回ture,否则false
 Status isEmpty(DoublelyLinkList& L) {
	 if (L->next)
		 return true;
	 else
	 {
		 return false;
	 }
 }
