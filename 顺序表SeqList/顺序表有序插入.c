/*
题目要求：
在一个递增有序的顺序表中插入一个元素x，使得插入后的顺序表仍然是递增有序的。

思路和算法原理：
我们可以遍历顺序表，找到第一个大于x的元素的位置，然后把这个位置及其后面的所有元素都向后移动一位，最后在这个位置插入x。

以下是具体的C语言实现：
*/

#include <stdio.h>

// 定义顺序表的结构体
typedef struct
{
    int *data;    // 数据数组
    int length;   // 当前长度
    int capacity; // 最大容量
} SeqList;

// 初始化顺序表
SeqList *initSeqList(int capacity)
{
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    list->data = (int *)malloc(sizeof(int) * capacity);
    list->length = 0;
    list->capacity = capacity;
    return list;
}

// 在顺序表中插入元素的函数
void insert(SeqList *list, int x)
{
    if (list->length == list->capacity)
    { // 如果顺序表已满，返回错误信息
        printf("Error: the sequence list is full.\n");
        return;
    }
    int i;
    for (i = 0; i < list->length; i++)
    { // 找到第一个大于x的元素的位置
        if (list->data[i] > x)
        {
            break;
        }
    }
    for (int j = list->length; j > i; j--)
    { // 把这个位置及其后面的所有元素都向后移动一位
        list->data[j] = list->data[j - 1];
    }
    list->data[i] = x; // 在这个位置插入x
    list->length++;    // 长度加1
}

int main()
{
    SeqList *list = initSeqList(100); // 初始化顺序表
    // 插入测试数据
    list->data[0] = 1;
    list->data[1] = 2;
    list->data[2] = 4;
    list->data[3] = 5;
    list->length = 4;
    // 插入元素3
    insert(list, 3);
    // 输出插入后的顺序表
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    return 0;
}

/*
总结：
这个题目考察的是顺序表的基本操作和性质。顺序表是一种线性数据结构，可以通过下标直接访问元素。插入元素时需要保持顺序表的有序性。

关键问题：
//! 1. 如何找到插入的位置？
我们可以遍历顺序表，找到第一个大于x的元素的位置，这就是需要插入的位置。

//! 2. 如何插入元素？
我们需要把插入位置及其后面的所有元素都向后移动一位，然后在这个位置插入x。注意，如果顺序表已满，需要返回错误信息。
*/
