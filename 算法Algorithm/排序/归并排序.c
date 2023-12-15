#include <stdio.h>
#include <stdlib.h>

// 题目要求：利用辅助队列，进行归并排序
// 思路：归并排序是一种分治算法。首先将数组分成两半，然后对每一半进行排序，最后将排序好的两半进行合并。
//!关键: 第一：创建一个Merge函数，他只管排有序的
//!      第二：创建MergeSort 函数 ，他是递归调用的
//!      第三：两个函数都非常需要 low  mid  high 的值 

// 辅助数组B
int *B;

// 作用是 A[low...mid]和A[mid+1...high]各自有序，将两个部分归并
void Merge(int A[], int low, int mid, int high)//!Merge：我来合并有序的两个人

{
    int i, j, k;
    for (k = low; k <= high; k++)
        B[k] = A[k]; //!  将A中所有元素复制到新数组B中
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)//!准备覆写A
    {
        if (B[i] <= B[j])//! 先考虑 i ，这样就保证了算法的稳定性
            A[k] = B[i++]; // 将较小值复制到A中
        else
            A[k] = B[j++];
    }
    while (i <= mid)
        A[k++] = B[i++]; // 如果左半部分还有剩余元素，将它们复制回A中
    while (j <= high)
        A[k++] = B[j++]; // 如果右半部分还有剩余元素，将它们复制回A中
}

void MergeSort(int A[], int low, int high)//!mergesort是递归调用的
{
    if (low < high)
    {
        int mid = (low + high) / 2;   // 从中间划分 
                   //!low high 一开始是 0 到 数组长度
        MergeSort (A, low, mid);      // 对左半部分归并排序
        MergeSort (A, mid + 1, high); // 对右半部分归并排序
        Merge(A, low, mid, high);     // !每一次都要归并
        //!每次合并的都是相邻的分区
    }
}

// 测试代码
int main()
{
    int A[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);

    B = (int *)malloc(n * sizeof(int)); // 分配辅助数组B的空间

    printf("给定的数组是 \n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    MergeSort(A, 0, n - 1);

    printf("\n排序后的数组是 \n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(B); // 释放辅助数组B的空间

    return 0;
}

// 总结：归并排序是一种稳定的排序算法，其时间复杂度为O(n log n)。它的主要思想是将数组分成两部分，分别进行排序，然后合并这两部分。
// 关键注释：
// 1. Merge函数：这个函数是归并排序的核心，它负责合并两个已排序的子数组。这个函数首先创建两个临时数组，然后将原数组的元素复制到这两个临时数组中。然后，它将这两个临时数组的元素按照顺序合并回原数组。
// 2. MergeSort函数：这个函数是归并排序的主函数，它负责将数组分成两部分，并对每一部分进行排序。然后，它调用Merge函数来合并这两个已排序的部分。
// 3. main函数：这个函数是程序的入口点。它首先创建一个数组和一个辅助数组，然后调用MergeSort函数对数组进行排序，最后打印排序后的数组。
