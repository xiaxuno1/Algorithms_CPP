#pragma once
//��������


#include <stdio.h>
#include <stdlib.h>
#include "../StackAndQune/LinkStack.h"
#include "AdjGraph.h"


//�㷨˼��
LinkStack S; //����ջ�������洢���Ϊ0�Ķ���λ��
int indegree[];//ÿ�������������飬Ӧ��Ϊ��֪
int topo[],count = 0; //�洢���������˳��,countΪ��¼����
void visit(int i){}

bool topoLogicSort(AdjGraph G) {
	init(S); //��ʼ��ջ
	for ( int i = 0; i < G.vernum; i++)
	{
		if (indegree[i] == 0)
			push(S, i);//���Ϊ0�Ķ���λ����ջ
	}
	while (isEmpty(S) == 1)
	{
		j = pop(S);//���Ϊ0��ջ
		topo[count++] = j;//��ǰ����Ԫ�ز���
		//���¸���iӰ��Ķ������ȣ���iָ��Ķ������ȼ���1��
		for ( p = G.adj[i].firstarc;p; p = p->nextarc)  //�ڽӱ�ĳ��ȣ�λ�ã�����
		{
			int v = p->adjvex;
			//iָ������ж������ȼ�1���ж��Ƿ�Ϊ0,Ϊ0��ջ
			if (--indegree[v])
				push(S, v);
		}
		if (count<G.vernum) //����û��ȫ������
			return false;
		else
			return true; //����ɹ�
	}
}
