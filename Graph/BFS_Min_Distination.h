#pragma once
//BFS


#include <stdio.h>
#include <stdlib.h>
#include "../Tree/queue.hpp"
#include "../Tree/singlyLinkList.hpp"
#include "MGraph.h"
#include "AdjGraph.h"

//定义顶点，包括顶点数值和边
constexpr int MAX_GRAPH_VERTEX = 100; //最大的顶点数量;
typedef int ElemType;  //顶点数据类型
bool visited[MAX_GRAPH_VERTEX]; //对应结点是否被访问过，1为访问过

ElemType FristNeighbor(MGraph G, ElemType x) {
	//pass
}

//图G的X顶点的第一个邻接点y的下一个结点
ElemType NextNeighbor(MGraph G, ElemType x, ElemType y) {
	//pass
}

//实现输出顶点
void visit(int v) {}

int d[MAX_GRAPH_VERTEX],path[MAX_GRAPH_VERTEX];
//从v出发
void BFS_Min_Distanation(MGraph& G, int v) {
	//初始化d[] path[]
	d[v] = 0; //图的路径起点为0
	for (int i = 0; i < G.vernum; i++)
	{
		d[i] = -1; //记录最短路径，-1表示无效值
		path[i] = -1;//记录最短路径从哪个顶点来
	}
	visit(v);//从顶结点出发，如下G（1）
	visited[v] = true;
	Queue<ElemType> Q, temp; //辅助队列
	Q.push(v); //第一个结点入队
	while (Q.isEmpty()) //队列为空结束
	{
		temp = Q; //临时存储Q
		Q.pop();
		//顶点的剩下的所有边
		for (ElemType w = FristNeighbor(G, v); w >= 0; NextNeighbor(G,w))
		{
			if (visited[w] == false)
			{
				d[w] = d[v] + 1;//最短路径长度
				path[w] = v; //记录最短路径的上一个点
				visit(w);
				visited[w] = true;
				Q.push(w);
			}
		}
	}

}


