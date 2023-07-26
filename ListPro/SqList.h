#pragma once
//顺序线性表

#include <iostream>
using namespace std;


constexpr auto MaxSize = 20;  //定义数组容量;宏定义修改为constexpr 
typedef int ElmType; //定义数据类型，这里用int

struct SqList
{
	ElmType arr[MaxSize]; //数组长度必须固定
	int length; //记录线性表的长度
};

//初始化操作，建立一个空的线性表
bool initList(SqList *L) {
	L->length = 0;
	return true;
}

//若线性表为空，返回ture,否则false
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

//清空线性表
bool clearList(SqList *L) {
	L->length = 0;
	return 0;
}

//GetElem(L,i,*e):将L中第i个元素返回给e
bool GetElem(SqList& L, int i, ElmType& e) {
	if (L.length == 0 || i<1 || i>L.length)
	{
		return false;
	}
	e = L.arr[i - 1];//数组下标索引从0开始
	return true;
}

//LocateElem(L,e):在L中查找与e相等元素，返回位置，没有返回0
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

//ListInsert(*L,i,e):在L的第i个元素位置插入e
bool listInsert(SqList &L, int i, ElmType &e) {
	if (L.length >= MaxSize) //检查数组是否满足条件，数组已满，无法插入
		return 0;
	if (i < 1 || i > L.length + 1) //检查位置
		return 0;
	if (i<=L.length)//插入不在表尾
	{
		//i后的元素一次后移，前面不变
		for (int j = L.length-1; j >= i - 1; j--)
		{
			L.arr[j+1] = L.arr[j];
		}
	}
	L.arr[i -1] = e; //i后元素移动完成后插入
	L.length++;

	return true;
}

//ListDelete(*L,i,*e):在L的第i个元素位置删除，并用e返回
bool listDelete(SqList &L, int i, ElmType &e) {
	//检查i
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

//ListLength(L)   :返回线性表L的元素个数
int listLength(SqList &L) {
	return L.length;
}

//OList 输出所有元素
bool OList(SqList& L) {
	int i;
	for (i = 0; i < L.length; i++)
		cout << L.arr[i]<<" ";
	cout << endl;
	return true;
}