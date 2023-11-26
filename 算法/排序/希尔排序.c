// 题目要求：在插入排序的基础上，写一个希尔排序，函数分开写

// 思路：希尔排序是插入排序的一种改进版本
// 它通过定义一个间隔序列来改进插入排序，使得在间隔序列的每个间隔处执行一次插入排序。随着间隔序列的递减，数组变得越来越有序，最后当间隔为1时，执行一次插入排序，此时的插入排序效率很高。

#include <stdio.h>

// 插入排序函数
void InsertionSort(int arr[], int start, int end, int gap)
{
    // 遍历每个元素
    for (int i = start + gap; i < end; i = i + gap)
    {
        // 保存当前元素
        int current = arr[i];
        int j = i - gap;
        // 将所有大于当前元素的元素向后移动
        while (j >= start && arr[j] > current)
        {
            arr[j + gap] = arr[j];
            j -= gap;
        }
        // 插入当前元素
        arr[j + gap] = current;
    }
}

// 希尔排序函数
void ShellSort(int arr[], int len)
{
    // 定义间隔序列
    for (int gap = len / 2; gap > 0; gap /= 2)
    {
        // 对每个间隔执行一次插入排序
        for (int i = 0; i < gap; i++)
        {
            InsertionSort(arr, i, len, gap);
        }
    }
}

int main()
{
    // 定义数组
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int len = sizeof(arr) / sizeof(arr[0]);

    // 执行希尔排序
    ShellSort(arr, len);

    // 打印排序后的数组
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// 总结：本题主要考察了希尔排序算法的实现，希尔排序是一种基于插入排序的快速排序算法，通过定义一个间隔序列来改进插入排序，使得在间隔序列的每个间隔处执行一次插入排序。随着间隔序列的递减，数组变得越来越有序，最后当间隔为1时，执行一次插入排序，此时的插入排序效率很高。
// 关键注释：
// 1. "void InsertionSort(int arr[], int start, int end, int gap)": 这是插入排序函数，它在给定的间隔上对数组进行插入排序。
// 2. "void ShellSort(int arr[], int len)": 这是希尔排序函数，它定义了一个间隔序列，并在每个间隔上调用插入排序函数。
// 3. "for (int gap = len / 2; gap > 0; gap /= 2)": 这是定义间隔序列的循环，间隔从数组长度的一半开始，每次减半，直到间隔为1。
// 4. "InsertionSort(arr, i, len, gap)": 这是在每个间隔上调用插入排序函数的代码，它确保了在每个间隔上都执行了一次插入排序。
