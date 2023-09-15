#pragma once
//�ֿ����


typedef int ElemType;

typedef struct {
	ElemType* elm;  //��̬����Ļ�ַ
	int elmlen;
}SSTabel;

//������ṹ
typedef struct {
	ElemType maxValue;
	int low, heigh;
}Index;
//������
typedef struct {
	Index indextabel[100];
	int len;
}IndexTabel;

//�������۰����
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
	return low; //�����������ڣ���Ҫȥ���ڲ���
}

//����˳�����
int blockSearch(SSTabel tabel,ElemType e,IndexTabel itabel){
	int blockloc;
	blockloc = binarySearch(itabel, e);
	//˳�����
	for (int i = itabel.indextabel[blockloc].low; i <= itabel.indextabel[blockloc].heigh; i++)
	{
		if (i == e)
		{
			return i;//��������
		}
	}
	return -1; //û�в鵽
}