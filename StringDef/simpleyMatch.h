#pragma once
#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

constexpr auto MAXSIZE = 100 /* 存储空间初始分配量 */;

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;	/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct {

	ElemType data[MAXSIZE];
	int len;
}SString;

//朴素模式匹配
Status simplyMatch(SString S, SString T, int pos) {
	int i=1, j=1;//位置记录
	while (j <= T.len && i<=S.len)//匹配上或者位置溢出
	{
		if (S.data[i] == T.data[j]) //匹配时，i j后移
		{
			++i;
			++j;
		}
		else //不匹配，i退回匹配开始位置的下一位置，j退回起点
		{
			j = 1;  //待匹配串的位置
			i = i-j+2
		}
	}
	if (j> T.len)
	{
		return i - T.len;
	}
	else
	{
		return 0;
	}
}