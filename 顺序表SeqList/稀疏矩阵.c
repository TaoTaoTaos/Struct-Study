// 题目要求：实现稀疏矩阵的三元组表示法
// 思路和算法原理：
// 对于一个m*n的稀疏矩阵，我们只需要存储非零的元素即可。
// 我们可以使用一个二维数组来存储这些元素，数组的行数为非零元素的个数+1，列数为3。
// 数组的第一行存储矩阵的行数、列数和非零元素的个数。
// 数组的其他行存储非零元素的行索引、列索引和值。

#include <stdio.h>

// 定义最大非零元素的个数
#define MAX_SIZE 100

// !定义三元组
typedef struct {
    int i, j; // 行索引和列索引
    int e; // 元素的值
} Triple;

// !定义稀疏矩阵
typedef struct {
    Triple data[MAX_SIZE+1]; // 存储非零元素的三元组
    int m, n, num; // 矩阵的行数、列数和非零元素的个数
} TSMatrix;

// 创建稀疏矩阵
void createMatrix(TSMatrix *M, int a[][4], int m, int n) {
    M->m = m;
    M->n = n;
    M->num = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                M->data[M->num].i = i;
                M->data[M->num].j = j;
                M->data[M->num].e = a[i][j];
                M->num++;
            }
        }
    }
}

int main() {
    // 定义一个4*4的稀疏矩阵
    int a[4][4] = {
        {1, 0, 3, 0},
        {0, 5, 0, 0},
        {0, 0, 0, 0},
        {0, 7, 0, 8}
    };
    // 定义一个稀疏矩阵
    TSMatrix M;
    // 创建稀疏矩阵
    createMatrix(&M, a, 4, 4);
    // 输出稀疏矩阵的三元组
    printf("行数：%d，列数：%d，非零元素个数：%d\n", M.m, M.n, M.num);
    for (int i = 0; i < M.num; i++) {
        printf("行索引：%d，列索引：%d，元素值：%d\n", M.data[i].i, M.data[i].j, M.data[i].e);
    }
    return 0;
}

// 总结：
// 本题考察了稀疏矩阵的三元组表示法，是数据结构中线性表的应用。
// 关键问题：
//! 对于稀疏矩阵，我们只需要存储非零的元素即可，这样可以节省存储空间。
//! 我们使用一个二维数组来存储非零元素的行索引、列索引和值，数组的第一行存储矩阵的行数、列数和非零元素的个数。
