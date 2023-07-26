#pragma once
//˳�����Ա�

#include <iostream>
using namespace std;


constexpr auto MaxSize = 20;  //������������;�궨���޸�Ϊconstexpr 
typedef int ElmType; //�����������ͣ�������int

struct SqList
{
	ElmType arr[MaxSize]; //���鳤�ȱ���̶�
	int length; //��¼���Ա�ĳ���
};

//��ʼ������������һ���յ����Ա�
bool initList(SqList *L) {
	L->length = 0;
	return true;
}

//�����Ա�Ϊ�գ�����ture,����false
bool isListEmpty(SqList &L) {
	if (L.length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//������Ա�
bool clearList(SqList *L) {
	L->length = 0;
	return 0;
}

//GetElem(L,i,*e):��L�е�i��Ԫ�ط��ظ�e
bool GetElem(SqList& L, int i, ElmType& e) {
	if (L.length == 0 || i<1 || i>L.length)
	{
		return false;
	}
	e = L.arr[i - 1];//�����±�������0��ʼ
	return true;
}

//LocateElem(L,e):��L�в�����e���Ԫ�أ�����λ�ã�û�з���0
int locateElem(SqList &L, ElmType& e) {
	int i;
	if (L.length ==0)
	{
		return 0;
	}
	for (i = 0; i < L.length; i++)
	{
		if (L.arr[i] == e)
			break;
	}
	if (i >= L.length)
		return 0;
	return i + 1;
}

//ListInsert(*L,i,e):��L�ĵ�i��Ԫ��λ�ò���e
bool listInsert(SqList &L, int i, ElmType &e) {
	if (L.length >= MaxSize) //��������Ƿ����������������������޷�����
		return 0;
	if (i < 1 || i > L.length + 1) //���λ��
		return 0;
	if (i<=L.length)//���벻�ڱ�β
	{
		//i���Ԫ��һ�κ��ƣ�ǰ�治��
		for (int j = L.length-1; j >= i - 1; j--)
		{
			L.arr[j+1] = L.arr[j];
		}
	}
	L.arr[i -1] = e; //i��Ԫ���ƶ���ɺ����
	L.length++;

	return true;
}

//ListDelete(*L,i,*e):��L�ĵ�i��Ԫ��λ��ɾ��������e����
bool listDelete(SqList &L, int i, ElmType &e) {
	//���i
	if (i <= 0 || i >= L.length + 1)
		return 0;
	e = L.arr[i - 1];
	if (i<=L.length)
	{
		for (int j= i - 1; j>=L.length-1; j++)
		{
			L.arr[j] = L.arr[j + 1];
		}
	}
	L.length--;
	return true;
}

//ListLength(L)   :�������Ա�L��Ԫ�ظ���
int listLength(SqList &L) {
	return L.length;
}

//OList �������Ԫ��
bool OList(SqList& L) {
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.arr[i]<<" ";
	cout << endl;
	return true;
}