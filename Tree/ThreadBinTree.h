#pragma once
#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#include "linkTree.h"

typedef char ThrElemType;
typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef enum { Link, Thread } PointerTag;	/* Link=0表示指向左右孩子指针, */
/* Thread=1表示指向前驱或后继的线索 */

typedef struct ThrBinNode {
	ThrElemType data;
	ThrBinNode* lchild, * rchild;
	PointerTag LTag, RTag;
}*ThrBinTree;

//按照前序遍历顺序创建二叉树
void createTheBit(ThrBinTree& T) {
	TElemtype ch;
	ch = str[treeIndex++]; //递归，因此必须要将treeIndex定位全局，否则每次递归都会被初始化
	if (ch=='#')
	{
		T = NULL;
	}
	else
	{
		T = (ThrBinTree)malloc(sizeof(ThrBinNode));
		if (!T)
			exit(OVERFLOW);
		T->data = ch; //根
		createTheBit(T->lchild);
		if (T->lchild)
			T->LTag = Link; //标记为非线索
		 //左子树存在
		createTheBit(T->rchild);
		if (T->rchild)
			T->RTag = Link; //右子树存在
	}
}

void visitT(ThrBinTree T){
	std::cout << T->data << " ";
}
//pre按照顺序记录遍历结点的前驱，如果
//通过中序遍历返回结点前驱
ThrElemType goal_data = 'E';
ThrBinTree pre =NULL, temp_pre = NULL; //为了避免改变递归的结构，使用全局变量记录前驱
ThrBinTree preDriveInOrder(ThrBinTree T) {
	if (T == NULL)
		return NULL;
	//递归遍历顺序不变，需要对vistT改造，以便记录前驱
	preDriveInOrder(T->lchild);
	
	//遍历的当前节点是否为目标节点
	visitT(T);
	if (T->data == goal_data)
	{
		pre = temp_pre;
	}
	else
	{
	//遍历的当前节点不是目标节点，pre移动到当前节点，继续遍历
		temp_pre = T;
	}
	//目标值不在遍历中
	preDriveInOrder(T->rchild);
}

//中序线索化,中序遍历线索化
void ThrInOrder(ThrBinTree T) {
	if (T==NULL)
	{
		return;
	}
	ThrInOrder(T->lchild);
	visitT(T);
	//线索化,左空子树指向前驱，有空子树指向后继；头无前驱，尾无后继(指向为空即可，不用判断)
	//结点的前驱
	if (T->lchild==NULL)
	{
		T->lchild = pre;
		T->LTag = Thread;  //线索化标记
	}
	//建立结点前驱的后继线索
	if (pre != NULL && pre->rchild ==NULL)
	{
		pre->rchild = T;
		pre->RTag = Thread;
	}
	//随着遍历位置移动前驱结点
	pre = T;
	ThrInOrder(T->rchild);
}

//前序线索化

//后续线索化
