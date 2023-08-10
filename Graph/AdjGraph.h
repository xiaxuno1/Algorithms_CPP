#pragma once
#include <stdio.h>
#include <stdlib.h>

//定义顶点，包括顶点数值和边
constexpr int MAX_GRAPH_VERTEX = 100; //最大的顶点数量;
typedef int ElemType;  //顶点数据类型
typedef struct VNode { //顶点结构数据+第一条边指针
	ElemType data;
	ArcNode* first; //指向第一个边
};

//结点所有边的组成链表
typedef struct ArcNode{
	int adjvex;  //边/弧指向结点位置
	ArcNode* next;
}ArcNode,*ArcList;

typedef struct {
	VNode[MAX_GRAPH_VERTEX];
}AdjacencyList;  //邻接表

//图，包含顶点、边的数值
typedef struct {
	AdjacencyList adj;
	int vernum, arcnum; //定义顶点、边/弧的数值
}AdjGraph;


