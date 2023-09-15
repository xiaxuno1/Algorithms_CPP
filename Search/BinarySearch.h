#pragma once
//折半查找

typedef int ElemType;

typedef struct {
	ElemType* elm;  //动态数组的基址
	int elmlen;
}SSTabel;

//查找成功返回位置，失败返回-1
int binarySearch(SSTabel tabel,ElemType e) {
	int low, mid, heigh;
	low = 0;
	heigh = tabel.elmlen-1;
	while (low <= heigh) //查找的终点
	{
		mid = (low + heigh) / 2;
		if (tabel.elm[mid] == e) //查找成功
		{
			return mid+1;
		}
		else if(tabel.elm[mid]>e)
		{
			heigh = mid-1; //如果使用mid在满足low+1 = heigh;elm[mid]>e；low和heigh无法移动，陷入死循环
		}
		else
		{
			low = mid+1;
		}
		//查找失败
	}
	return -1;
}