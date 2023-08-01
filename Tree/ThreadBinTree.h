#pragma once
#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#include "linkTree.h"

typedef char ThrElemType;
typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK�� */
typedef enum { Link, Thread } PointerTag;	/* Link=0��ʾָ�����Һ���ָ��, */
/* Thread=1��ʾָ��ǰ�����̵����� */

typedef struct ThrBinNode {
	ThrElemType data;
	ThrBinNode* lchild, * rchild;
	PointerTag LTag, RTag;
}*ThrBinTree;

//����ǰ�����˳�򴴽�������
void createTheBit(ThrBinTree& T) {
	TElemtype ch;
	ch = str[treeIndex++]; //�ݹ飬��˱���Ҫ��treeIndex��λȫ�֣�����ÿ�εݹ鶼�ᱻ��ʼ��
	if (ch=='#')
	{
		T = NULL;
	}
	else
	{
		T = (ThrBinTree)malloc(sizeof(ThrBinNode));
		if (!T)
			exit(OVERFLOW);
		T->data = ch; //��
		createTheBit(T->lchild);
		if (T->lchild)
			T->LTag = Link; //���Ϊ������
		 //����������
		createTheBit(T->rchild);
		if (T->rchild)
			T->RTag = Link; //����������
	}
}

void visitT(ThrBinTree T){
	std::cout << T->data << " ";
}
//pre����˳���¼��������ǰ�������
//ͨ������������ؽ��ǰ��
ThrElemType goal_data = 'E';
ThrBinTree pre =NULL, temp_pre = NULL; //Ϊ�˱���ı�ݹ�Ľṹ��ʹ��ȫ�ֱ�����¼ǰ��
ThrBinTree preDriveInOrder(ThrBinTree T) {
	if (T == NULL)
		return NULL;
	//�ݹ����˳�򲻱䣬��Ҫ��vistT���죬�Ա��¼ǰ��
	preDriveInOrder(T->lchild);
	
	//�����ĵ�ǰ�ڵ��Ƿ�ΪĿ��ڵ�
	visitT(T);
	if (T->data == goal_data)
	{
		pre = temp_pre;
	}
	else
	{
	//�����ĵ�ǰ�ڵ㲻��Ŀ��ڵ㣬pre�ƶ�����ǰ�ڵ㣬��������
		temp_pre = T;
	}
	//Ŀ��ֵ���ڱ�����
	preDriveInOrder(T->rchild);
}

//����������,�������������
void ThrInOrder(ThrBinTree T) {
	if (T==NULL)
	{
		return;
	}
	ThrInOrder(T->lchild);
	visitT(T);
	//������,�������ָ��ǰ�����п�����ָ���̣�ͷ��ǰ����β�޺��(ָ��Ϊ�ռ��ɣ������ж�)
	//����ǰ��
	if (T->lchild==NULL)
	{
		T->lchild = pre;
		T->LTag = Thread;  //���������
	}
	//�������ǰ���ĺ������
	if (pre != NULL && pre->rchild ==NULL)
	{
		pre->rchild = T;
		pre->RTag = Thread;
	}
	//���ű���λ���ƶ�ǰ�����
	pre = T;
	ThrInOrder(T->rchild);
}

//ǰ��������

//����������