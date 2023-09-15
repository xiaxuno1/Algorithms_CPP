#pragma once
//

void shell_sort(int A[], int n) {
	int d, i, j; //d表示增量，A[0]不放数据作为直接插入的temp存放临时数据
	for (d = n/2; d >=1; d = d/2) //步长
	{
		//按照步长分表，将每个表按照直接插入排序;一个分表的一个元素排序完成后切换到另一个分表；来会切换
		for (i = d+1; i <=n; ++i)
		{
			if (A[i]<A[i-d])//需要移动，将i-d移动到i
			{
				A[0] = A[i]; //暂存A[i],防止被覆盖
				for ( j =i-d ; j >0&& A[0]<A[j]; j= j-d) //比较前面的元素
				{
					A[j + d] = A[j];//后移
				}
				A[j+d] = A[0];//插入适合位置
			}
		}
	}
}
