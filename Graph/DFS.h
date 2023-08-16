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

//整个图进行广度优先遍历
void DFSTraverse(MGraph G) {
	//初始化访问标记
	for (int i = 0; i < G.vernum; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < G.vernum; i++)
	{
		if (!visited[i]) {
			DFS(G, i); //子图，最大连通分量
		}
	}
}

//从v出发
void DFS(MGraph& G, int v) {
	visit(v);//从顶结点出发，如下G（1）
	visited[v] = true;
	Queue<ElemType> Q, temp; //辅助队列
	//顶点的剩下的所有边
	for (ElemType w = FristNeighbor(G, v); w >= 0; NextNeighbor(w))
	{
		if (visited[w] == false)//没有遍历过，以防回路
			DFS(G, w);//递归到最深处，深度优先遍历
	}

}

