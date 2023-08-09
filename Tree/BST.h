#pragma once
//����������
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct BSTNode {
	Elemtype data;
	struct BSTNode* rchild, * lchild;
}BSTNode,*BSTree;

//���ң�ѭ��
BSTNode* BSTSearch(BSTree T, Elemtype key) {
	while (T->data == key || T != NULL)
	{
		if (T->data > key)
		{
			T = T->lchild;
		}
		if (T->data < key)
		{
			T = T->rchild;
		}
	}
	return T;  //����ƥ���㣬����NULL
}

//���ң��ݹ�
BSTNode* BSTSearchRecur(BSTree T, Elemtype key) {
	if (T==NULL) //�ݹ��������
		return NULL;
	if (T->data == key)
		return T;
	else if (T->data > key) //�ȸ�С�����
		return BSTSearchRecur(T->lchild, key);
	else
		return BSTSearchRecur(T->rchild, key);
}

//����
bool BSTInsert(BSTree &T, Elemtype key) {
	if (T==NULL) //�ݹ��������
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = key;
		T->lchild = T->rchild = NULL;
		return true;
	}
	else if(key == T->data){  //
		return false;
	}
	else if(key<T->data)
	{
		BSTInsert(T->lchild, key);  //���͸��Ӷ�
	}
	else
	{
		BSTInsert(T->rchild, key);
	}
}

//�����������Ĺ���
void createBST(BSTree& T, Elemtype str[], int n) {
	T == NULL; //��ʼΪ��
	int i = 0;
	while (i<n)
	{
		BSTInsert(T, str[i]);
		i++;
	}
}
