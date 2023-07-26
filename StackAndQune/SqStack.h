#pragma once
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>

constexpr auto OK = 1;
constexpr auto ERROR = 0;

constexpr auto MAXSIZE = 100 /* �洢�ռ��ʼ������ */;

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

typedef struct 
{
	ElemType data[MAXSIZE];
	int top;
}SqStack;

//init(L) : ��ʼ������
Status init(SqStack &S) {
	S.top = -1;
	return true;
}

//isEmpty(L) : �����Ա�Ϊ�գ�����ture, ����false
Status isEmpty(SqStack S) {
	if (S.top = -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//clearStack(L) : ���
Status clear(SqStack &S) {
	S.top = -1;
	return OK;
}

//getTop(L) : ����ջ��
ElemType getTop(SqStack S) {
	return S.data[S.top];
}

//pop(L, *e) : ��ջ����
ElemType pop(SqStack &S,ElemType &e) {
	e = S.data[S.top];
	--S.top;
	return e;
}

//push(L, e) : ��ջ����
Status push(SqStack &S,ElemType &e) {
	if (S.top>=MAXSIZE-1) //�޷�������ջ����,top��0��ʼ
	{
		return ERROR;
	}
	++S.top;
	S.data[S.top] = e;
	return OK;
}

//OStack(L)  ������е�Ԫ��
void OStack(SqStack S) {
	while (S.top != -1)
	{
		std::cout << S.data[S.top] << " ";
		--S.top;
	}
}

//length(L):���س���
int length(SqStack S) {
	return S.top++;
}
