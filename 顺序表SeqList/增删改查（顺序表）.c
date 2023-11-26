//!  SeqList
// 题目要求：实现线性表的基本操作，包括初始化、插入、删除和查找。

// 使用数组来实现线性表，数组的索引作为线性表的位置。

#include <stdio.h>

#define MAX_SIZE 100 // 定义线性表的最大长度

// 定义线性表的数据结构
typedef struct SeqList
{

    int data[MAX_SIZE]; // 存储数据元素
    int length;         // 线性表的当前长度

} SeqList;

//! 初始化线性表
void InitList(SeqList *L)
{
    L->length = 0; // 初始化长度为0
}

//!  在线性表的第i个位置插入元素e
void ListInsert(SeqList *L, int i, int e)
{
    if (L->length == MAX_SIZE)
    { // 如果线性表已满，无法插入
        return;
    }
    if (i < 1 || i > L->length + 1)
    { // 如果插入位置不合法
        return;
    }
    for (int j = L->length; j >= i; j--)
    {                                      //!  将第i个位置及之后的元素后移
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e; //!        后移完了然后在位置i处插入e
    L->length++;        //!        记得线性表长度加1
}

//!  删除线性表的第i个元素
void ListDelete(SeqList *L, int i)
{
    if (i < 1 || i > L->length)
    { // 如果删除位置不合法
        return;
    }
    for (int j = i; j < L->length; j++)
    { // 将第i个位置之后的元素前移
        L->data[j - 1] = L->data[j];
    }
    L->length--; // 线性表长度减1
}

//! 查找元素e在线性表中的位置
int LocateElem(SeqList *L, int e)
{
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1; // 返回第一个值为e的元素的位置
        }
    }
    return 0; // 如果找不到，返回0
}

int main()
{
    SeqList L;    // 创建一个线性表
    InitList(&L); // 初始化线性表

    ListInsert(&L, 2, 20); // 在第2个位置插入20

    ListDelete(&L, 1); // 删除第1个元素

    int pos = LocateElem(&L, 20); // 查找20在线性表中的位置

    printf("The position of 20 is %d\n", pos);
    return 0;
}

//! 总结
// 本题主要考察了线性表的基本操作，包括初始化、插入、删除和查找。线性表是一种基本的数据结构，对其进行操作是数据结构和算法学习的基础。
// 本题中，我们使用数组来实现线性表，数组的索引作为线性表的位置。在插入和删除操作中，需要对数组进行移动操作，以保持线性表的连续性。
// 查找操作则是遍历数组，找到第一个值为给定值的元素的位置。
// 通过本题，我们可以理解线性表的基本概念和操作，为学习更复杂的数据结构打下基础。
