#pragma once
#include <stdio.h>
#include<stdlib.h>


//˫�ױ�ʾ����˳��
constexpr int MAX_TREE_SIZE = 100;
typedef int ElemType;
typedef struct PTNode {
	ElemType data;
	int parent;
};
typedef struct {
	PTNode nodes[MAX_TREE_SIZE]; //˳��洢���
	int n; //�������
}PTree;

//���ӱ�ʾ����˳��+��ʽ��
typedef struct CTNode {
	int index;  //�ڵ��λ��
	CTNode* child;
};

typedef struct CTBox {
	ElemType data;
	CTNode* firstchild; //ָ���һ������
};

typedef struct CTree{
	CTBox nodes[MAX_TREE_SIZE]; //˳��洢
	int n;
};


//�����ֵܱ�ʾ��
typedef struct CSNode {
	ElemType data;
	CSNode *firstchild *nextsibling
}CSNode,*CSTree;


void visitT(CSNode T) {
	std::cout << T->data << " ";
}

//�����ȸ�����,�ݹ飨α��
void preOrder(CSTree R) {
	if (R == NULL )
	{
		return;
	}
	visitT(R);
	while ("R������T����")
	{
		preOrder(T);
	}
}

//���ĺ���������ݹ飨α��
void postOrder(CSTree R) {
	if (R == NULL)
	{
		return;
	}
	while ("R������T����")
	{
		postOrder(T);
	}
	visitT(R);
}



