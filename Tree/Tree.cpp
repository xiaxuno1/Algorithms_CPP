// Tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
ADT Tree
Data 
    只有一个根结点和m(m>=0)的互不相交有限集组成
Opreator
    init() //初始化一棵树
    createBiT() //创造一个二叉树
    clear() //清空
    isEmpty()  //是否为空
    assign()  //赋值
    depthBiT()  //返回树的深度
    rootBiT() //树的根结点
    parent() //父结点
    lChild() //左孩子
    rChild() //右孩子
    preOderTraverse() //前序遍历
    inOrderTraverse() //中序遍历
    postOrderTraverse() //后续遍历
    leverOrderTraverse() //层序遍历
*/

#include <iostream>
#include "SqBitree.h"

void testSqBiTree() {
    Status i;
    TElemType e;
    SqBiTree T;
    init(T);
    createBiTree(T);
    printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", isEmpty(T), depthBiT(T));
    i = rootBiT(T,e);
    if (i)
        printf("二叉树的根为：%d\n", e);
    else
        printf("树空，无根\n");
    e = 10;
    printf("结点%d的双亲为%d,左右孩子分别为 %d %d", e, parent(T, e),lChild(T,e),rChild(T,e));

}


int main()
{
    testSqBiTree();
    std::cout << "End!\n";
}
