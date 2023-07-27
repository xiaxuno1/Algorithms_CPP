#pragma once
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

constexpr auto OK = 1;
constexpr auto ERROR = 0;
constexpr int MAXSIZE=100;/* 存储空间初始分配量 */
constexpr int MAX_TREE_SIZE=100; /* 二叉树的最大结点数 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int TElemType;  /* 树结点的数据类型，目前暂定为整型 */

typedef TElemType SqBiTree[MAXSIZE + 1]; //从索引1开始，方便计算;

TElemType NBiT = 0;  //定义

//    init() //初始化一棵树
Status init(SqBiTree T) 
{
	int i;
	for ( i = 0; i <= MAX_TREE_SIZE; i++)
	{
		T[i] = NBiT; //初始为空
	}
	return 1;
}

//createBiT() //创造一个二叉树
Status createBiTree(SqBiTree T) {
	int i = 1;
	while (i <= 30)
	{
		T[i] = i;

		if(T[i / 2 ] == NBiT && T[i] != NBiT && i !=1) /* 此结点(不空)无双亲且不是根 */
		{
			printf("出现无双亲的非根结点%d\n", T[i]);
			exit(ERROR);
		}
		i++;
	}
	while (i < MAX_TREE_SIZE)
	{
		T[i] = NBiT; /* 将空赋值给T的后面的结点 */
		i++;
	}
}

//clear() 清空
#define clear init

//isEmpty()  //是否为空
Status isEmpty(SqBiTree T) {
	if (T[1] == NBiT) //判断根结点是否为空
	{
		return true;
	}
	else
	{
		return false;
	}
}

//assign()  //赋值



//depthBiT()  //返回树的深度 [log2(n)}+1
int depthBiT(SqBiTree T)
{
	int i, j = -1;
	for (i = MAX_TREE_SIZE; i >= 0; i--) //从后往前，找最后一个非空结点
	{
		if (T[i] != NBiT)
			break;
	}
	do j++;
	while (i >= powl(2, j));
	return j;
}

//rootBiT() //树的根结点
Status rootBiT(SqBiTree T, TElemType& e) {
	if (isEmpty(T)) /* T空 */
		return ERROR;
	e = T[1];
	return 1;
}

//parent() //父结点 [i/2]取整
TElemType parent(SqBiTree T,TElemType e) {
	int i; //e的位置，
	if (T[10] == NBiT)
		return NBiT;
	for ( i = 1; i <=MAX_TREE_SIZE; i++)
	{
		if (T[i]==e)
			return T[i / 2];
	}
	return NBiT; //没有e
}

//lChild() //左孩子
TElemType lChild(SqBiTree T,TElemType e){
	int i;
	if (T[10] == NBiT)
		return NBiT;
	for (i = 1; i <= MAX_TREE_SIZE; i++)
	{
		if (T[i] == e)
			return T[2*i];
	}
	return NBiT;
}
//rChild() //右孩子
TElemType rChild(SqBiTree T, TElemType e) {
	int i;  //结点位置
	if (T[10] == NBiT)
		return NBiT;
	for (i = 1; i <= MAX_TREE_SIZE; i++)
	{
		if (T[i] == e)
			return T[2 * i+1];
	}
	return NBiT;
}

//preOderTraverse() //前序遍历
//todo
//inOrderTraverse() //中序遍历
//todo
//postOrderTraverse() //后续遍历
//todo
//leverOrderTraverse() //层序遍历
//todo