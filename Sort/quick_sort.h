#pragma once
//���������ʵ��

//�ֱ�ʵ��
int partition(int A[], int low, int high) {
	int pivot = A[0]; //��������Ϊ��һ��Ԫ��
	while (low<high)
	{
		while (low < high && pivot <= A[high]) --high;
		//��Ҫ�ı�high��λ��
		A[low] = A[high];
		//�ı�low��λ��
		while (low < high && pivot > A[low]) --low;
		A[high] = A[low];
	}
	//pivot������λ��
	A[low] = pivot;
	//���طֱ��λ��
	return low;
}

//�ݹ�ʵ�ֿ�������
void quick_sort(int A[], int low, int high) {
	//�ݹ��������
	if (low>=high)
	{
		return;
	}
	int loc = partition(A, low, high); //�ֱ�λ��
	//�ݹ鷽�򣬼��ٸ��Ӷȣ��ֱ�
	quick_sort(A, low, loc-1);
	quick_sort(A, loc+1, high);
}