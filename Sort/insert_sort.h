#pragma once
//��������ʵ��

/*
ֱ�Ӳ�������ʵ��
�������Ա�
*/
void insert_sort(int A[], int n) {
	int i, j, temp; //i����ǰ����λ�ã�j�����������ǣ�temp�ݴ�,nΪ����
	for (int i = 1; i < n; i++)
	{
		if (A[i]<A[i-1]) //��Ҫ����
		{
			temp = A[i]; //�ݴ棬�Է�iǰ���λ�ú���ʱ����
			for (int j = i-1; j <= 0; j--) //���ƣ�������λ�ý���
			{
				if (temp<A[j])  //����
					return;
				A[j + 1] = A[j]; //����
			}
			A[j + 1] = temp;  //���������λ��
		}
	}
}