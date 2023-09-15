#pragma once
//顺序查找

typedef int ElemType;

typedef struct {
	ElemType* elm;  //动态数组的基址
	int elmlen;
}SSTabel;

//顺序查找实现，返回索引位置,查找失败返回-1
int searchSeq(SSTabel &tabel,ElemType e){
	for (int i = 0; i < tabel.elmlen; i++)
	{
		if (e == tabel.elm[i])
		{
			return i;
		}
	}
	return -1;
}
