#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 函数声明
void shuffle(int *array, int n);  // 随机打乱数组
int is_sorted(int *array, int n); // 检查数组是否已排序
void print_progress(int current, int total); // 打印进度条

int main()
{
    srand(time(NULL)); // 初始化随机数生成器

    int array[15]; // 要排序的数组
    int i;
    int tag = 0;
    // 生成随机数组
    for (i = 0; i < 15; i++)
    {
        array[i] = rand() % 10;
    }

    // 使用猴子排序算法对数组进行排序
    while (!is_sorted(array, 15))
    {

        shuffle(array, 15);
        tag += 1;

        printf("正在尝试第 %d 次排序\n", tag);
        print_progress(tag, 15*15); // 打印进度条

    }

    // 输出排序后的数组
    for (i = 0; i < 15; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}

// 随机打乱数组
void shuffle(int *array, int n)
{
    int i, j, temp;
    for (i = n - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// 检查数组是否已排序
int is_sorted(int *array, int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

// 打印进度条
void print_progress(int current, int total)
{
    int percent = (100 * current) / total;
    printf("[");
    for (int i = 0; i < percent; i++)
    {
        printf("#");
    }
    for (int i = percent; i < 100; i++)
    {
        printf(" ");
    }
    printf("] %d%%\n", percent);
}
