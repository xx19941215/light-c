#include <stdio.h>
int max(int a, int b);

int main() {
    //函数指针
    // 1.一个函数总是占用一段连续的内存区域，函数名在表达式中有时也会被转换为该函数所在内存区域的首地址， 这和数组名非常类似
    // 2.把函数的这个首地址(或称入口地址)赋予一个指针变量，使指针变量指向函数所在的内存区域，然后通过指针变量就可以找到并调用该函数。这种指针就是函数指针。

    int x, y, maxVal;
    //函数指针的名字 pmax
    //int 表示 该函数指针指向的函数是返回 int 类型
    //(int, int) 表示 该函数指针指向的函数形参是接收两个 int
    //在定义函数指针时，也可以写上形参名 int (*pmax)(int x, int y) = max;
    int (*pmax)(int, int) = max;
    printf("Input two numbers:");
    scanf("%d %d", &x, &y);
    // (*pmax)(x, y) 通过函数指针去调用 函数 max
    maxVal = (*pmax)(x, y);
    printf("Max value: %d pmax=%p pmax 本身的地址=%p\n", maxVal, pmax, &pmax);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

// 说明