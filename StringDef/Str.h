#pragma once
#include <stdio.h>
#include <string>

constexpr auto MAXSIZE = 100;

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;	/* ElemType���͸���ʵ������������������Ϊint */
typedef char String[MAXSIZE + 1]; //һ��λ�ô�ų���

//����һ����ֵ����chars�Ĵ�T
Status strAssign(String T, char* chars) {
	int i;
	if (strlen(chars)>MAXSIZE)
	{
		return 0;
	}
	else
	{
		T[0] = strlen(chars);
		for ( i = 0; i <=T[0]; i++)
		{
			T[i] = *(chars + i - 1);
		}
		return 1;
	}
}

//��S���Ƶ�T
Status strCopy(String T, String S)
{
	int i;
	for ( i = 0; i <= S[0]; i++)
	{
		T[i] = S[i];
	}
	return 1;
}

//��SΪ�մ�,�򷵻�TRUE,���򷵻�FALSE
Status isEmpty(String S) {
	if (S[0]==0)
	{
		return 0;
	}
	else
	{
		return false;
	}
}

//�������: ��S>T,�򷵻�ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0 
int strCompare(String S, String T) {
	int i;
	for ( i = 1; i <= S[0]&&i<=T[0]; i++)
	{
		if(S[i]!=T[i])
			return S[i]-T[i]
	}
	return S[0] - T[0];
}

//���ش���Ԫ�ظ���
int strlength(String S) {
	return S[0];
}

//��ʼ����:��S���ڡ��������:��S��Ϊ�մ�
Status clear(String S) {
	S[0] = 0;
	return 1;
}

//��T����S1��S2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE
Status concat(String T, String S1, String S2)
{
	int i;
	if (S1[0] + S2[0] <= MAXSIZE)
	{ /*  δ�ض� */
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= S2[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = S1[0] + S2[0];
		return TRUE;
	}
	else
	{ /*  �ض�S2 */
		for (i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (i = 1; i <= MAXSIZE - S1[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = MAXSIZE;
		return FALSE;
	}
}

/* ��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ��� */
Status SubString(String Sub, String S, int pos, int len)
{
	int i;
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1)
		return ERROR;
	for (i = 1; i <= len; i++)
		Sub[i] = S[pos + i - 1];
	Sub[0] = len;
	return OK;
}

/* ����,T�ǿ�,1��pos��StrLength(S)�� */
int Index(String S, String T, int pos)
{
	int i = pos;	/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;				/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (S[i] == T[j]) 	/* ����ĸ�������� */
		{
			++i;
			++j;
		}
		else 				/* ָ��������¿�ʼƥ�� */
		{
			i = i - j + 2;		/* i�˻ص��ϴ�ƥ����λ����һλ */
			j = 1; 			/* j�˻ص��Ӵ�T����λ */
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

/*  �������: �ڴ�S�ĵ�pos���ַ�֮ǰ���봮T����ȫ���뷵��TRUE,���ֲ��뷵��FALSE */
Status StrInsert(String S, int pos, String T)
{
	int i;
	if (pos<1 || pos>S[0] + 1)
		return ERROR;
	if (S[0] + T[0] <= MAXSIZE)
	{ /*  ��ȫ���� */
		for (i = S[0]; i >= pos; i--)
			S[i + T[0]] = S[i];
		for (i = pos; i < pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] = S[0] + T[0];
		return TRUE;
	}
	else
	{ /*  ���ֲ��� */
		for (i = MAXSIZE; i <= pos; i--)
			S[i] = S[i - T[0]];
		for (i = pos; i < pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] = MAXSIZE;
		return FALSE;
	}
}

/*  ��ʼ����: ��S����,1��pos��StrLength(S)-len+1 */
/*  �������: �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ� */
Status StrDelete(String S, int pos, int len)
{
	int i;
	if (pos<1 || pos>S[0] - len + 1 || len < 0)
		return ERROR;
	for (i = pos + len; i <= S[0]; i++)
		S[i - len] = S[i];
	S[0] -= len;
	return OK;
}

/*  ��ʼ����: ��S,T��V����,T�Ƿǿմ����˺����봮�Ĵ洢�ṹ�޹أ� */
/*  �������: ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ� */
Status Replace(String S, String T, String V)
{
	int i = 1; /*  �Ӵ�S�ĵ�һ���ַ�����Ҵ�T */
	if (StrEmpty(T)) /*  T�ǿմ� */
		return ERROR;
	do
	{
		i = Index(S, T, i); /*  ���iΪ����һ��i֮���ҵ����Ӵ�T��λ�� */
		if (i) /*  ��S�д��ڴ�T */
		{
			StrDelete(S, i, StrLength(T)); /*  ɾ���ô�T */
			StrInsert(S, i, V); /*  ��ԭ��T��λ�ò��봮V */
			i += StrLength(V); /*  �ڲ���Ĵ�V����������Ҵ�T */
		}
	} while (i);
	return OK;
}

/*  ����ַ���T */
void StrPrint(String T)
{
	int i;
	for (i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");
}
