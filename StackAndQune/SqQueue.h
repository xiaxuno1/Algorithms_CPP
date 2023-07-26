#pragma once
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>
typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */
constexpr int MAXSIZE = 100;

typedef struct {
	//因为队列先进先出，因此在入队时需要知道尾的位置，在出队时需要知道头的位置
	ElemType data[MAXSIZE];
	int front; //头指针
	int rear; //尾指针
}SqQueue;

//初始化操作
Status init(SqQueue& Q) {
	Q.front = Q.rear = 0;
	return 1;
}

//判断是否为空
Status isEmpty(SqQueue& Q) {
	if (Q.front == Q.rear)
	{
		return true;
	}
	return false;
}

//长度
int length(SqQueue& Q) {
	return (Q.front - Q.rear + MAXSIZE) % MAXSIZE;  //相当于取绝对值
}

//入队
Status enQueue(SqQueue& Q, ElemType& e) {
	if ((Q->rear + 1) % MAXSIZE == Q->front)	/* 队列满的判断 */
		return ERROR;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE; //对尾向后移动一位，到最后则向头，循环出入
	return 1;
}

//出队
Status deQueue(SqQueue& Q, ElemType& e) {
	if (Q->front == Q->rear)			/* 队列空的判断 */
		return ERROR;
	*e = Q->data[Q->front];				/* 将队头元素赋值给e */
	Q->front = (Q->front + 1) % MAXSIZE;	/* front指针向后移一位置， */
	/* 若到最后则转到数组头部 */
	return  OK;
}

//打印输出
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
