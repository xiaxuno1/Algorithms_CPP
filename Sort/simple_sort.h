#pragma once
//


void select_sort(int A[], int n) {
	int i,j;//������ɵ�λ��
	for (i = 0; i < n-1; i++)
	{
		int min = i; //��¼����ʱ����Сֵλ�ã���ʼ����������ʼλ��
		for (j = i+1; j <n; j++)
		{
			if (A[min] > A[j])
				min = j;
		}
		if (min != i) //��Ҫ����λ��
			swap(A[min], A[i]);
	}
}

//ʵ������Ԫ�ؽ���
void swap(int &a, int &b) {
	int temp;
	a = temp;
	a = b;
	b = temp;
}
