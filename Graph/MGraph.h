#pragma once
//邻接矩阵法
#include <stdio.h>
#include<stdlib.h>


constexpr int MAX_GRAPH_VERTEX = 100; //最大的顶点数量;
typedef int ElemType; //定义数据类型
typedef struct MGraph {
	ElemType data[MAX_GRAPH_VERTEX]; //定义图的顶点数据
	int vernum, arcnum; //定义顶点、边/弧的数值
	int edge[MAX_GRAPH_VERTEX][MAX_GRAPH_VERTEX]; //定义邻接矩阵关系表
}MGraph;

