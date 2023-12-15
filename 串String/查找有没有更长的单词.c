// 题目要求：写一个函数int find_len_word( char *s1, char *s2)，查找串 s1中是否包含比指定的词（s2指向的字符串)长的词，如果存在则返回第一次出现的位置，否则返回-1，约定串中的词由1个或1个以上的空格符分隔。
// 思路：首先，我们需要获取s2的长度。然后，我们遍历s1，使用空格作为分隔符来获取每个词。对于每个词，我们比较它的长度和s2的长度。如果它的长度大于s2的长度，我们就返回它的位置。

#include <stdio.h>
#include <string.h>

// 定义函数
int find_len_word(char *s1, char *s2)
{
    // 获取s2的长度
    int len_s2 = strlen(s2);

    // 初始化词的开始位置和长度
    int start = 0;
    int len = 0;

    // 遍历s1
    for (int i = 0; s1[i] != '\0'; i++)
    {
        // 如果遇到空格或者到达字符串的末尾，就表示找到了一个词
        if (s1[i] == ' ' || s1[i + 1] == '\0')
        {
            // 比较词的长度和s2的长度
            if (len > len_s2)
            {
                // 如果词的长度大于s2的长度，就返回词的开始位置
                return start;
            }

            // 更新词的开始位置和长度
            start = i + 1;
            len = 0;
        }
        else
        {
            // 如果没有遇到空格，就增加词的长度
            len++;
        }
    }

    // 如果没有找到比s2长的词，就返回-1
    return -1;
}

int main()
{
    // 测试函数
    char s1[] = "Hello world this is a test";
    char s2[] = "world";
    int position = find_len_word(s1, s2);
    printf("位置是：%d\n", position);

    return 0;
}

// 总结：这个题目主要考察了字符串的操作，包括获取字符串的长度，遍历字符串，以及比较字符串的长度。
// 关键注释：int len_s2 = strlen(s2); 这行代码是获取字符串长度的关键，它使用了strlen函数来获取s2的长度。
// if (len > len_s2) 这行代码是比较字符串长度的关键，它比较了当前词的长度和s2的长度。
// return start; 这行代码是返回结果的关键，它返回了比s2长的词的开始位置。
