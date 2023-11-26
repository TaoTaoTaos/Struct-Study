// 题目要求：实现括号匹配，检查一个字符串中的括号是否匹配。

// 思路：使用栈来实现括号匹配。遍历字符串，遇到左括号就入栈，遇到右括号就出栈并检查是否匹配。

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // 定义栈的最大长度

// 定义栈的数据结构
typedef struct {
    char data[MAX_SIZE];  // 存储数据元素
    int top;  // 栈顶指针
} Stack;

// 初始化栈
void InitStack(Stack* S) {
    S->top = -1;  //!       初始化栈顶指针为-1
}

// 入栈操作
void Push(Stack* S, char e) {
    if (S->top == MAX_SIZE - 1) {  // 如果栈已满，无法入栈
        return;
    }                       //!栈顶其实就是数组的最后一位
    S->data[++S->top] = e;  //!先把栈顶（top指向最后一位）+ 1   // 将元素e入栈
}

// 出栈操作
void Pop(Stack* S) {
    if (S->top == -1) {  // 如果栈为空，无法出栈
        return;
    }
    S->top--;  //    出栈   //! 其实数据没删掉，只是栈顶指针减了 1
}

// 获取栈顶元素
char GetTop(Stack* S) {
    if (S->top != -1) {  // 如果栈不为空
        return S->data[S->top];  // 返回栈顶元素 S -> top 
    }
    return '\0';  // 如果栈为空，返回空字符
}

// 检查括号是否匹配
int CheckMatch(char* str) {
    Stack S;  // 创建一个栈
    InitStack(&S);  // 初始化栈
    for (int i = 0; str[i] != '\0'; i++) {  // 遍历字符串

        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {    
            Push(&S, str[i]);//! 如果是左括号，无脑入栈

        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') { 
             //! 如果是右括号，出栈并检查是否匹配
            if (S.top == -1) {  //! 如果栈为空，说明没有匹配的左括号,结束
                return 0;
            }
    
            char top = GetTop(&S);  // 获取栈顶元素
            if 
            ((str[i] == ')' && top != '(') || 
             (str[i] == ']' && top != '[') ||
             (str[i] == '}' && top != '{'))  
            
            {  // 如果不匹配，返回0
                return 0;
            }
            Pop(&S);  // 出栈
        }
    }
    if (S.top != -1) {  //!  如果遍历完字符串后栈不为空，说明有未匹配的左括号
        return 0;
    }
    return 1;  //! 如果遍历完字符串后栈为空，说明所有括号都匹配
}

int main() {
    char str[] = "{[()]}";  // 创建一个包含括号的字符串
    int match = CheckMatch(str);  // 检查括号是否匹配
    if (match) {
        printf("The brackets match.\n");
    } else {
        printf("The brackets do not match.\n");
    }
    return 0;
}

//! 总结
// 本题主要考察了栈的应用——括号匹配。括号匹配是栈的一个经典应用，它利用栈后进先出的特性，当遇到左括号时入栈，遇到右括号时出栈并检查是否匹配。
// 如果遍历完字符串后栈为空，说明所有括号都匹配；如果栈不为空，说明有未匹配的左括号；如果在遍历过程中栈为空但遇到右括号，或者出栈的左括号与当前的右括号不匹配，说明括号不匹配。
// 通过本题，我们可以理解栈在解决实际问题中的应用，以及如何利用栈的特性来解决问题。
