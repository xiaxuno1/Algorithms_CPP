// ListPro.cpp : 表
//线性表顺序结构、
/*
ADT List
Data
	有限序列，顺序存储
Opration
	initList(L):    初始化操作，建立一个空的线性表
	isListEmpty(L):   若线性表为空，返回ture,否则false
	clearList(L):   清空线性表
	getElem(L,i,*e):将L中第i个元素返回给e
	locateElem(L,e):在L中查找与e相等元素，返回位置，没有返回0
	listInsert(*L,i,e):在L的第i个元素位置插入e
	listDelete(*L,i,*e):在L的第i个元素位置删除，并用e返回
	listLength(L)   :返回线性表L的元素个数
	OList(L)  输出所有的元素
	createListHead(LinkList *L, int n) 头插法创建长度为n的线性表
	createListTail(LinkList *L, int n)
endADT
*/

#include <iostream>
#include "SqList.h"
#include "SLinkList.h"
using namespace std;

void test_sqlist() {
	SqList L;
	//SqList Lb;

	int i, j, k;

	initList(&L);
	printf("初始化L后：L.length=%d\n", L.length);

	for (j = 1; j <= 5; j++)
		listInsert(L, 1, j);
	printf("在L的表头依次插入1～5后：L.data=");
	OList(L);

	printf("ListLength(L)=%d \n", listLength(L));
	i = isListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	i = clearList(&L);
	printf("清空L后：ListLength(L)=%d\n", listLength(L));
	i = isListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	for (j = 1; j <= 10; j++)
		listInsert(L, j, j);
	printf("在L的表尾依次插入1～10后：L.data=");
	OList(L);

	printf("ListLength(L)=%d \n", listLength(L));

	ElmType e = 0;
	listInsert(L, 1, e);
	printf("在L的表头插入0后：L.data=");
	OList(L);
	printf("ListLength(L)=%d \n", listLength(L));

	ElmType e1;//定义一个空指针变量
	GetElem(L, 5, e1);
	printf("第5个元素的值为：%d\n", e1);
	for (j = 3; j <= 4; j++)
	{
		k = locateElem(L, j);
		if (k)
			printf("第%d个元素的值为%d\n", k, j);
		else
			printf("没有值为%d的元素\n", j);
	}

	k = listLength(L); /* k为表长 */
	for (j = k + 1; j >= k; j--)
	{
		i = listDelete(L, j, e); /* 删除第j个数据 */
		if (i == 0)
			printf("删除第%d个数据失败\n", j);
		else
			printf("删除第%d个的元素值为：%d\n", j, e);
	}
	printf("依次输出L的元素：");
	OList(L);

	j = 5;
	listDelete(L, j, e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n", j, e);

	printf("依次输出L的元素：");
	OList(L);

	i = clearList(&L);
	printf("\n清空L后：ListLength(L)=%d\n", listLength(L));
}

void test_SLinkList() {
	LinkList L;
	ElemType e;
	Status i;
	int j, k;
	i = initList(&L);
	printf("初始化L后：ListLength(L)=%d\n", listLength(L));
	for (j = 1; j <= 5; j++)
		i = listInsert(L, 1, j);
	printf("在L的表头依次插入1～5后：L.data=");
	OList(L);

	printf("ListLength(L)=%d \n", listLength(L));
	i = isListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	i = clearList(L);
	printf("清空L后：ListLength(L)=%d\n", listLength(L));
	i = isListEmpty(L);
	printf("L是否空：i=%d(1:是 0:否)\n", i);

	for (j = 1; j <= 10; j++)
		listInsert(L, j, j);
	listInsert(L, 18, 18);
	printf("在L的表尾依次插入1～10后：L.data=");
	OList(L);

	printf("ListLength(L)=%d \n", listLength(L));

	listInsert(L, 1, 0);
	printf("在L的表头插入0后：L.data=");
	OList(L);
	printf("ListLength(L)=%d \n", listLength(L));

	getElem(L, 5, e);
	printf("第5个元素的值为：%d\n", e);

	for (j = 3; j <= 4; j++)
	{
		k = locateElem(L, j);
		if (k)
			printf("第%d个元素的值为%d\n", k, j);
		else
			printf("没有值为%d的元素\n", j);
	}

	k = listLength(L); /* k为表长 */
	for (j = k + 1; j >= k; j--)
	{
		i = listDelete(L, j, e); /* 删除第j个数据 */
		if (i == ERROR)
			printf("删除第%d个数据失败\n", j);
		else
			printf("删除第%d个的元素值为：%d\n", j, e);
	}
	printf("依次输出L的元素：");
	OList(L);

	j = 5;
	listDelete(L, j, e); /* 删除第5个数据 */
	printf("删除第%d个的元素值为：%d\n", j, e);

	printf("依次输出L的元素：");
	OList(L);

	i = clearList(L);
	printf("\n清空L后：ListLength(L)=%d\n", listLength(L));
	createListHead(L, 20);
	printf("整体创建L的元素(头插法)：");
	OList(L);

	i = clearList(L);
	printf("\n删除L后：ListLength(L)=%d\n", listLength(L));
	createListTail(L, 20);
	printf("整体创建L的元素(尾插法)：");
	OList(L);

}



int main()
{
	//test_sqlist();
	test_SLinkList();
    std::cout << "End\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

