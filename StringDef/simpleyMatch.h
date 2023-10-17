#pragma once
#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

constexpr auto MAXSIZE = 100 /* �洢�ռ��ʼ������ */;

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;	/* ElemType���͸���ʵ������������������Ϊint */

typedef struct {

	ElemType data[MAXSIZE];
	int len;
}SString;

//����ģʽƥ��
Status simplyMatch(SString S, SString T, int pos) {
	int i=1, j=1;//λ�ü�¼
	while (j <= T.len && i<=S.len)//ƥ���ϻ���λ�����
	{
		if (S.data[i] == T.data[j]) //ƥ��ʱ��i j����
		{
			++i;
			++j;
		}
		else //��ƥ�䣬i�˻�ƥ�俪ʼλ�õ���һλ�ã�j�˻����
		{
			j = 1;  //��ƥ�䴮��λ��
			i = i-j+2
		}
	}
	if (j> T.len)
	{
		return i - T.len;
	}
	else
	{
		return 0;
	}
}