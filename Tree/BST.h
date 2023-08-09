#pragma once
//二叉排序树
#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct BSTNode {
	Elemtype data;
	struct BSTNode* rchild, * lchild;
}BSTNode,*BSTree;

//查找，循环
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
	return T;  //返回匹配结点，或者NULL
}

//查找，递归
BSTNode* BSTSearchRecur(BSTree T, Elemtype key) {
	if (T==NULL) //递归结束条件
		return NULL;
	if (T->data == key)
		return T;
	else if (T->data > key) //比根小在左边
		return BSTSearchRecur(T->lchild, key);
	else
		return BSTSearchRecur(T->rchild, key);
}

//插入
bool BSTInsert(BSTree &T, Elemtype key) {
	if (T==NULL) //递归结束条件
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
		BSTInsert(T->lchild, key);  //降低复杂度
	}
	else
	{
		BSTInsert(T->rchild, key);
	}
}

//二叉排序树的构造
void createBST(BSTree& T, Elemtype str[], int n) {
	T == NULL; //初始为空
	int i = 0;
	while (i<n)
	{
		BSTInsert(T, str[i]);
		i++;
	}
}
