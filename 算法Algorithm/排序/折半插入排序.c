#include <stdio.h>

// 题目要求：
// 实现折半插入排序

// 思路和算法原理：
// 折半插入排序是对插入排序的一种改进，
// 它的基本思想是：在将一个新元素插入已经排好序的数组的过程中
//! 采用二分查找法寻找新元素的插入位置，从而减少比较次数。

void binaryInsertionSort(int arr[], int n)
{
    int i, j, key, low, high, mid;
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // 取出待插入的元素
        low = 0;
        high = i - 1;
        //! 使用二分查找法找到插入位置
        while (low <= high)        //! 直到low > high
        {
            mid = (low + high) / 2;
            if (arr[mid] > key)
                high = mid - 1;
            else
                low = mid + 1; //!这一步是与二分查找有区别的地方
        }
        // 将大于key的元素后移
        for (j = i - 1; j >= high + 1; j--)
            arr[j + 1] = arr[j];
        // 插入元素
        arr[high + 1] = key;
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

    binaryInsertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

// 总结：
// 折半插入排序是一种改进的插入排序，
//!它的主要优点是减少了比较次数，从而提高了排序效率。
//!但是元素的移动次数并没有减少，所以对于大规模数据的排序，折半插入排序并不是最优选择。
// 关键问题：
//! 1. 如何选择插入的位置？
//!    我们可以使用二分查找法在已排序的序列中找到插入位置，这样可以减少比较次数。
//! 2. 如何移动元素？
//!    在找到插入位置后，我们需要将插入位置后的所有元素后移一位，为新元素腾出空间。这一步的时间复杂度是O(n)，所以总的时间复杂度仍然是O(n^2)。
