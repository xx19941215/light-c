#include <stdio.h>

void main() {
    printf("int 的字节数 %d", sizeof(int));
    longint();
    getchar();
}

//使用细节
//1.各种类型的存储大小与操作系统、系统位数、和编译器有关，目前通用的以64位系统为主。
//2.通常c程序运行在linux/unix操作系统中
//3.c语言中的整型类型 分为有符号(signed)和无符号(unsigned)两种 默认是signed。
//4.c程序中的整型常声明为int型，除非不足以表达大数 才使用long long

longint() {
    long long num1 = 12345678453345;
    printf("num1 = %lld", num1);
}