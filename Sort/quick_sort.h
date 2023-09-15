#pragma once
//快速排序的实现

//分表实现
int partition(int A[], int low, int high) {
	int pivot = A[0]; //枢轴设置为第一个元素
	while (low<high)
	{
		while (low < high && pivot <= A[high]) --high;
		//需要改变high的位置
		A[low] = A[high];
		//改变low的位置
		while (low < high && pivot > A[low]) --low;
		A[high] = A[low];
	}
	//pivot的最终位置
	A[low] = pivot;
	//返回分表的位置
	return low;
}

//递归实现快速排序
void quick_sort(int A[], int low, int high) {
	//递归结束条件
	if (low>=high)
	{
		return;
	}
	int loc = partition(A, low, high); //分表位置
	//递归方向，减少复杂度，分表
	quick_sort(A, low, loc-1);
	quick_sort(A, loc+1, high);
}