#pragma once
//�ڽӾ���
#include <stdio.h>
#include<stdlib.h>


constexpr int MAX_GRAPH_VERTEX = 100; //���Ķ�������;
typedef int ElemType; //������������
typedef struct MGraph {
	ElemType data[MAX_GRAPH_VERTEX]; //����ͼ�Ķ�������
	int vernum, arcnum; //���嶥�㡢��/������ֵ
	int edge[MAX_GRAPH_VERTEX][MAX_GRAPH_VERTEX]; //�����ڽӾ����ϵ��
}MGraph;

