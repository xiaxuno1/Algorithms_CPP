#pragma once
//


void select_sort(int A[], int n) {
	int i,j;//排序完成的位置
	for (i = 0; i < n-1; i++)
	{
		int min = i; //记录排序时的最小值位置，初始化在排序起始位置
		for (j = i+1; j <n; j++)
		{
			if (A[min] > A[j])
				min = j;
		}
		if (min != i) //需要交换位置
			swap(A[min], A[i]);
	}
}

//实现两个元素交换
void swap(int &a, int &b) {
	int temp;
	a = temp;
	a = b;
	b = temp;
}
