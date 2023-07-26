#pragma once
//单链表
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>

constexpr auto OK = 1;
constexpr auto ERROR = 0;

constexpr auto MAXSIZE = 20 /* 存储空间初始分配量 */;

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

//节点定义,起个别名
typedef struct Node
{
	ElemType data;
	Node *next;
}Node;
typedef Node *LinkList; //定义LinkList为指针

//初始化操作，建立一个空的线性表
Status initList(LinkList *L) {
	//产生头结点，并指向空
	(*L)=(LinkList)malloc(sizeof(Node)); //为Node开辟空间,*L是一个指向Node类型的指针
	if (!(*L)) //分配空间失败
		return ERROR;
	(*L)->next = NULL;//指针指向为空
	return OK;
}

//isListEmpty(L):   若线性表为空，返回ture,否则false
Status isListEmpty(LinkList &L) 
{
	//头节点指向为空，表示线性表为空
	if (L->next)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//ClearList(L):   清空线性表；释放除头结点外的空间，头结点指针指向空
Status clearList(LinkList &L) {
	LinkList temp, q;
	temp = L->next;//指向第一个节点
	while (temp)
	{

		q = temp->next; //临时存储下需要释放的节点，否则释放后无法访问下一结点
		free(temp);
		temp = q;
	}
	L->next = nullptr; //头节点必须指向为空
	return false;
}

//GetElem(L,i,*e):将L中第i个元素返回给e
Status getElem(LinkList& L, int i, ElemType &e) {
	LinkList temp;
	temp = L->next;
	for (int j = 0; j < i; j++)
	{
		temp = temp->next;
		if (!(temp)) //当i超出长度
		{
			return ERROR;
		}
	}
	e = temp->data;
	return OK;
}

//LocateElem(L,e):在L中查找与e相等元素，返回位置，没有返回0
int locateElem(LinkList& L, ElemType& e) {
	LinkList temp;
	int loc = 1;
	temp = L->next; //temp指向第一个元素
	while (temp)
	{	
		if ((temp->data) == e)
		{
			return loc;
		}
		else
		{
			temp = temp->next;
			++loc;
		}
	}
	//所有元素遍历完没有找到相同
	return false;
}

//ListInsert(*L,i,e):在L的第i个元素位置插入e
Status listInsert(LinkList& L, int i, ElemType e) {
	LinkList newNode,temp;
	temp = L; //初始化
	int j=1;
	for (j = 1; j < i && temp; j++)//允许在尾节点插入
	{
		temp = temp->next;
	}
	if (!temp || j > i) return ERROR; //第i个元素不存在
	newNode = (LinkList)malloc(sizeof(Node));  //新节点开辟空间
	newNode->data = e;
	newNode->next = temp->next; //新节点指向后继结点
	temp->next = newNode; //指向新节点
	return OK;
}

//ListDelete(*L,i,*e):在L的第i个元素位置删除，并用e返回
Status listDelete(LinkList& L, int i, ElemType& e) {
	LinkList temp,q;
	temp = L; //temp初始化
	int j = 1;
	for (j = 1; j < i && (temp->next); j++) {
		temp = temp->next;
	}
	if (!(temp->next) || j > i) return ERROR;  //i =0或者i个元素不存在
	q = temp->next; //必须保证此指针有效，否则会报错，因此上面判断（temp->next）
	temp->next = q->next;
	e = q->data;
	free(q); //释放节点
	return OK;
}

//ListLength(L)   :返回线性表L的元素个数
int listLength(LinkList& L) {
	int length = 0;
	LinkList temp;
	temp = L->next;
	while (temp)
	{
		temp = temp->next;
		++length;
	}
	return length;
}

//OList(L)  输出所有的元素
Status OList(LinkList& L){
	LinkList temp;
	temp = L->next;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	return OK;
}

//createListHead(LinkList *L, int n)头插法创建长度为n的线性表
void createListHead(LinkList& L, int n) {
	LinkList p,q;
	srand(time(0));  //产生随机数种子
	L = (LinkList)malloc(sizeof(Node));
	L->next = nullptr; //头节点
	for (int i = 0; i <= n; i++)
	{
		q = (LinkList)malloc(sizeof(Node));
		q->data = rand() % 100 + 1; //产生100内的随机数
		q->next = L->next;//新节点指向第一个元素
		L->next = q;  //头插
	}
}

//createListTail(LinkList *L, int n)头插法创建长度为n的线性表
void createListTail(LinkList& L, int n) {
	LinkList p, q;
	srand(time(0));  //产生随机数种子
	L = (LinkList)malloc(sizeof(Node));
	p = L; //p指向尾结点
	for (int i = 0; i < n; i++)
	{
		q = (LinkList)malloc(sizeof(Node));
		q->data = rand() % 100 + 1; //产生100内的随机数
		p->next = q;
		//p重新移动到尾结点
		p = q;
	}
	//尾节点指向为空格指针
	p->next = NULL;
}
