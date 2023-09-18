#pragma once


int *B = (int *)malloc(n * sizeof(int)); //与待排序队列相同长度的辅助

/*
二路归并思想：两个表已有序；比较两个表的第一个元素，小的作为排序，继续比较
以mid为界，从按照分治思想，两路归并，将小的放到前面；

*/
void merge(int A[], int low, int mid, int high) {
	int i, j, k;  //k为A中待排序位置，i,j为当前比较数据游标
	for ( k = low,j = mid,k = i; i <= mid&&j<=high; k++)
	{
		if (B[i]<=B[j])  //将较小值复制到A中，排序完成
			A[k] = B[i++];
		else
			A[k] = B[j++];
	}

	while (i <= mid) A[k++] = B[i++]; //可能出现一边数据比较完了，另一边剩余数据；直接把剩余数据放到排序后面
	while (j <= high) A[k++] = B[j++];
}


/*
递归实现分治
*/
void merge_sort(int A[], int low, int high) {
	if (low<high)
	{
		int mid = (low + high) / 2;
		merge_sort(A, low, mid); //左部分
		merge_sort(A, mid + 1, high);//右部分
		merge(A, low, mid, high);
	}
}
