#include <stdio.h>
#include <stdlib.h>
/*这段代码的目标是找到数组中未出现过的最小正整数。它首先创建一个新的整数数组B，并将所有元素初始化为0。然后，它遍历原始数组A，如果A中的元素是正整数并且小于等于n，就在B中的对应位置标记为1。接下来，它遍历数组B，找到第一个值为0的元素，这个元素的下标加1就是未出现过的最小正整数。最后，它释放了数组B的内存。这个算法的时间复杂度是O(n)，空间复杂度也是O(n)。*/


int find(int A[], int n){
    int i;
    // 使用malloc分配内存，创建一个大小为n的整数数组B
    int *B = (int*)malloc(n * sizeof(int));
    // 检查内存是否成功分配
    if (B == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }
    // 初始化数组B，将所有元素设置为0
    for (int k = 0; k < n; ++k) B[k] = 0;
    // 遍历数组A
    for (i = 0; i < n; ++i)
        // 如果A[i]是一个在1和n之间的正整数，就在数组B中的对应位置标记为1
        if (A[i] > 0 && A[i] <= n) B[A[i] - 1] = 1;
    // 遍历数组B，找到第一个值为0的元素
    for (i = 0; i < n; ++i) if(B[i] == 0)
        break;
    // 使用free释放内存
    free(B);
    // 返回未出现过的最小正整数，即第一个值为0的元素的下标+1
    return i + 1;
}

int main() {
    // 测试的数组
    int A[] = {3, 4, -1, 1};
    // 数组的大小
    int n = sizeof(A) / sizeof(int);
    // 调用函数find，找到未出现过的最小正整数
    int result = find(A, n);
    // 输出结果
    printf("The smallest missing positive integer is %d.\n", result);
    return 0;
}
