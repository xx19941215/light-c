#include <stdio.h>
// #include "header.h"

void fn(void) {
    int n = 10; //普通变量, 每次执行都会初始化，n 在栈区
    printf("n=%d\n", n);
    n++;
    printf("n++=%d\n", n);
}

void fn_static(void) {
    static int n = 10; //静态局部变量， 放在静态存储区，全局性质空间 printf("\nstatic n=%d\n", n); // 10
    n++; // n = 11
    printf("\nn++=%d\n", n); // 11
}

extern int num;
int num2 = 60;

void main() {
    //static
    //static 关键字在 c 语言中比较常用，使用恰当能够大大提高程序的模块化特性，有利于扩展和维护。
    //局部变量中使用static修饰
    // 1.局部变量被 static 修饰后，我们称为静态局部变量
    // 2.对应静态局部变量在声明时未赋初值，编译器也会把它初始化为0。
    // 3.静态局部变量存储于进程的静态存储区(全局性质)，只会被初始一次，即使函数返回，它的值也会保持不变

    static int n;
    printf("n = %d\n ", n);
    fn();
    fn();
    fn_static();
    fn_static();

    //全局变量使用 static 修饰
    //1.普通全局变量对整个工程可见，其他文件可以使用extern外部声明后直接使用。也就是说其他文件不能再定义 一个与其相同名字的变量了(否则编译器会认为它们是同一个变量)，静态全局变量仅对当前文件可见，其他 文件不可访问，其他文件可以定义与其同名的变量，两者互不影响
    //2.定义不需要与其他文件共享的全局变量时，加上static关键字能够有效地降低程序模块之间的耦合，避免不同 文件同名变量的冲突，且不会误使用
    // 编译步骤
    // 1.gcc -c var.c
    // 2.gcc -o a.out main.c var.o
    printf("\nnum=%d num2=%d", num, num2);
}
// 说明