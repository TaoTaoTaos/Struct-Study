// 冒泡排序

// 思路：冒泡排序是一种简单的排序算法。它重复地遍历要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。遍历数列的工作是重复地进行直到没有再需要交换，也就是说该数列已经排序完成。

#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // 最后i个元素已经有序，无需比较
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // 交换arr[j]和arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

// 总结：本题主要考察了冒泡排序算法的实现。冒泡排序是一种简单的排序算法，它通过重复地遍历数列，比较并交换相邻的元素，从而将最大（或最小）的元素“冒泡”到数列的一端。这个过程会重复进行，直到整个数列都排序完成。
//!关键注释：for (j = 0; j < n-i-1; j++) {...} 这段代码是冒泡排序算法的核心部分，它负责在每次遍历过程中，比较并交换相邻的元素。如果arr[j] > arr[j+1]，则交换这两个元素。这样，每次遍历后，最大的元素都会被移动到数列的末尾。
