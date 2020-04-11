#include <stdio.h>

void fun1(void)
{ //普通函数(非静态函数)
    printf("hello from fun1.\n");
}

static void fun2(void)
{ //静态函数, 它只能在本文件中使用
    printf("hello from fun2.\n");
}
// 说明
