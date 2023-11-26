/*
题目要求：
将中缀表达式转换为后缀表达式。

思路：
1. 初始化两个栈：      运算符栈s1
                 和储存中间结果的栈s2。
2. 从左至右扫描中缀表达式。
3. 遇到操作数时，将其压s2；
4. 遇到运算符时，比较其与s1栈顶运算符的优先级：
    1. 如果s1为空， 或  栈顶运算符为左括号“(”，则直接将此运算符入栈；
    2. 否则，若优先级比栈顶运算符的高，也将运算符压入s1；
    3. 否则，将s1栈顶的运算符弹出并压入到s2中，再次转到(4-1)与s1中新的栈顶运算符相比较；
5. 遇到括号时： 
    1. 如果是左括号“(”，则直接压入s1
    2. 如果是右括号“)”，则依次弹出s1栈顶的运算符，并压入s2，直到遇到左括号为止，此时将这一对括号丢弃
6. 重复步骤2至5，直到表达式的最右边
7. 将s1中剩余的运算符依次弹出并压入s2
8. 依次弹出s2中的元素并输出，结果的逆序即为中缀表达式对应的后缀表达式
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// !判断是否为操作符
int isOperator(char c) 
{
    return c == '+' || c == '-' || c == '*' || c == '/'; // 判断是否为四则运算符
}

//! 判断操作符的优先级 
int precedence(char op)
 {
    if(op == '+'||op == '-') // 加减运算优先级最低
        return 1;
    if(op == '*'||op == '/') // 乘除运算优先级较高
        return 2;
    return 0;       
}

// !中缀表达式转后缀表达式
char* infixToPostfix(char* infix) {
    int len = strlen(infix);
    char* postfix = (char*)malloc(sizeof(char) * (len + 1)); // 创建一个字符串用于存储后缀表达式,他的长度和infix一样
    char stack[len]; // 创建一个栈用于存储操作符
    int top = -1; // 栈顶指针
    int j = 0; // 后缀表达式指针

    for(int i = 0; i < len; i++)
     { // 遍历中缀表达式
        if(isOperator(infix[i]))
         { //! 如果是操作符 
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            { //!如果栈不为空 且 栈顶操作符的优先级大于等于当前操作符
                postfix[j++] = stack[top--]; //! 将栈顶操作符添加到后缀表达式
            }
            stack[++top] = infix[i]; // 将当前操作符压入栈
        }
         else
        { // 如果是操作数
            postfix[j++] = infix[i]; // 直接添加到后缀表达式
        }
    }

    while(top != -1) 
    { // 如果栈不为空
        postfix[j++] = stack[top--]; // 将栈顶操作符添加到后缀表达式
    }

    postfix[j] = '\0'; // 字符串结束符
    return postfix; // 返回后缀表达式
}

int main() 
{
    char infix[100];
    printf("请输入中缀表达式：");
    scanf("%s", infix);
    printf("对应的后缀表达式为：%s\n", infixToPostfix(infix));
    return 0;
}

/*
总结：
本题主要考察了栈的使用，以及中缀表达式和后缀表达式的转换方法。
关键点：
1. 使用栈存储操作符：栈具有后进先出的特性，非常适合用来处理这种需要考虑优先级的问题。
2. 操作符的优先级判断：通过设定优先级的值，可以方便地比较两个操作符的优先级。
3. 中缀表达式和后缀表达式的转换：通过栈的操作，可以实现中缀表达式向后缀表达式的转换。
*/
