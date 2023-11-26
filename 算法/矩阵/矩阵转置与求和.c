// 从键盘上输入两个3×3的矩阵，然后计算出这两个矩阵的转置结果和矩阵的和，并输出结果
#include <stdio.h>

// 定义矩阵的大小
#define SIZE 3

// 定义一个函数，用于 读取矩阵
void readMatrix(int matrix[SIZE][SIZE])
{
    // 使用嵌套的for循环来读取矩阵的每一个元素
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // 使用scanf函数来读取用户输入的一个整数，并将其存储在矩阵的相应位置
            scanf("%d", &matrix[i][j]);
        }
    }
}

// 定义一个函数，用于打印矩阵
void printMatrix(int matrix[SIZE][SIZE])
{
    // 使用嵌套的for循环来打印矩阵的每一个元素
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // 使用printf函数来打印矩阵的一个元素，并在其后添加一个空格
            printf("%d ", matrix[i][j]);
        }
        // 在打印完矩阵的一行后，使用printf函数打印一个换行符，以便于下一行的打印
        printf("\n");
    }
}

//!      定义一个函数，用于计算矩阵的转置
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE])
{
    // 使用嵌套的for循环来计算矩阵的转置
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // 将原矩阵的第i行第j列的元素赋值给 -->  矩阵的第j行第i列
            result[j][i] = matrix[i][j];
        }
    }
}

// !     定义一个函数，用于计算两个矩阵的和
void addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE], int result[SIZE][SIZE])
{
    // 使用嵌套的for循环来计算两个矩阵的和
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // 将两个矩阵的对应元素相加，然后将结果存储在结果矩阵的对应位置
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main()
{
    // 定义两个3x3的矩阵，用于存储用户的输入
    int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE];
    // 定义两个3x3的矩阵，用于存储结果
    int transpose1[SIZE][SIZE], transpose2[SIZE][SIZE], sum[SIZE][SIZE];

    // 提示用户输入第一个矩阵，并读取用户的输入
    printf("请输入第一个3x3矩阵的元素：\n");
    readMatrix(matrix1);

    // 提示用户输入第二个矩阵，并读取用户的输入
    printf("请输入第二个3x3矩阵的元素：\n");
    readMatrix(matrix2);

    // 计算两个矩阵的转置
    transposeMatrix(matrix1, transpose1);
    transposeMatrix(matrix2, transpose2);

    // 计算两个矩阵的和
    addMatrices(matrix1, matrix2, sum);

    // 打印两个矩阵的转置
    printf("第一个矩阵的转置是：\n");
    printMatrix(transpose1);
    printf("第二个矩阵的转置是：\n");
    printMatrix(transpose2);

    // 打印两个矩阵的和
    printf("两个矩阵的和是：\n");
    printMatrix(sum);

    return 0;
}