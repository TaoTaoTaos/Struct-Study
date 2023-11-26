// 题目要求：实现KMP算法（Knuth Morris Pratt）算法，也叫快速模式匹配算法。
// KMP算法是一种在字符串中查找子串的高效方法，它对待匹配串进行预处理，以便在不匹配时跳过尽可能多的字符。

// 思路和算法原理：
//! 1. 首先，构建一个“部分匹配表”，记录了每个前缀子串的最长公共前后缀的长度。
//  2. 然后，从左到右逐个检查文本串中的字符是否和待匹配串中的字符相同。
//  3. 如果相同，就继续比较下一个字符；如果不同，就根据部分匹配表跳过一些字符，然后重新比较。
//  4. 这个过程一直持续到找到匹配的子串或者已经检查了所有可能的位置。

#include <stdio.h>
#include <string.h>

// 构建部分匹配表 //! next 数组
void computeLPSArray(char *pat, int M, int *lps)
{
    int len = 0;
    lps[0] = 0; // lps[0]总是等于0

    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP算法的实现
//!主串 i 不变 ，思考 模式串的 j 应该 指向哪里 ，即思考 模式串可以跳过多少部分
void KMP(char *txt, char *pat)
{
    int M = strlen(pat);
    int N = strlen(txt);

    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0; // 文本串的索引
    int j = 0; // 待匹配串的索引
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main()
{
    // 测试KMP算法
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    KMP(txt, pat);
    return 0;
}

// 题目所考察的知识点：
// 1. 字符串操作：KMP算法需要对字符串进行基本的操作，如获取长度和访问特定位置的字符。
// 2. 循环结构：KMP算法使用了嵌套的循环结构来遍历文本串和待匹配串。
// 3. 条件判断：KMP算法需要判断文本串中的字符是否和待匹配串中的字符相同。
// 4. 数组操作：KMP算法需要构建和使用一个部分匹配表，这需要对数组进行操作。

//! 关键问题：KMP算法的时间复杂度是O(m+n)，其中m和n分别是文本串和待匹配串的长度。这比BF算法的时间复杂度O(mn)要好得多。KMP算法的关键在于利用已经对待匹配串进行的比较，通过部分匹配表跳过不可能匹配的位置，从而提高了匹配的效率。但是，构建部分匹配表需要一定的时间和空间，这是KMP算法的一个代价。
