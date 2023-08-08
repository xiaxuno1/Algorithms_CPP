#pragma once
#include <stdio.h>
#include<stdlib.h>


//双亲表示法（顺序）
constexpr int MAX_TREE_SIZE = 100;
typedef int ElemType;
typedef struct PTNode {
	ElemType data;
	int parent;
};
typedef struct {
	PTNode nodes[MAX_TREE_SIZE]; //顺序存储结点
	int n; //结点数量
}PTree;

//孩子表示法（顺序+链式）
typedef struct CTNode {
	int index;  //节点的位置
	CTNode* child;
};

typedef struct CTBox {
	ElemType data;
	CTNode* firstchild; //指向第一个孩子
};

typedef struct CTree{
	CTBox nodes[MAX_TREE_SIZE]; //顺序存储
	int n;
};


//孩子兄弟表示法
typedef struct CSNode {
	ElemType data;
	CSNode *firstchild *nextsibling
}CSNode,*CSTree;


void visitT(CSNode T) {
	std::cout << T->data << " ";
}

//树的先根遍历,递归（伪）
void preOrder(CSTree R) {
	if (R == NULL )
	{
		return;
	}
	visitT(R);
	while ("R的子树T存在")
	{
		preOrder(T);
	}
}

//树的后根遍历，递归（伪）
void postOrder(CSTree R) {
	if (R == NULL)
	{
		return;
	}
	while ("R的子树T存在")
	{
		postOrder(T);
	}
	visitT(R);
}



