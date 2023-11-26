#include <stdio.h>
#include <string.h>

int main() {
    // 定义一个字符串
    char str[100] = "Hello, World!";

    // 增：在字符串末尾添加字符
    strcat(str, " How are you?");
    printf("%s\n", str); // 输出：Hello, World! How are you?

    // 删：删除字符串中的某个字符（例如，删除第一个字符）
    memmove(&str[0], &str[1], strlen(str) - 1);
    str[strlen(str) - 1] = 0;
    printf("%s\n", str); // 输出：ello, World! How are you?

    // 改：修改字符串中的某个字符（例如，将第一个字符改为'H'）
    str[0] = 'H';
    printf("%s\n", str); // 输出：Hello, World! How are you?

    // 查：查找字符串中的某个字符（例如，查找字符'o'）
    char *p = strchr(str, 'o');
    if (p) {
        printf("Found 'o' at position: %ld\n", p - str + 1); // 输出：Found 'o' at position: 2
    } else {
        printf("'o' not found\n");
    }

    return 0;
}
