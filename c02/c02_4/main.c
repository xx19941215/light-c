#include <stdio.h>
#include <stdarg.h>

void f3(int *p) {
    (*p)++;
}

//可变参数
int func (int num, ...) {
    int i, totalSum = 0;
    int val = 0;

    va_list v1; // v1 实际是一个字符指针，从头文件里可以找到
    va_start(v1, num); //使 v1 指向可变列表中第一个值，即 num 后的第一个参数

    printf("*v=%d\n", *v1);
    for (i = 0; i < num; i++) {
        val = va_arg(v1, int); //该函数返回 v1 指向的值，并使 v1 向下移动一个 int 的距离，使其指向下一个 int
        printf("val=%d\n", val); //val = 10 val=30 val=60
        totalSum += val;
    }

    va_end(v1);
    return totalSum;
}

void swap(int *a, int *b) {
    int temp = *a; //将a这个指针指向的变量的值赋给temp
    *a = *b; //表示将 b这个指针指向的变量的值赋给n1这个指针指向的变量
    *b = temp; //表示将temp值赋给b这个指针指向的变量
}

void main() {
    //函数细节
    int n = 9;
    int m = 90;
    f3(&n);
    printf("n=%d\n", n);
    swap(&n, &m);
    printf("n=%d\n", n);

    int res = func(8, 10,30,60, -100,1,5,7,98);
    printf("和是%d\n", res);
}

//函数的细节
// 1.函数的形参列表可以是多个。
// 2.C 语言传递参数可以是值传递(pass by value)，也可以传递指针(a pointer passed by value)也叫引用传递。
// 3.函数的命名遵循标识符命名规范，首字母不能是数字，可以采用 驼峰法 或者 下划线法 ，比如 get_max()。
// 4.函数中的变量是局部的，函数外不生效
// 5.基本数据类型默认是值传递的，即进行值拷贝。在函数内修改，不会影响到原来的值。
// 6.如果希望函数内的变量能修改函数外的变量，可以传入变量的地址&，函数内以指针的方式操作变量。从效果 上看类似引用(即传递指针) 
// 7.C 语言 不支持函数重载。
// 8.C 语言支持可变参数函数