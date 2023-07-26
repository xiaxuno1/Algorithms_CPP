#pragma once  //��֤�ļ�ֻ������һ�Σ������ظ�
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>
typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

//����ڵ�
typedef struct QNode {
	ElemType data;
	QNode* next;
}QNode, *QNodePtr;

//��������
typedef struct LinkQueue{
	QNodePtr rear, front;//��ͷ��βָ�룬ָ��ͷβ�ڵ�
}LinkQueue;

//init()��ʼ��
Status init(LinkQueue& Q) {
	Q.front = Q.rear=(QNodePtr)malloc(sizeof(QNode));//����һ���ռ�
	if (!Q.front)
	{
		exit(OVERFLOW);
	}
	Q.front->next = NULL; //ͷָ��ָ��j����
	return 1;
}

//isEmpty()�ж�Ϊ��
Status isEmpty(LinkQueue Q) {
	if (Q.front == Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//length()����
int length(LinkQueue Q) {
	//û�д洢Q�ĳ��ȣ�Ҫ����Q��n��
	int len = 0;
	QNodePtr loc; //�洢����λ�õĽڵ�
	loc = Q.front;
	while (Q.rear!=loc)
	{
		++len;
		loc = loc->next;
	}
	return len;
}

//enQueue()��ջ
Status enQueue(LinkQueue& Q, const ElemType& e) {
	QNodePtr new_node;
	new_node = (QNodePtr)malloc(sizeof(QNode));
	new_node->data = e;
	new_node->next = NULL;//�µĶ�βָ��ָ������Ϊ��
	Q.rear->next = new_node; //��β�ڵ�ָ���½��
	Q.rear = new_node; //��βָ��ָ���½��
	return 1;
}

//deQueue()��ջ
Status deQueue(LinkQueue& Q, ElemType& e) {
	//����ͷ��β����Ҫ�������������
	QNodePtr temp;
	temp = Q.front->next;//����Ԫ��
	Q.front->next = temp->next; //ͷ���ָ��ָ��ڶ������
	e = temp->next->data; //��ɾ���ڵ�����
	free(temp);
	return 1;
}

//clear()���
Status clear(LinkQueue& Q) {
	QNodePtr temp,q;
	temp = Q.front->next; //����Ԫ��
	while (temp)
	{
		q = temp; //�ݴ棬�Ա��ͷ�
		temp = temp->next;
		free(q);
	}
	Q.rear = Q.front;
	return 1;
}
//OQueue()���
Status OQueue(LinkQueue Q) {
	QNodePtr temp;
	temp = Q.front->next;
	while (temp)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	return 0;
}

//���ض���Ԫ��
Status getHead(LinkQueue Q, ElemType& e) {
	if (Q.front == Q.rear)
	{
		return 0;
	}
	e = Q.front->next->data;
	return 1;
}