#pragma once
//拓扑排序


#include <stdio.h>
#include <stdlib.h>
#include "../StackAndQune/LinkStack.h"
#include "AdjGraph.h"


//算法思想
LinkStack S; //定义栈，辅助存储入度为0的顶点位置
int indegree[];//每个顶点的入度数组，应该为已知
int topo[],count = 0; //存储拓扑排序的顺序,count为记录索引
void visit(int i){}

bool topoLogicSort(AdjGraph G) {
	init(S); //初始化栈
	for ( int i = 0; i < G.vernum; i++)
	{
		if (indegree[i] == 0)
			push(S, i);//入度为0的顶点位置入栈
	}
	while (isEmpty(S) == 1)
	{
		j = pop(S);//入度为0出栈
		topo[count++] = j;//当前排序元素操作
		//重新更新i影响的顶点的入度；将i指向的顶点的入度减少1；
		for ( p = G.adj[i].firstarc;p; p = p->nextarc)  //邻接表的出度（位置）链表
		{
			int v = p->adjvex;
			//i指向的所有顶点的入度减1；判断是否为0,为0入栈
			if (--indegree[v])
				push(S, v);
		}
		if (count<G.vernum) //顶点没有全部排序
			return false;
		else
			return true; //排序成功
	}
}
