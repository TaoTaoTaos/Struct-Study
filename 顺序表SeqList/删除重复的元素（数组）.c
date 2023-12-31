/*
题目要求：删除有序表a和b中相同的结点。

思路：
1. 初始化两个指针，分别指向数组a和b的开始位置。
2. 比较两个指针所指向的元素，如果两个元素相等，则删除元素，并将两个指针都向右移动一位。
3. 如果a[i]小于b[j]，将指针i向右移动一位。
4. 如果a[i]大于b[j]，将指针j向右移动一位。
5. 当一个数组遍历完后，停止操作。

注意：在删除元素时，需要将后面的元素向前移动，以保持数组的连续性。
*/

#include <stdio.h>

void deleteSame(int* a, int* b, int n, int m) {
    int i = 0, j = 0;
    
    // 遍历数组a和b
    while (i < n && j < m) {
        // 如果a[i]等于b[j]，删除a[i]和b[j]，并将两个指针都向右移动一位
        if (a[i] == b[j]) {
            for (int k = i; k < n - 1; k++) {
                a[k] = a[k + 1];
            }
            n--;
            for (int k = j; k < m - 1; k++) {
                b[k] = b[k + 1];
            }
            m--;
        }
        // 如果a[i]小于b[j]，将指针i向右移动一位
        else if (a[i] < b[j]) {
            i++;
        }
        // 如果a[i]大于b[j]，将指针j向右移动一位
        else {
            j++;
        }
    }
}

/*
总结：
本题主要考察了数组的基本操作和双指针技巧。关键在于如何在遍历两个数组的过程中，删除两个数组中相同的元素。
这里的处理方法是：使用两个指针，分别指向数组a和b的开始位置，然后比较两个指针所指向的元素，如果两个元素相等，则删除元素，并将两个指针都向右移动一位。
这样，当遍历完两个数组后，就删除了两个数组中相同的元素。
*/
