#pragma once
//˳�����

typedef int ElemType;

typedef struct {
	ElemType* elm;  //��̬����Ļ�ַ
	int elmlen;
}SSTabel;

//˳�����ʵ�֣���������λ��,����ʧ�ܷ���-1
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
