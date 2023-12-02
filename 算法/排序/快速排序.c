// 题目要求：实现一个快速排序算法
// 思路：快速排序是一种分而治之的排序算法，它将一个数组分为两个子数组，然后对这两个子数组进行递归排序。
//!快速排序是不稳定的

#include <stdio.h>

// 分区操作
int Partition(int A[], int low, int high)
{
    int pivot = A[low]; // 第一个元素作为枢轴
    //! 把小于pivot的放左边 ，大于pivot 的放右边
    while (low < high)
    { // 用low、high搜索枢轴的最终位置
        while (low < high && A[high] >= pivot)
            --high;       // 如果当前元素大于等于枢轴，high向左移动
        A[low] = A[high]; // 比枢轴小的元素移动到左端

        while (low < high && A[low] <= pivot)
        {
            ++low;        // 如果当前元素小于等于枢轴，low向右移动
        A[high] = A[low]; // 比枢轴大的元素移动到右端
        }
    }

    A[low] = pivot; // 枢轴元素存放到最终位置
    return low;     // 返回存放枢轴的最终位置
}

// 快速排序
void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivot = Partition(A, low, high); // 对数组进行分区操作
        QuickSort(A, low, pivot - 1);        // 对左子数组进行快速排序
        QuickSort(A, pivot + 1, high);       // 对右子数组进行快速排序
    }
}

int main()
{
    int A[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int n = sizeof(A) / sizeof(int);

    QuickSort(A, 0, n - 1);//!一开始low 是 0 high 是n-1

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}

// 总结：这个问题主要考察了快速排序算法的实现。关键在于理解如何通过分区操作和递归来实现排序。
// //!关键：QuickSort(A, low, pivot - 1); 和 QuickSort(A, pivot + 1, high);
// 这两行代码是快速排序的关键，它们通过递归调用来对子数组进行排序。


//! 1. 快速排序是一种高效的排序算法，它的基本思想是通过一趟排序将待排记录分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，然后分别对这两部分记录继续进行排序，以达到整个序列有序。
//! 2. 快速排序的关键在于partition操作，我们需要选取一个基准元素，然后将数组分为两部分，使得一部分的所有元素都小于基准元素，而另一部分的所有元素都大于基准元素，然后对这两部分再分别进行快速排序。
//! 3. 在实现过程中，我们通常采用in-place排序（即在原始数组上直接进行排序），不需要额外的存储空间。
//! 4. 快速排序的时间复杂度为O(n log n)，但是在最坏的情况下，时间复杂度可能会退化到O(n^2)，这通常发生在待排序序列已经部分有序的情况下。
