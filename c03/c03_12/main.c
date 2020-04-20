#include <stdio.h>
#include <stdlib.h>
// 1.int (*f)(void)
// 2.f就是函数的指针
// 3.f在这里被initArray调用
void initArray(int *array, int arraySize, int (*f)(void))
{
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = f(); //通过 函数指针调用了 getNextRandomValue 函数
    }
    
}

int getNextRandomValue(void)
{
    return rand();
}


void main() {
    //回调函数
    //1.函数指针变量可以作为某个函数的参数来使用的，回调函数就是一个通过函数指针调用的函数。
    //2.简单的讲:回调函数是由别人的函数执行时调用你传入的函数(通过函数指针完成)

    int myArr[10], i;
    initArray(myArr, 10, getNextRandomValue);

    for(i = 0; i < 10; i++) {
        printf("%d ", myArr[i]); 
    }
    printf("\n");
}

// 说明
// 1.指针变量存放的是地址，从这个角度看指针的本质就是地址。
// 2.变量声明的时候，如果没有确切的地址赋值，为指针变量赋一个 NULL 值是好的编程习惯。
// 3.赋为 NULL 值的指针被称为空指针，NULL 指针是一个定义在标准库 <stdio.h>中的值为零的常量 #define NULL 0