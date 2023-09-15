#pragma once
//冒泡排序

//实现两个元素交换
void swap(int &a, int &b) {
	int temp;
	a = temp;
	a = b;
	b = temp;
}

//冒泡排序，升序
void bubble_sort(int A[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		bool flag = false; //是否发生交换，如果没有发生过交换，则停止比较
		//一趟排序，i为已经完成的排序
		for (int j = n-1; j > i; j--)
		{
			if (A[j] > A[j - 1])
			{
				swap(A[j], A[j - 1]);
				flag = true;
			}
		}
		if (flag = false) //一趟后没有发送交换，证明已有序
		{
			return;
		}
	}
}