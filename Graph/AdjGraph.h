#pragma once
#include <stdio.h>
#include <stdlib.h>

//���嶥�㣬����������ֵ�ͱ�
constexpr int MAX_GRAPH_VERTEX = 100; //���Ķ�������;
typedef int ElemType;  //������������
typedef struct VNode { //����ṹ����+��һ����ָ��
	ElemType data;
	ArcNode* first; //ָ���һ����
};

//������бߵ��������
typedef struct ArcNode{
	int adjvex;  //��/��ָ����λ��
	ArcNode* next;
}ArcNode,*ArcList;

typedef struct {
	VNode[MAX_GRAPH_VERTEX];
}AdjacencyList;  //�ڽӱ�

//ͼ���������㡢�ߵ���ֵ
typedef struct {
	AdjacencyList adj;
	int vernum, arcnum; //���嶥�㡢��/������ֵ
}AdjGraph;


