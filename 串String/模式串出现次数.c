/*
题目要求：
给定一个主串和一个模式串，编程计算该模式串在主串中出现的次数。

思路：
1. 遍历主串，对于每个字符，检查它后面的字符是否与模式串匹配。
2. 如果匹配，计数器加一。
3. 最后返回计数器的值。
*/

#include <stdio.h>

int countOccurrences(char *mainStr, char *pattern)
{                  // 定义函数，参数为主串和模式串
    int i, j, k;   // 定义循环变量
    int count = 0; // 初始化计数器

    for (i = 0; mainStr[i] != '\0'; i++)
    { // 遍历主串
        for (j = i, k = 0; pattern[k] != '\0' && mainStr[j] == pattern[k]; j++, k++)
                  ;                            // 检查主串的子串是否与模式串匹配
        if (k > 0 && pattern[k] == '\0') // 如果匹配，计数器加一
            count++;
    }

    return count; // 返回计数器的值
}

int main()
{
    char mainStr1[] = "BAPC"; // 测试数据1
    char pattern1[] = "BAPC";
    printf("%d\n", countOccurrences(mainStr1, pattern1)); // 输出结果

    char mainStr2[] = "AZAZAZAZ"; // 测试数据2
    char pattern2[] = "AZ";
    printf("%d\n", countOccurrences(mainStr2, pattern2)); // 输出结果

    return 0;
}

/*
总结：
本题考察了字符串处理和遍历的知识点。解决问题的关键是使用自定义的字符串比较方法来比较主串的子串和模式串是否匹配。
我们通过遍历主串和模式串，比较每个字符是否相同，从而判断主串的子串是否与模式串匹配，计算模式串在主串中出现的次数。
*/
