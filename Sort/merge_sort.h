#pragma once


int *B = (int *)malloc(n * sizeof(int)); //������������ͬ���ȵĸ���

/*
��·�鲢˼�룺�����������򣻱Ƚ�������ĵ�һ��Ԫ�أ�С����Ϊ���򣬼����Ƚ�
��midΪ�磬�Ӱ��շ���˼�룬��·�鲢����С�ķŵ�ǰ�棻

*/
void merge(int A[], int low, int mid, int high) {
	int i, j, k;  //kΪA�д�����λ�ã�i,jΪ��ǰ�Ƚ������α�
	for ( k = low,j = mid,k = i; i <= mid&&j<=high; k++)
	{
		if (B[i]<=B[j])  //����Сֵ���Ƶ�A�У��������
			A[k] = B[i++];
		else
			A[k] = B[j++];
	}

	while (i <= mid) A[k++] = B[i++]; //���ܳ���һ�����ݱȽ����ˣ���һ��ʣ�����ݣ�ֱ�Ӱ�ʣ�����ݷŵ��������
	while (j <= high) A[k++] = B[j++];
}


/*
�ݹ�ʵ�ַ���
*/
void merge_sort(int A[], int low, int high) {
	if (low<high)
	{
		int mid = (low + high) / 2;
		merge_sort(A, low, mid); //�󲿷�
		merge_sort(A, mid + 1, high);//�Ҳ���
		merge(A, low, mid, high);
	}
}
