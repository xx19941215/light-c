#include <stdio.h>

void main() {
    //指针
    // 1.指针是C语言的精华，也是C语言的难点。
    // 2.指针，也就是内存的地址;所谓指针变量，也就是保存了内存地址的变量。
    // 3.获取变量的地址，用&，比如:intnum=10,获取num的地址:&num
    // 4.指针类型，指针变量存的是一个地址，这个地址指向的空间存的才是值 比如:int *ptr = &num; ptr 就是指向 int 类型的指针变量, 即 ptr 是 int * 类型。
    // 5.获取指针类型所指向的值，使用:*(取值符号)，比如:int*ptr,使用*ptr获取ptr指向的值

    int *ip; //一个整型的指针
    double *dp; //一个 double 型的指针
    float *fp; // 一个浮点型的指针
    char *ch; //一个字符型的指针

    int num = 1;
    int *ptr = &num;

    printf("\nnum的值是=%d num的地址是=%p", num, &num);

    printf("\nptr的地址是%p ptr存放的值是一个地址为%p ptr指向的值是=%d", &ptr, ptr, *ptr);
}

// 说明