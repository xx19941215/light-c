#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * strlong(char *str1, char *str2);
int * func();
int * func2();

int main() {
    //返回指针的函数
    //C 语言 允许函数的返回值是一个指针(地址)，这样的函数称为指针函数。
    char str1[30], str2[30], *str;

    printf("\n 请输入第 1 个字符串");
    gets(str1);
    printf("\n 请输入第 2 个字符串");
    gets(str2);
    str = strlong(str1, str2);
    printf("\nLonger string: %s \n", str);

    int *p = func();
    int n;
    n = *p;
    printf("\nvalue = %d\n", n);// 是否能够输出 100? 不一定

    p = func2();

    for (int i = 0; i < 10; i++)
    {
        printf("\n%d", *(p+i));
    }
    

    return 0;
}

char * strlong(char *str1, char *str2)
{
    printf("\nstr1的长度%d str2的长度 %d", strlen(str1), strlen(str2));
    if (strlen(str1) > strlen(str2)) {
        return str1;
    }

    return str2;
}

int * func()
{
    // int n = 100; //局部变量, 在 func 返回时，就会销毁
    static int n = 100; //如果这个局部变量是 static 性质的，那么 n 存放数据的空间在静态数据区
    return &n;
}

int * func2()
{
    static int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand();
    }

    return arr;
    
}

// 说明
// 1.用指针作为函数返回值时需要注意，函数运行结束后会销毁在它内部定义的所有局部数据，包括局部变量、局部数组和形式参数，函数返回的指针不能指向这些数据
// 2.函数运行结束后会销毁该函数所有的局部数据，这里所谓的销毁并不是将局部数据所占用的内存全部清零，而是程序放弃对它的使用权限，后面的代码可以使用这块内存
// 3.C语言不支持在调用函数时返回局部变量的地址，如果确实有这样的需求，需要定义局部变量为 static 变量