#pragma once
#include <string.h>
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"
#include "queue.hpp"


typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
int treeIndex = 1;

//
typedef char String[24];  //一个结点存放数据长度
String str;
//给结点data赋值作为元素单元
Status strAssign(String T,const char *chars) {
	int i;
	if (strlen(chars) > MAXSIZE)
	{
		return 0;
	}
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return 1;
	}
}

//
typedef char TElemtype;
typedef struct BiTNode {
	TElemtype data;
	BiTNode* rchild, * lchild;
}BiTNode,*BiTree;

//init() //初始化一棵树
Status init(BiTree& T) {
	T = NULL;
	return 1;
}

//createBiT() //创造一个二叉树
void createBiT(BiTree& T) {
	TElemtype ch;
	ch = str[treeIndex++]; 
	//根据输入的str字符串创建一个二叉树，#表示无效
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode)); //创建二叉树节点
		if (!T)
		{
			exit(OVERFLOW);//溢出
		}
		T->data = ch;  //根结点赋值 根左右 前序遍历的方式生成
		createBiT(T->lchild); //迭代创建左右子树
		createBiT(T->rchild);
	}
}

//visitT()
void visitT(BiTree T) {
	std::cout << T->data << " ";
}
//clear() //清空
void destroyBiT(BiTree T) {
	if (T)
	{
		if (T->lchild)
		{
			destroyBiT(T->lchild);
		}
		if (T->rchild)
		{
			destroyBiT(T->rchild);
		}
		free(T); //从根结点开始，按照遍历顺序释放结点
		T = NULL;
	}
}

//isEmpty()  //是否为空
Status isEmpty(BiTree T){
	if (T)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//assign()  //赋值


//depthBiT()  //返回树的深度
//rootBiT() //树的根结点
//parent() //父结点
//lChild() //左孩子
//rChild() //右孩子
//preOderTraverse() //前序遍历
void preOderTraverse(BiTree T) {
	if (T == NULL) //迭代的结束条件
		return;
	visitT(T);//根
	preOderTraverse(T->lchild);//左
	preOderTraverse(T->rchild);//右
}

//inOrderTraverse() //中序遍历
void inOrderTraverse(BiTree T) {
	if (T == NULL)
		return;
	inOrderTraverse(T->lchild);
	visitT(T);
	inOrderTraverse(T->rchild);
}

//postOrderTraverse() //后续遍历
void postOrderTraverse(BiTree T) {
	if (T == NULL)
		return;
	postOrderTraverse(T->lchild);
	postOrderTraverse(T->rchild);
	visitT(T);
}

//leverOrderTraverse() //层序遍历
void leverOrderTraverse(BiTree T) {
	Queue<BiTree> Q;//初始化队列
	Q.push(T);//根结点入队
	while (!Q.isEmpty()) //不为空
	{
		Q.pop(); //出队
		if (T->lchild !=NULL)
		{
			Q.push(T->lchild);
		}
		if (T->rchild !=NULL)
		{
			Q.push(T->rchild);//左右子树不为空时入队
		}
	}
}