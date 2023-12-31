#include <stdio.h>

// ! 插入排序
// ! 关键：每次抽出一个人来，看要不要把他插入到前面，和打麻将理牌是一样的
// ! 从抽出的那个人的左边开始倒着回去比较
// ! 算法实现需要两个指针， i 在前 ，j 在后 ， 
// 思路和算法原理：
// 插入排序的基本操作就是将一个数据插入到已经排好序的有序数据中，从而得到一个新的、个数加一的有序数据，算法适用于少量数据的排序，时间复杂度为O(n^2)。
//!是稳定的排序方法。
//插入排序要一个一个比较，可以加一个二分查找，来优化他
void insertionSort(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++) //每次挑出一个人，他就开始问左边的人，有没有比我大的，如果真有比他大的，那比他大的都得往后走，然后他自己进去。
    {//! 刚开始 i = 1 ，指向着数组里第二个人
    
    

        key = arr[i]; // 取出待插入的元素，然后他开始喊，问左边有没有大的
        j = i - 1;    //! J = i - 1 ，指向着数组里 i 前面那个 ，也就是第一个

        // 将大于key的元素后移
        while (j >= 0 && arr[j] > key)//当找到比i大的元素时
        {
            arr[j + 1] = arr[j]; //! 大于 i 的开始往后移
            j--;

        }

        arr[j + 1] = key; // 插入元素 //!相当于麻将码到前面
        //! 插入的位置是 j + 1 
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
               //!总大小/单个字符大小==长度
    insertionSort(arr, n);

    printArray(arr, n);

    return 0;
}

// 总结：
// 插入排序是一种简单直观的排序算法，它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
// 关键问题：
//! 1. 如何选择插入的位置？
//!    我们可以从后向前扫描已排序的序列，找到第一个不大于当前元素的位置，然后在该位置后插入当前元素。
//! 2. 如何移动元素？
//!    在从后向前扫描的过程中，我们可以一边扫描一边移动元素，为当前元素腾出空间。
