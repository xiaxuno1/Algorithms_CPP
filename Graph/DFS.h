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

//����ͼ���й�����ȱ���
void DFSTraverse(MGraph G) {
	//��ʼ�����ʱ��
	for (int i = 0; i < G.vernum; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < G.vernum; i++)
	{
		if (!visited[i]) {
			DFS(G, i); //��ͼ�������ͨ����
		}
	}
}

//��v����
void DFS(MGraph& G, int v) {
	visit(v);//�Ӷ�������������G��1��
	visited[v] = true;
	Queue<ElemType> Q, temp; //��������
	//�����ʣ�µ����б�
	for (ElemType w = FristNeighbor(G, v); w >= 0; NextNeighbor(w))
	{
		if (visited[w] == false)//û�б��������Է���·
			DFS(G, w);//�ݹ鵽�����������ȱ���
	}

}

