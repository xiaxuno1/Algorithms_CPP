#pragma once
#include <string>
using namespace std;

//KMP�ĸĽ�

//��ȡģʽ����next[],����ǰ��׺����+1
void get_next(string S, int next[]) {
	int i=1, j=0;
	next[1] = 0;
	while (i<S.size())
	{
		if (j == 0 || S[i] == S[j]) {
			++i, ++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}

void get_nextval(string S,int get_next[], int nextval[]) {
	nextval[1] = 0;
	for (int j = 2; j <= S.size(); j++)
	{
		if (S[get_next[j]] == S[j])
		{
			nextval[j] = nextval[get_next[j]];
		}
		else
		{
			nextval[j] = get_next[j];
		}
	}
}

int index_KMP(string S, string const T) {
	int i=1, j=1;
	//ʹ�ö�̬�����ڴ棬�����ֶ��ͷ�
	int* next = new int[T.size()+1];
	get_next(T, next);
	while (i <= S.size()&& j<=T.size())
	{
		if (j == 0 || S[i] == T[j]) {
			++j, ++i;
		}
		else
		{
 			j = next[j]; //û��ƥ��ʱ�����ػ���λ��
		}
	}
	delete[]next;//�ͷ��ڴ�
	next = NULL;
	if (j > T.size())
		return i - T.size(); //ƥ��ɹ�������λ��
	else
	{
		return 0;
	}
}
