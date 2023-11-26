#include <stdio.h>

// 矩阵加法函数
void add(int a[3][3], int b[3][3], int result[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = a[i][j] + b[i][j]; // 将两个矩阵对应位置的元素相加
        }
    }
}

// 矩阵减法函数
void subtract(int a[3][3], int b[3][3], int result[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = a[i][j] - b[i][j]; // 将两个矩阵对应位置的元素相减
        }
    }
}

//!   矩阵乘法函数
void multiply(int a[3][3], int b[3][3], int result[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = 0; // 初始化结果矩阵的元素为0
            for (int k = 0; k < 3; k++)
            {
                result[i][j] += a[i][k] * b[k][j]; //  计算矩阵乘法
            }
        }
    }
}

// 矩阵转置函数
void transpose(int a[3][3], int result[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[j][i] = a[i][j]; // 将原矩阵的行变为列，列变为行
        }
    }
}

// 求矩阵的迹函数
int trace(int a[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += a[i][i]; // 将矩阵对角线上的元素相加
    }
    return sum;
}



// 检查矩阵是否对称的函数
int isSymmetric(int a[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i][j] != a[j][i])
            { // 如果矩阵的元素不满足对称性质，返回0
                return 0;
            }
        }
    }
    return 1; // 如果矩阵的所有元素都满足对称性质，返回1
}

// 求矩阵的行列式函数
int determinant(int a[3][3])
{
    int sum = 0;
    sum = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
          a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
          a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]); // 计算矩阵的行列式
    return sum;
}
 
// 计算矩阵的逆的函数（这里假设输入的矩阵一定是可逆的）
void inverse(int a[3][3], float result[3][3])
{
    int det = determinant(a); // 计算矩阵的行列式
    if (det == 0)
    {
        printf("The matrix is not invertible.\n");
        return;
    }
    //!  计算矩阵的逆 = 伴随/行列式
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[j][i] = 
            
            ((a[(i + 1) % 3][(j + 1) % 3] * a[(i + 2) % 3][(j + 2) % 3]) - (a[(i + 1) % 3][(j + 2) % 3] * a[(i + 2) % 3][(j + 1) % 3]))

             / (float)det;
        }
    }
}












int main()
{
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // 定义一个3*3矩阵
    int result[3][3];                                // 定义结果矩阵

    transpose(a, result);   // 调用矩阵转置函数
    int t = trace(a);       // 调用求矩阵的迹函数
    int d = determinant(a); // 调用求矩阵的行列式函数

    return 0;
}
