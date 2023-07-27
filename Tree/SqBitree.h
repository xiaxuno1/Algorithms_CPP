#pragma once
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

constexpr auto OK = 1;
constexpr auto ERROR = 0;
constexpr int MAXSIZE=100;/* �洢�ռ��ʼ������ */
constexpr int MAX_TREE_SIZE=100; /* ��������������� */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int TElemType;  /* �������������ͣ�Ŀǰ�ݶ�Ϊ���� */

typedef TElemType SqBiTree[MAXSIZE + 1]; //������1��ʼ���������;

TElemType NBiT = 0;  //����

//    init() //��ʼ��һ����
Status init(SqBiTree T) 
{
	int i;
	for ( i = 0; i <= MAX_TREE_SIZE; i++)
	{
		T[i] = NBiT; //��ʼΪ��
	}
	return 1;
}

//createBiT() //����һ��������
Status createBiTree(SqBiTree T) {
	int i = 1;
	while (i <= 30)
	{
		T[i] = i;

		if(T[i / 2 ] == NBiT && T[i] != NBiT && i !=1) /* �˽��(����)��˫���Ҳ��Ǹ� */
		{
			printf("������˫�׵ķǸ����%d\n", T[i]);
			exit(ERROR);
		}
		i++;
	}
	while (i < MAX_TREE_SIZE)
	{
		T[i] = NBiT; /* ���ո�ֵ��T�ĺ���Ľ�� */
		i++;
	}
}

//clear() ���
#define clear init

//isEmpty()  //�Ƿ�Ϊ��
Status isEmpty(SqBiTree T) {
	if (T[1] == NBiT) //�жϸ�����Ƿ�Ϊ��
	{
		return true;
	}
	else
	{
		return false;
	}
}

//assign()  //��ֵ



//depthBiT()  //����������� [log2(n)}+1
int depthBiT(SqBiTree T)
{
	int i, j = -1;
	for (i = MAX_TREE_SIZE; i >= 0; i--) //�Ӻ���ǰ�������һ���ǿս��
	{
		if (T[i] != NBiT)
			break;
	}
	do j++;
	while (i >= powl(2, j));
	return j;
}

//rootBiT() //���ĸ����
Status rootBiT(SqBiTree T, TElemType& e) {
	if (isEmpty(T)) /* T�� */
		return ERROR;
	e = T[1];
	return 1;
}

//parent() //����� [i/2]ȡ��
TElemType parent(SqBiTree T,TElemType e) {
	int i; //e��λ�ã�
	if (T[10] == NBiT)
		return NBiT;
	for ( i = 1; i <=MAX_TREE_SIZE; i++)
	{
		if (T[i]==e)
			return T[i / 2];
	}
	return NBiT; //û��e
}

//lChild() //����
TElemType lChild(SqBiTree T,TElemType e){
	int i;
	if (T[10] == NBiT)
		return NBiT;
	for (i = 1; i <= MAX_TREE_SIZE; i++)
	{
		if (T[i] == e)
			return T[2*i];
	}
	return NBiT;
}
//rChild() //�Һ���
TElemType rChild(SqBiTree T, TElemType e) {
	int i;  //���λ��
	if (T[10] == NBiT)
		return NBiT;
	for (i = 1; i <= MAX_TREE_SIZE; i++)
	{
		if (T[i] == e)
			return T[2 * i+1];
	}
	return NBiT;
}

//preOderTraverse() //ǰ�����
//todo
//inOrderTraverse() //�������
//todo
//postOrderTraverse() //��������
//todo
//leverOrderTraverse() //�������
//todo