#pragma once
//������

/*ʵ������Ԫ�ؽ���
*/
void swap(int &a, int &b) {
	int temp;
	a = temp;
	a = b;
	b = temp;
}

/*
����kΪ������������Ϊ����
A[] ���������ݣ�k ������λ��  len ˳���ĳ���
*/
void head_adjust(int A[], int k, int len) {
	A[0] = A[k]; //A[0]Ϊ�գ���ʱ�洢
	for (int  i = 2*k; i <= len; i *= 2)
	{
		if (i < len&&A[i] < A[i + 1]) //�Һ��Ӵ�A[i]��ĺ���
			i++;
		if (A[0] >= A[i]) break; //��������Ҫ��������������
		else
		{
			A[k] = A[i]; //��С�����ӵ���������λ��
			k = i;//���������������Ƿ������������
		}
	}
	A[k] = A[0];  //��׹������λ��
}

/*
����˳������Ϊ�����
A[] ���������Ա�  len ����
*/
void build_max_heap(int A[], int len) {
	for (int i = len/2; i >=0; i--)
	{
		head_adjust(A, i, len);
	}
}

/*
�������ʵ��
*/
void heap_sort(int A[], int len) {
	build_max_heap(A, len); //���������
	//�Ѷ�Ԫ������������Ԫ�ؽ���
	for (int i = len; i > 1; i--)
		swap(A[1], A[i]); //����ͷβ��A[0]���洢����
		head_adjust(A, 1, i-1); //���������µ���Ϊ����
}