#pragma once
#include <string.h>
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"
#include "queue.hpp"


typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
int treeIndex = 1;

//
typedef char String[24];  //һ����������ݳ���
String str;
//�����data��ֵ��ΪԪ�ص�Ԫ
Status strAssign(String T,const char *chars) {
	int i;
	if (strlen(chars) > MAXSIZE)
	{
		return 0;
	}
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return 1;
	}
}

//
typedef char TElemtype;
typedef struct BiTNode {
	TElemtype data;
	BiTNode* rchild, * lchild;
}BiTNode,*BiTree;

//init() //��ʼ��һ����
Status init(BiTree& T) {
	T = NULL;
	return 1;
}

//createBiT() //����һ��������
void createBiT(BiTree& T) {
	TElemtype ch;
	ch = str[treeIndex++]; 
	//���������str�ַ�������һ����������#��ʾ��Ч
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode)); //�����������ڵ�
		if (!T)
		{
			exit(OVERFLOW);//���
		}
		T->data = ch;  //����㸳ֵ ������ ǰ������ķ�ʽ����
		createBiT(T->lchild); //����������������
		createBiT(T->rchild);
	}
}

//visitT()
void visitT(BiTree T) {
	std::cout << T->data << " ";
}
//clear() //���
void destroyBiT(BiTree T) {
	if (T)
	{
		if (T->lchild)
		{
			destroyBiT(T->lchild);
		}
		if (T->rchild)
		{
			destroyBiT(T->rchild);
		}
		free(T); //�Ӹ���㿪ʼ�����ձ���˳���ͷŽ��
		T = NULL;
	}
}

//isEmpty()  //�Ƿ�Ϊ��
Status isEmpty(BiTree T){
	if (T)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//assign()  //��ֵ


//depthBiT()  //�����������
//rootBiT() //���ĸ����
//parent() //�����
//lChild() //����
//rChild() //�Һ���
//preOderTraverse() //ǰ�����
void preOderTraverse(BiTree T) {
	if (T == NULL) //�����Ľ�������
		return;
	visitT(T);//��
	preOderTraverse(T->lchild);//��
	preOderTraverse(T->rchild);//��
}

//inOrderTraverse() //�������
void inOrderTraverse(BiTree T) {
	if (T == NULL)
		return;
	inOrderTraverse(T->lchild);
	visitT(T);
	inOrderTraverse(T->rchild);
}

//postOrderTraverse() //��������
void postOrderTraverse(BiTree T) {
	if (T == NULL)
		return;
	postOrderTraverse(T->lchild);
	postOrderTraverse(T->rchild);
	visitT(T);
}

//leverOrderTraverse() //�������
void leverOrderTraverse(BiTree T) {
	Queue<BiTree> Q;//��ʼ������
	Q.push(T);//��������
	while (!Q.isEmpty()) //��Ϊ��
	{
		Q.pop(); //����
		if (T->lchild !=NULL)
		{
			Q.push(T->lchild);
		}
		if (T->rchild !=NULL)
		{
			Q.push(T->rchild);//����������Ϊ��ʱ���
		}
	}
}