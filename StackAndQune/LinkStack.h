#pragma once
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>
typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

typedef struct Node {
	ElemType data;
	Node* next;
}Node,*StackNodePtr;

typedef struct LinkStack {
	int count;
	StackNodePtr top;
}Head; //�����ͷ���洢ͷָ��

//init(L) : ��ʼ������
Status init(LinkStack& S) {
	S.top = (StackNodePtr)malloc(sizeof(Node));//Ϊ��ջ����ռ�
	if (!S.top)
	{
		return 0;
	}
	S.count = 0;
	S.top->next = NULL;//ջ��ָ��ָ������Ϊ��
	return 1;
}

//isEmpty(L) : �����Ա�Ϊ�գ�����ture, ����false
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

//clearStack(L) : ���
Status clear(LinkStack& S) {
	StackNodePtr p,q;
	p = S.top;//ջ��Ԫ��
	while (p)
	{
		q = p;
		p = p->next;//ջ��Ԫ������
		free(q);//�ͷ�
	}
	S.count = 0;
	return 1;
}


//getTop(L) : ����ջ��

//pop(L, *e) : ��ջ����
Status pop(LinkStack& S,ElemType& e) {
	StackNodePtr p;
	if ((S.count) == 0)
	{
		return 0;
	}
	p = S.top;//ջ��Ԫ�أ���ջ
	e = p->data;
	S.top = S.top->next;
	free(p);//�ͷ�ջ��Ԫ��
	--S.count; //���ȼ�1
	return 1;
}


//push(L, e) : ��ջ����
Status push(LinkStack& S,ElemType& e) {
	StackNodePtr q;
	q = (StackNodePtr)malloc(sizeof(Node)); //����ռ�
	q->data=e;
	q->next = S.top;//qΪ�µ�ջ����
	S.top = q; //ջ��ָ���½��
	++S.count;
	return 1;
}

//length(L) : ���س���
int length(LinkStack& S) {
	return S.count;
}

//OStack(L)  ������е�Ԫ��
void OStack(LinkStack& S) {
	StackNodePtr p;
	p = S.top;
	while (p->next)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
}