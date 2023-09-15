#pragma once
//堆排序

/*实现两个元素交换
*/
void swap(int &a, int &b) {
	int temp;
	a = temp;
	a = b;
	b = temp;
}

/*
将以k为根的子树调整为根堆
A[] 待调整数据；k 调整的位置  len 顺序表的长度
*/
void head_adjust(int A[], int k, int len) {
	A[0] = A[k]; //A[0]为空，暂时存储
	for (int  i = 2*k; i <= len; i *= 2)
	{
		if (i < len&&A[i] < A[i + 1]) //右孩子大，A[i]大的孩子
			i++;
		if (A[0] >= A[i]) break; //根大，则不需要调整，调整结束
		else
		{
			A[k] = A[i]; //根小，大孩子调整到根的位置
			k = i;//继续检查调整后孩子是否满足根堆特性
		}
	}
	A[k] = A[0];  //下坠的最终位置
}

/*
整个顺序表调整为大根堆
A[] 待调整线性表  len 表长度
*/
void build_max_heap(int A[], int len) {
	for (int i = len/2; i >=0; i--)
	{
		head_adjust(A, i, len);
	}
}

/*
堆排序的实现
*/
void heap_sort(int A[], int len) {
	build_max_heap(A, len); //建立大根堆
	//堆顶元素与待排序最后元素交换
	for (int i = len; i > 1; i--)
		swap(A[1], A[i]); //交换头尾，A[0]不存储数据
		head_adjust(A, 1, i-1); //交换后重新调整为根堆
}