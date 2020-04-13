#include <stdio.h>
#include <string.h>

void main() {
    //字符串函数
    char src[50] = "abc", dest[50];

    char *str = "abcdff";

    printf("str.len=%d", strlen(str));

    strcpy(src, "hello");
    printf("\n src=%s", src);

    
    strcpy(dest, "萧");
    //strcat 是将 src 字符串的内容连接到 dest ,但是不会覆盖 dest 原来的内容，而是连接!!
    strcat(dest, src); 
    printf("\n最终的目标字符串: dest=%s", dest);

}

// 说明