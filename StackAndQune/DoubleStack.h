#pragma once
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>
typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

typedef struct DoubleStack{
	ElemType data[MAXSIZE];
	int top1, top2; //����ջ��ջ������λ��
}DoubleStack;

Status init(DoubleStack& S) {
	S.top1 = -1;
	S.top2 = MAXSIZE;
	return OK;
}

//isEmpty(L) : �����Ա�Ϊ�գ�����ture, ����false
Status isEmpty(DoubleStack S) {
	if (S.top1 == -1 && S.top2 == MAXSIZE)
	{
		return true;
	}
	return false;
}

//clearStack(L) : ���
Status clear(DoubleStack& S) {
	S.top1 = -1;
	S.top2 = MAXSIZE;
	return OK;
}

//getTop(L) : ����ջ��

//pop(L, *e) : ��ջ����
Status pop(DoubleStack& S, ElemType& e, int stackNum) {
	if (S.top1 == -1 || S.top2 == MAXSIZE) //���߱���ջ����
	{
		return ERROR;
	}
	if (stackNum == 1)
	{
		e = S.data[S.top1];
		--S.top1;
	}
	if (stackNum == 2)
	{
		e = S.data[S.top2];
		++S.top2;
	}
	return 1;
}

//push(L, e) : ��ջ����
Status push(DoubleStack& S, ElemType& e, int stackNum) {
	if (S.top1 >= S.top2 || S.top2-S.top1<=1) //�޷���ջ����
	{
		return ERROR;
	}
	if (stackNum == 1)//ջ1����
	{
		++S.top1;
		S.data[S.top1] = e;
	}
	if (S.top2 <= 0)
	{
		return ERROR;
	}
	if (stackNum == 2)//ջ2����
	{
		--S.top2;
		S.data[S.top2] = e;
	}
	return OK;
}


//length(L) : ���س���
int length(DoubleStack S) {
	return S.top1 + 1 + (MAXSIZE - S.top2);
}

//OStack(L)  ������е�Ԫ��
void OStack(DoubleStack S) {
	int i = 0;
	while (i <= S.top1)
	{
		std::cout << S.data[i++] << " ";
	}
	i = S.top2;
	while (i < MAXSIZE)  //MAXSIZE��1��ʼ��i��0��ʼ
	{
		std::cout << S.data[i] << " ";
		++i;
	}
}
