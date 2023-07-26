#pragma once
//������
#include <iostream>
#include <cstdio>
#include <math.h>
#include <time.h>

constexpr auto OK = 1;
constexpr auto ERROR = 0;

constexpr auto MAXSIZE = 20 /* �洢�ռ��ʼ������ */;

typedef int Status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

//�ڵ㶨��,�������
typedef struct Node
{
	ElemType data;
	Node *next;
}Node;
typedef Node *LinkList; //����LinkListΪָ��

//��ʼ������������һ���յ����Ա�
Status initList(LinkList *L) {
	//����ͷ��㣬��ָ���
	(*L)=(LinkList)malloc(sizeof(Node)); //ΪNode���ٿռ�,*L��һ��ָ��Node���͵�ָ��
	if (!(*L)) //����ռ�ʧ��
		return ERROR;
	(*L)->next = NULL;//ָ��ָ��Ϊ��
	return OK;
}

//isListEmpty(L):   �����Ա�Ϊ�գ�����ture,����false
Status isListEmpty(LinkList &L) 
{
	//ͷ�ڵ�ָ��Ϊ�գ���ʾ���Ա�Ϊ��
	if (L->next)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//ClearList(L):   ������Ա��ͷų�ͷ�����Ŀռ䣬ͷ���ָ��ָ���
Status clearList(LinkList &L) {
	LinkList temp, q;
	temp = L->next;//ָ���һ���ڵ�
	while (temp)
	{

		q = temp->next; //��ʱ�洢����Ҫ�ͷŵĽڵ㣬�����ͷź��޷�������һ���
		free(temp);
		temp = q;
	}
	L->next = nullptr; //ͷ�ڵ����ָ��Ϊ��
	return false;
}

//GetElem(L,i,*e):��L�е�i��Ԫ�ط��ظ�e
Status getElem(LinkList& L, int i, ElemType &e) {
	LinkList temp;
	temp = L->next;
	for (int j = 0; j < i; j++)
	{
		temp = temp->next;
		if (!(temp)) //��i��������
		{
			return ERROR;
		}
	}
	e = temp->data;
	return OK;
}

//LocateElem(L,e):��L�в�����e���Ԫ�أ�����λ�ã�û�з���0
int locateElem(LinkList& L, ElemType& e) {
	LinkList temp;
	int loc = 1;
	temp = L->next; //tempָ���һ��Ԫ��
	while (temp)
	{	
		if ((temp->data) == e)
		{
			return loc;
		}
		else
		{
			temp = temp->next;
			++loc;
		}
	}
	//����Ԫ�ر�����û���ҵ���ͬ
	return false;
}

//ListInsert(*L,i,e):��L�ĵ�i��Ԫ��λ�ò���e
Status listInsert(LinkList& L, int i, ElemType e) {
	LinkList newNode,temp;
	temp = L; //��ʼ��
	int j=1;
	for (j = 1; j < i && temp; j++)//������β�ڵ����
	{
		temp = temp->next;
	}
	if (!temp || j > i) return ERROR; //��i��Ԫ�ز�����
	newNode = (LinkList)malloc(sizeof(Node));  //�½ڵ㿪�ٿռ�
	newNode->data = e;
	newNode->next = temp->next; //�½ڵ�ָ���̽��
	temp->next = newNode; //ָ���½ڵ�
	return OK;
}

//ListDelete(*L,i,*e):��L�ĵ�i��Ԫ��λ��ɾ��������e����
Status listDelete(LinkList& L, int i, ElemType& e) {
	LinkList temp,q;
	temp = L; //temp��ʼ��
	int j = 1;
	for (j = 1; j < i && (temp->next); j++) {
		temp = temp->next;
	}
	if (!(temp->next) || j > i) return ERROR;  //i =0����i��Ԫ�ز�����
	q = temp->next; //���뱣֤��ָ����Ч������ᱨ����������жϣ�temp->next��
	temp->next = q->next;
	e = q->data;
	free(q); //�ͷŽڵ�
	return OK;
}

//ListLength(L)   :�������Ա�L��Ԫ�ظ���
int listLength(LinkList& L) {
	int length = 0;
	LinkList temp;
	temp = L->next;
	while (temp)
	{
		temp = temp->next;
		++length;
	}
	return length;
}

//OList(L)  ������е�Ԫ��
Status OList(LinkList& L){
	LinkList temp;
	temp = L->next;
	while (temp)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	return OK;
}

//createListHead(LinkList *L, int n)ͷ�巨��������Ϊn�����Ա�
void createListHead(LinkList& L, int n) {
	LinkList p,q;
	srand(time(0));  //�������������
	L = (LinkList)malloc(sizeof(Node));
	L->next = nullptr; //ͷ�ڵ�
	for (int i = 0; i <= n; i++)
	{
		q = (LinkList)malloc(sizeof(Node));
		q->data = rand() % 100 + 1; //����100�ڵ������
		q->next = L->next;//�½ڵ�ָ���һ��Ԫ��
		L->next = q;  //ͷ��
	}
}

//createListTail(LinkList *L, int n)ͷ�巨��������Ϊn�����Ա�
void createListTail(LinkList& L, int n) {
	LinkList p, q;
	srand(time(0));  //�������������
	L = (LinkList)malloc(sizeof(Node));
	p = L; //pָ��β���
	for (int i = 0; i < n; i++)
	{
		q = (LinkList)malloc(sizeof(Node));
		q->data = rand() % 100 + 1; //����100�ڵ������
		p->next = q;
		//p�����ƶ���β���
		p = q;
	}
	//β�ڵ�ָ��Ϊ�ո�ָ��
	p->next = NULL;
}
