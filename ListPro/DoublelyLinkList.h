#pragma once
#include <stdio.h>
#include <stdlib.h>

constexpr int OK = 1;
constexpr int ERROR = 0;

typedef int ElemType;//���ݵ�����
typedef int Status;

typedef struct Node
{
	ElemType value;
	Node* next, * prev;
}Node;

typedef Node* DoublelyLinkList; //�������ָ����ʽ

//initList(L):    ��ʼ������������һ���յ����Ա�
 Status initList(DoublelyLinkList &L) {
	L = (DoublelyLinkList)malloc(sizeof(Node));
	if (L)
	{
		return ERROR;
	}
	L->value = 0;
	//��ͷ���洢���ȣ�����������ܻᱻ�޸�ֵ�����´�����˲���
	L->next = nullptr;
	L->prev = nullptr;
}

 //isEmpty(L):   �����Ա�Ϊ�գ�����ture,����false
 Status isEmpty(DoublelyLinkList& L) {
	 if (L->next)
		 return true;
	 else
	 {
		 return false;
	 }
 }
