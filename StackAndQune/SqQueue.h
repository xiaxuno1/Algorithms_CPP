#pragma once
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>
typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */
constexpr int MAXSIZE = 100;

typedef struct {
	//��Ϊ�����Ƚ��ȳ�����������ʱ��Ҫ֪��β��λ�ã��ڳ���ʱ��Ҫ֪��ͷ��λ��
	ElemType data[MAXSIZE];
	int front; //ͷָ��
	int rear; //βָ��
}SqQueue;

//��ʼ������
Status init(SqQueue& Q) {
	Q.front = Q.rear = 0;
	return 1;
}

//�ж��Ƿ�Ϊ��
Status isEmpty(SqQueue& Q) {
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;
}

//����
int length(SqQueue& Q) {
	return (Q.front - Q.rear + MAXSIZE) % MAXSIZE;  //�൱��ȡ����ֵ
}

//���
Status enQueue(SqQueue& Q, ElemType& e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)	/* ���������ж� */
		return ERROR;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE; //��β����ƶ�һλ�����������ͷ��ѭ������
	return 1;
}

//����
Status deQueue(SqQueue& Q, ElemType& e) {
	if (Q->front == Q->rear)			/* ���пյ��ж� */
		return ERROR;
	*e = Q->data[Q->front];				/* ����ͷԪ�ظ�ֵ��e */
	Q->front = (Q->front + 1) % MAXSIZE;	/* frontָ�������һλ�ã� */
	/* ���������ת������ͷ�� */
	return  OK;
}

//��ӡ���
Status OQueue(SqQueue Q)
{
	int i;
	i = Q.front;
	while (i != Q.rear)
	{
		visit(Q.data[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
	return 1;
}
