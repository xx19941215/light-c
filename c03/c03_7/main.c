#include <stdio.h>

const int MAX = 3;//常量
int main() {
    //指针的递增操作
    int var[] = {10, 100, 200};
    int i, *ptr;//ptr是一个int*指针

    ptr = var;//ptr指向了var数组的首地址
    for (i = 0; i < MAX; i++)
    {
        printf("var[%d]地址=%p\n", i, ptr);
        printf("存储值：var[%d]=%d\n", i, *ptr);
        ptr++;//ptr = ptr + 1(1 个 int 字节数); ptr 存放值+4 字节(int)
    }

    //指针的递减操作
    ptr = &var[MAX-1];
    for (i = MAX; i > 0 ; i--)
    {
        printf("ptr存放的地址=%p\n", ptr);
        printf("存储值：var[%d]=%d\n", i, *ptr);
        ptr--;
    }

    ptr = var; //arr的首地址赋值给ptr
    ptr += 2; // ptr 的存储的地址 + 2个int的字节 (8个字节)
    printf("var[2]=%d var[2]的地址是=%p ptr存储的地址是=%p ptr指向的值是=%d", var[2], &var[2], ptr, *ptr);

    ptr -= 2;
    if (ptr == &var[0]) {//true
        printf("\nok");
    }

    if (ptr == var) { //true
        printf("\nok");
    }

    if (ptr >= &var[1]) { //可以比较但是返回false
        printf("\nok");
    }

    while (ptr <= &var[MAX-2]) { //&var[1]
        printf("\nAddress of var[%d]=%p\n", i, ptr);
        printf("Address of var[%d]=%d\n", i, *ptr);
        ptr++;
        i++;
    }//会输出10, 100

   
    return 0;
}

// 说明
// 1.数组在内存中是连续分布的
// 2.当对指针进行++时，指针会按照它指向的数据类型字节数大小增加，比如 int * 指针，每++ ， 就增加 4 个字节
// 3.可以对指针按照指定的字节数大小进行 + 或者 – 的操作，可以快速定位你要的地址