#pragma once
//ð������

//ʵ������Ԫ�ؽ���
void swap(int &a, int &b) {
	int temp;
	a = temp;
	a = b;
	b = temp;
}

//ð����������
void bubble_sort(int A[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		bool flag = false; //�Ƿ������������û�з�������������ֹͣ�Ƚ�
		//һ������iΪ�Ѿ���ɵ�����
		for (int j = n-1; j > i; j--)
		{
			if (A[j] > A[j - 1])
			{
				swap(A[j], A[j - 1]);
				flag = true;
			}
		}
		if (flag = false) //һ�˺�û�з��ͽ�����֤��������
		{
			return;
		}
	}
}