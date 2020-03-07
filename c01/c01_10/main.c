#include <stdio.h>

#define BOOL int
#define TURE 1
#define FALSE 0
void main() {
    int isPass = 1;

    if (isPass) {
        printf("真");
    }

    //使用宏定义
    BOOL isOk = TURE;
    if (isOk) {
        printf("ok");
    }
}

// 说明
// 1.C语言标准(C89)中没有定义布尔类型 所以C语言中判断真假时以0为假 非0为真
// 2.C语言标准(C99)提供了_Bool型 但是仍然是整数类型 但与一般整型不同的是 它只能赋值为0和1 非0的值都会被存储为1
// C99还提供了一个头文件 stdbool.h 定义了bool代表 _Bool true代表1 false代表0 只要导入就可以方便的操作布尔类型了