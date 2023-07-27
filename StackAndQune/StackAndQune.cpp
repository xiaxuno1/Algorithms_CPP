// StackAndQune.cpp : 
//栈顺序结构、
/*
ADT Stack
Data
	先进后出
Opration
	init(L):    初始化操作
	isEmpty(L):   若线性表为空，返回ture,否则false
	clearStack(L):   清空
	getTop(L): 返回栈顶
	pop(L,*e):出栈操作
	push(L,e):入栈操作
	length(L):返回长度
	OStack(L)  输出所有的元素
endADT
*/

#include <iostream>
#include "SqStack.h"
#include "DoubleStack.h"
#include "LinkStack.h"
#include "LinkQueue.h"


void testStack() {
    int j;
    SqStack s;
    int e;
    if (init(s) == OK)
        for (j = 1; j <= 10; j++)
            push(s, j);
    printf("栈中元素依次为：");
    OStack(s);
    pop(s, e);
    printf("弹出的栈顶元素 e=%d\n", e);
    printf("栈空否：%d(1:空 0:否)\n", isEmpty(s));
    e = getTop(s);
    printf("栈顶元素 e=%d 栈的长度为%d\n", e, length(s));
    clear(s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n", isEmpty(s));

}

void testSqDoubleStack() {
    int j;
    DoubleStack s;
    int e;
    if (init(s) == OK)
    {
        for (j = 1; j <= 5; j++)
            push(s, j, 1);
        for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
            push(s, j, 2);
    }

    printf("栈中元素依次为：");
    OStack(s);

    printf("当前栈中元素有：%d \n", length(s));

    pop(s, e, 2);
    printf("弹出的栈顶元素 e=%d\n", e);
    printf("栈空否：%d(1:空 0:否)\n", isEmpty(s));

    for (j = 6; j <= MAXSIZE - 2; j++)
        push(s, j, 1);

    printf("栈中元素依次为：");
    OStack(s);

    e = 100;
    printf("栈满否：%d(1:否 0:满)\n", isEmpty(s));
    printf("满栈后插入结果%d \n", push(s, e, 1));


    clear(s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n", isEmpty(s));

}

void testLinkStack() {
    int j;
    LinkStack s;
    int e;
    if (init(s) == OK)
        for (j = 1; j <= 10; j++)
            push(s, j);
    printf("栈中元素依次为：");
    OStack(s);
    pop(s, e);
    printf("弹出的栈顶元素 e=%d\n", e);
    printf("栈空否：%d(1:空 0:否)\n", isEmpty(s));
    clear(s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",isEmpty(s));
}

void testLinkQueue() {
    int i;
    ElemType d;
    LinkQueue q;
    i = init(q);
    if (i)
        printf("成功地构造了一个空队列!\n");
    printf("是否空队列？%d(1:空 0:否)  ", isEmpty(q));
    printf("队列的长度为%d\n", length(q));
    enQueue(q, -5);
    enQueue(q, 5);
    enQueue(q, 10);
    printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", length(q));
    printf("是否空队列？%d(1:空 0:否)  ", isEmpty(q));
    printf("队列的元素依次为：");
    OQueue(q);
    deQueue(q, d);
    printf("删除了队头元素%d\n", d);
    i = getHead(q, d);
    if (i == OK)
        printf("新的队头元素是：%d\n", d);
    clear(q);
    printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
}

int main()
{
    testLinkQueue();
    std::cout << "End \n";
}