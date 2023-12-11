// 题目要求：使用折半查找来找到目标值所在的块

// 思路：
//!1. 首先，假设目标数组是有序的（如果不是，需要先进行排序）。
// 2. 然后，将数组分为若干个块，并对每个块的最大值进行索引。
// 3. 使用折半查找在索引表中找到目标值所在的块。
// 4. 在找到的块中使用折半查找来查找目标值。

#include <stdio.h>

// 折半查找函数，参数为目标数组、数组长度和目标值
int binarySearch(int arr[], int len, int target)
{
    // 定义左右边界
    int left = 0, right = len - 1;

    // 当左边界小于等于右边界时，继续查找
    while (left <= right)
    {
        // 计算中间位置
        int mid = left + (right - left) / 2;

        // 如果找到目标值，返回索引
        if (arr[mid] == target)
        {
            return mid;
        }
        // 如果目标值小于中间元素，查找左半部分
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        // 如果目标值大于中间元素，查找右半部分
        else
        {
            left = mid + 1;
        }
    }

    //! 如果没有找到，返回left
    return left;
}

// 分块查找函数，参数为目标数组、数组长度、块大小和目标值
int blockSearch(int arr[], int len, int blockSize, int target)
{
    // 计算块的数量
    int blockCount = (len + blockSize - 1) / blockSize;

    // 创建索引表
    int indexTable[blockCount];

    // 填充索引表
    for (int i = 0; i < blockCount; i++)
    {
        int blockStart = i * blockSize;
        int blockEnd = blockStart + blockSize - 1;
        if (blockEnd >= len)
        {
            blockEnd = len - 1;
        }

        // 找到块的最大值
        int maxVal = arr[blockStart];
        for (int j = blockStart + 1; j <= blockEnd; j++)
        {
            if (arr[j] > maxVal)
            {
                maxVal = arr[j];
            }
        }

        // 将块的最大值添加到索引表
        indexTable[i] = maxVal;
    }

    // 在索引表中使用折半查找来找到目标值所在的块
    int blockIndex = binarySearch(indexTable, blockCount, target);

    // 在找到的块中使用折半查找来查找目标值
    int blockStart = blockIndex * blockSize;
    int blockEnd = blockStart + blockSize - 1;
    if (blockEnd >= len)
    {
        blockEnd = len - 1;
    }

    return binarySearch(arr + blockStart, blockEnd - blockStart + 1, target);
}

int main()
{
    // 测试数组
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 数组长度
    int len = sizeof(arr) / sizeof(arr[0]);
    // 块大小
    int blockSize = 3;
    // 目标值
    int target = 5;

    // 调用分块查找函数
    int index = blockSearch(arr, len, blockSize, target);

    // 打印结果
    if (index != -1)
    {
        printf("找到目标值%d，索引为%d\n", target, index);
    }
    else
    {
        printf("未找到目标值%d\n", target);
    }

    return 0;
}

// 总结：
// 本题考察的是分块查找算法的实现。分块查找是一种将顺序查找和折半查找结合起来的查找算法，它的基本思想是先确定目标值所在的块，然后在该块中进行查找。
// 本题的关键是理解分块查找的基本思想，并能够正确地在代码中实现这一思想。
// 1. 分块查找的时间复杂度为O(sqrt(n))，其中n为数组的长度。这是因为首先需要遍历索引表来确定目标值所在的块，然后在该块中进行查找。
// 2. 分块查找要求数组是有序的，这是它与顺序查找的一个重要区别。
// 3. 在实现分块查找的代码时，需要注意边界条件的处理，例如当目标值不在数组中时，应返回一个特殊的值（如-1）来表示查找失败。
// 4. 分块查找的实现中，需要先创建并填充索引表，然后在索引表中找到目标值所在的块，最后在该块中使用折半查找来查找目标值。
