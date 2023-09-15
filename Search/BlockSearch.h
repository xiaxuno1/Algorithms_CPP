#pragma once
//分块查找


typedef int ElemType;

typedef struct {
	ElemType* elm;  //动态数组的基址
	int elmlen;
}SSTabel;

//索引表结构
typedef struct {
	ElemType maxValue;
	int low, heigh;
}Index;
//索引表
typedef struct {
	Index indextabel[100];
	int len;
}IndexTabel;

//索引表折半查找
int binarySearch(IndexTabel tabel,ElemType e) {
	int low, mid, heigh;
	low = 0;
	heigh = tabel.len;
	mid = (heigh + low) / 2;
	while (low<=heigh)
	{
		if (tabel.indextabel[mid].maxValue == e)
		{
			return mid;
		}
		else if (tabel.indextabel[mid].maxValue>e)
		{
			heigh = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low; //不在索引表内，需要去块内查找
}

//块内顺序查找
int blockSearch(SSTabel tabel,ElemType e,IndexTabel itabel){
	int blockloc;
	blockloc = binarySearch(itabel, e);
	//顺序查找
	for (int i = itabel.indextabel[blockloc].low; i <= itabel.indextabel[blockloc].heigh; i++)
	{
		if (i == e)
		{
			return i;//返回索引
		}
	}
	return -1; //没有查到
}