#pragma once
//�۰����

typedef int ElemType;

typedef struct {
	ElemType* elm;  //��̬����Ļ�ַ
	int elmlen;
}SSTabel;

//���ҳɹ�����λ�ã�ʧ�ܷ���-1
int binarySearch(SSTabel tabel,ElemType e) {
	int low, mid, heigh;
	low = 0;
	heigh = tabel.elmlen-1;
	while (low <= heigh) //���ҵ��յ�
	{
		mid = (low + heigh) / 2;
		if (tabel.elm[mid] == e) //���ҳɹ�
		{
			return mid+1;
		}
		else if(tabel.elm[mid]>e)
		{
			heigh = mid-1; //���ʹ��mid������low+1 = heigh;elm[mid]>e��low��heigh�޷��ƶ���������ѭ��
		}
		else
		{
			low = mid+1;
		}
		//����ʧ��
	}
	return -1;
}