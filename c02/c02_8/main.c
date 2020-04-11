#include <stdio.h>

extern void fun1(void);

void main()
{
    //static函数
    // 1.函数的使用方式与全局变量类似，在函数的返回类型前加上static，就是静态函数
    // 2.非静态函数可以在另一个文件中通过 extern 引用
    // 3.静态函数只能在声明它的文件中可见，其他文件不能引用该函数
    // 4.不同的文件可以使用相同名字的静态函数，互不影响
    fun1(); 
    //fun2();
}

void fun2(void)
{ //普通函数(非静态函数)
    printf("hello from fun1.\n");
}

// 说明
