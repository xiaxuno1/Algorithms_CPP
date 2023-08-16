#pragma once
//BFS


#include <stdio.h>
#include <stdlib.h>
#include "../Tree/queue.hpp"
#include "../Tree/singlyLinkList.hpp"
#include "MGraph.h"
#include "AdjGraph.h"

//���嶥�㣬����������ֵ�ͱ�
constexpr int MAX_GRAPH_VERTEX = 100; //���Ķ�������;
typedef int ElemType;  //������������
bool visited[MAX_GRAPH_VERTEX]; //��Ӧ����Ƿ񱻷��ʹ���1Ϊ���ʹ�

ElemType FristNeighbor(MGraph G, ElemType x) {
	//pass
}

//ͼG��X����ĵ�һ���ڽӵ�y����һ�����
ElemType NextNeighbor(MGraph G, ElemType x, ElemType y) {
	//pass
}

//ʵ���������
void visit(int v) {}

int d[MAX_GRAPH_VERTEX],path[MAX_GRAPH_VERTEX];
//��v����
void BFS_Min_Distanation(MGraph& G, int v) {
	//��ʼ��d[] path[]
	d[v] = 0; //ͼ��·�����Ϊ0
	for (int i = 0; i < G.vernum; i++)
	{
		d[i] = -1; //��¼���·����-1��ʾ��Чֵ
		path[i] = -1;//��¼���·�����ĸ�������
	}
	visit(v);//�Ӷ�������������G��1��
	visited[v] = true;
	Queue<ElemType> Q, temp; //��������
	Q.push(v); //��һ��������
	while (Q.isEmpty()) //����Ϊ�ս���
	{
		temp = Q; //��ʱ�洢Q
		Q.pop();
		//�����ʣ�µ����б�
		for (ElemType w = FristNeighbor(G, v); w >= 0; NextNeighbor(G,w))
		{
			if (visited[w] == false)
			{
				d[w] = d[v] + 1;//���·������
				path[w] = v; //��¼���·������һ����
				visit(w);
				visited[w] = true;
				Q.push(w);
			}
		}
	}

}


