#pragma once
//插入排序实现

/*
直接插入排序实现
接收线性表
*/
void insert_sort(int A[], int n) {
	int i, j, temp; //i代表当前排序位置，j代表已排序标记，temp暂存,n为长度
	for (int i = 1; i < n; i++)
	{
		if (A[i]<A[i-1]) //需要排序
		{
			temp = A[i]; //暂存，以防i前面的位置后移时覆盖
			for (int j = i-1; j <= 0; j--) //后移，找排序位置交换
			{
				if (temp<A[j])  //结束
					return;
				A[j + 1] = A[j]; //后移
			}
			A[j + 1] = temp;  //插入排序后位置
		}
	}
}