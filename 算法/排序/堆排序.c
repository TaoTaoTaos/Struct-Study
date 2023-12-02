// 题目要求：实现堆排序

// 思路：堆排序是一种基于二叉堆的比较排序算法。它可以被看做是选择排序的一种改进，利用了二叉堆的性质来改进选择排序在数据量大时的效率。堆排序的主要步骤是建堆和调整堆。
//! 大根堆 就是把最大的放到最上面 ，左右的都比他小，左右子树顺序无所谓 
//! 每次排好一次大根堆 ，即筛选了个最大的排到最后。
//! 利用了树的逻辑结构 ，但是操作的对象是数组 ， 最后排序成了一个递增的数组
//! 关键是每一次都保持住大根堆的结构
#include <stdio.h>

// 调整堆
//!保证根 > 左右，且 最大的应该是 i
void Heapify(int arr[], int i, int size)
{
    int largest = i;
    int left  = 2 * i + 1; //! 2i + 1 是左子树
    int right = 2 * i + 2; //! 2i + 2 是右子树

    // 如果左子节点大于根节点
    if (left < size  //! 先要保证 2i + 1 ,2 没有超出范围
            &&  arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于根节点
    if (right < size && arr[right] > arr[largest])
        largest = right;

    
    if (largest != i)
    //!如果最大节点不是我们一开始设定的当前节点，说明我们需要调整堆。
    {
        int temp = arr[i];
        arr[i]   = arr[largest];
        arr[largest] = temp;

        // 递归调整子堆
        Heapify(arr, largest, size);
    }
}

// 堆排序函数
void HeapSort(int arr[], int size)
{
    //! 从最后一个分支节点开始，向上调整堆
    //! 先把个最大的放到最头上
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, i, size);
    }

    //! 把堆顶的元素（最大的） 与最后一个元素互换，下一次这个最大的数据就不动了（i--）
    //! 最后把堆恢复！
    for (int i = size - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        Heapify(arr, 0, i);
    }
}

int main()
{
    // 定义数组
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // 执行堆排序
    HeapSort(arr, size);

    // 打印排序后的数组
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// 总结：本题主要考察了堆排序算法的实现，堆排序是一种基于二叉堆的比较排序算法。它可以被看做是选择排序的一种改进，利用了二叉堆的性质来改进选择排序在数据量大时的效率。堆排序的主要步骤是建堆和调整堆。
// 关键注释：
// 1. "void Heapify(int arr[], int i, int size)": 这是调整堆的函数，它确保父节点、左子节点和右子节点满足堆的性质。
// 2. "void HeapSort(int arr[], int size)": 这是堆排序函数，它首先构建一个堆，然后不断地交换堆顶元素和最后一个元素，并调整堆。
// 3. "for (int i = size / 2 - 1; i >= 0; i--)": 这是构建堆的循环，从最后一个非叶子节点开始，向上调整堆。
// 4. "Heapify(arr, 0, i)": 这是在每次交换堆顶元素和最后一个元素后，调整堆的代码，它确保新的堆顶元素满足堆的性质。
