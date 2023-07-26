#pragma once  //保证文件只被编译一次，避免重复
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>
typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

//定义节点
typedef struct QNode {
	ElemType data;
	QNode* next;
}QNode, *QNodePtr;

//定义链队
typedef struct LinkQueue{
	QNodePtr rear, front;//队头队尾指针，指向头尾节点
}LinkQueue;

//init()初始化
Status init(LinkQueue& Q) {
	Q.front = Q.rear=(QNodePtr)malloc(sizeof(QNode));//分配一个空间
	if (!Q.front)
	{
		exit(OVERFLOW);
	}
	Q.front->next = NULL; //头指针指向j结点空
	return 1;
}

//isEmpty()判断为空
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

//length()长度
int length(LinkQueue Q) {
	//没有存储Q的长度，要计算Q（n）
	int len = 0;
	QNodePtr loc; //存储遍历位置的节点
	loc = Q.front;
	while (Q.rear!=loc)
	{
		++len;
		loc = loc->next;
	}
	return len;
}

//enQueue()入栈
Status enQueue(LinkQueue& Q, const ElemType& e) {
	QNodePtr new_node;
	new_node = (QNodePtr)malloc(sizeof(QNode));
	new_node->data = e;
	new_node->next = NULL;//新的对尾指针指向内容为空
	Q.rear->next = new_node; //对尾节点指向新结点
	Q.rear = new_node; //对尾指针指向新结点
	return 1;
}

//deQueue()出栈
Status deQueue(LinkQueue& Q, ElemType& e) {
	//定义头和尾很重要，否则出对困难
	QNodePtr temp;
	temp = Q.front->next;//队首元素
	Q.front->next = temp->next; //头结点指针指向第二个结点
	e = temp->next->data; //待删除节点内容
	free(temp);
	return 1;
}

//clear()清空
Status clear(LinkQueue& Q) {
	QNodePtr temp,q;
	temp = Q.front->next; //队首元素
	while (temp)
	{
		q = temp; //暂存，以便释放
		temp = temp->next;
		free(q);
	}
	Q.rear = Q.front;
	return 1;
}
//OQueue()输出
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

//返回队首元素
Status getHead(LinkQueue Q, ElemType& e) {
	if (Q.front == Q.rear)
	{
		return 0;
	}
	e = Q.front->next->data;
	return 1;
}