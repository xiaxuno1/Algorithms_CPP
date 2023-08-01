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

//createBiT() //����һ�������� ����ǰ�����˳��洢
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
#define clearBiT destroyBiT

//isEmpty()  //�Ƿ�Ϊ��
Status isEmpty(BiTree T){
	if (T)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//assign()  //��ֵ


//depthBiT()  
//����������ȣ��߶ȣ��������Ӹ���㵽��Զ���ľ���
//�Ӹ����������ݹ鵽���Ӿ�ͷ���صݹ��Һ��ӣ���¼����
int BiTreeDepth(BiTree T)
{
	int i, j;
	if (!T)
		return 0; //�ն�����
	if (T->lchild)
		i = BiTreeDepth(T->lchild);
	else
		i = 0;
	if (T->rchild)
		j = BiTreeDepth(T->rchild);
	else
		j = 0;
	return i > j ? i + 1 : j + 1;
}
//rootBiT() //���ĸ����
TElemType rootBiT(BiTree T) {
	if (isEmpty(T))
	{
		return NBiT;

	}
	return T->data;
}

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
	postOrderTraverse(T->lchild); //��
	postOrderTraverse(T->rchild); //��
	visitT(T); //��
}

//leverOrderTraverse() //�������
void leverOrderTraverse(BiTree T) {
	Queue<BiTree> Q;//��ʼ������
	BiTree temp; //�洢���ӵĽڵ㣬�Ա�������Һ��ӽ��
	Q.push(T);//��������
	while (!Q.isEmpty()) //��Ϊ��
	{
		temp = Q.pop();
		std::cout<< temp->data<<" "; //����

		if (temp->lchild !=NULL)
		{
			Q.push(temp->lchild);
		}
		if (temp->rchild !=NULL)
		{
 			Q.push(temp->rchild);//����������Ϊ��ʱ���
		}
	}
}