// StringDef.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
ADT String
Data
     零个或多个字符组成的有限序列。一般记为s="a_{1},a_{2},...,a_{n} "  
Opreator
    StrASSign(&T,charS)//赋值操作。把串T赋值为chars。
    StrCopy(&T,S)//复制操作。由串S复制得到串T。
    StrEmpty(S)//判空操作。若S为空串，则返回TRUE，否则返回FALSE。
    StrLength(S)//求串长。返回串S的元素个数。
    ClearString(&S)//清空操作。将S清为空串。
    DestroyString(&S)//销毁串。将串S销毁（回收存储空间）。
    Concat(&T,S1,S2)//串联接。用T返回由S1和S2联接而成的新串
    SubString(&Sub,S,pos,len)//求子串。用Sub返回串S的第pos个字符起长度为len的子串。
    Index(S,Sub)//定位操作。若主串S中存在与串Sub值相同的子串，则返回它在主串S中第一次出现的位置;否则函数值为0。
    StrCompare(S,T)//比较操作。若S>T，则返回值>O;若S=T，则返回值=0;若S<T，则返回值<O。
endADT
*/

#include <iostream>
#include "KMP.h"

int main()
{
    const string T = "google";  //定义字符串常量
    string S = "googloglooggooglegoogoo";
    //一维数组声明时，长度必须为常量，不能在运行时确定，因此报错
    //int next_[T.size()];
    int index = index_KMP(S, T);
    cout << "匹配到的索引为：" << index<<endl;

}
