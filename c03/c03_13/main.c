#include <stdio.h>
#include <stdlib.h>
void check(int *p);

void main() {
    //动态内存分布
    // 1.全局变量——内存中的静态存储区
    // 2.非静态的局部变量——内存中的动态存储区——stack 栈
    // 3.临时使用的数据---建立动态内存分配区域，需要时随时开辟，不需要时及时释放——heap 堆
    // 4.根据需要向系统申请所需大小的空间，由于未在声明部分定义其为变量或者数组，不能通过变量名或者数组名来引用这些数据，只能通过指针来引用)

    int * p, i;
    p = (int *) malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", p + i);
    }
    
    check(p);
    free(p); //销毁 堆区 p 指向的空间


}

void check(int *p)
{
    int i;
    printf("\n不及格的成绩有");
    for (int i = 0; i < 5; i++)
    {
        if (p[i] < 60) {
            printf("%d\n", p[i]);
        }
    }
    
}

// 说明
// 1.头文件 #include <stdlib.h> 声明了四个关于内存动态分配的函数
// 2.函数原型 void * malloc(usigned int size) //memory allocation
//  2.1 作用——在内存的动态存储区(堆区)中分配一个长度为 size 的连续空间。
//  2.2 形参 size 的类型为无符号整型，函数返回值是所分配区域的第一个字节的地址，即此函数是一个指针型函数，返回的指针指向该分配域的开头位置。
//  2.3 malloc(100); 开辟 100 字节的临时空间，返回值为其第一个字节的地址
// 3.函数原型void*calloc(unsignedn,unsignedsize)
//  3.1 作用——在内存的动态存储区中分配 n 个长度为 size 的连续空间，这个空间一般比较大，足以保存一个数组
//  3.2 用 calloc 函数可以为一维数组开辟动态存储空间，n 为数组元素个数，每个元素长度为 size.
//  3.3 函数返回指向所分配域的起始位置的指针;分配不成功，返回 NULL。
//  3.4 p = calloc(50, 4); //开辟 50*4 个字节临时空间，把起始地址分配给指针变量 p
// 4.函数原型:voidfree(void*p)
//  4.1 作用——释放变量 p 所指向的动态空间，使这部分空间能重新被其他变量使用。
//  4.2 p是最近一次调用calloc或malloc函数时的函数返回值
//  4.3 free函数无返回值
//  4.4 free(p); // 释放 p 所指向的已分配的动态空间
// 5.函数原型void*realloc(void*p，unsignedintsize)
//  5.1 作用——重新分配 malloc 或 calloc 函数获得的动态空间大小，将 p 指向的动态空间大小改变为 size，p 的值不 变，分配失败返回 NULL
//  5.2 realloc(p, 50); // 将 p 所指向的已分配的动态空间 改为 50 字节

// 6.动态分配内存的基本原则
//  6.1 避免分配大量的小内存块。分配堆上的内存有一些系统开销，所以分配许多小的内存块比分配几个大内存块的 系统开销大
//  6.2 仅在需要时分配内存。只要使用完堆上的内存块，就需要及时释放它(如果使用动态分配内存，需要遵守原则: 谁分配，谁释放)， 否则可能出现内存泄漏
//  6.3 总是确保释放以分配的内存。在编写分配内存的代码时，就要确定在代码的什么地方释放内存
//  6.4 在释放内存之前，确保不会无意中覆盖堆上已分配的内存地址，否则程序就会出现内存泄漏。在循环中分配内存时，要特别小心

