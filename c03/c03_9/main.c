#include <stdio.h>

void test2(int *p);
double getAverage(int *arr, int size);
double getAverage2(int *arr, int size);

int main() {
    //多重指针
    //指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。通常，一个指针包含一个变量的地址。当 我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置

    int var;
    int *ptr;
    int **pptr;//二级指针
    int ***ppptr;//三级指针

    var = 3000;

    ptr = &var;
    pptr = &ptr;
    ppptr = &pptr;

    printf("var 的地址=%p var = %d \n", &var, var );// 0x1133 3000
    printf("ptr 的本身的地址=%p ptr 存放的地址=%p *ptr = %d \n", &ptr, ptr, *ptr );
    printf("pptr 本身地址 = %p pptr 存放的地址=%p **pptr = %d\n", &pptr, pptr, **pptr);
    printf("ppptr 本身地址 = %p ppptr 存放的地址=%p ***pptr = %d\n", &ppptr, ppptr, ***ppptr);

    //传递指针(地址)给函数
    //当函数的形参类型是指针类型时，是使用该函数时，需要传递指针，或者地址，或者数组给该形参
    int num = 90;
    int *p = &num;
    test2(&num);
    printf("\nnum=%d", num); // num = 91
    test2(p);
    printf("\nnum=%d", num); // num = 91

    //传数组给指针变量
    //数组名本身就代表该数组首地址，因此传数组的本质就是传地址。
    int balance[5] = {1000, 2, 3, 17, 50};

    double avg;
    avg = getAverage2(balance, 5);
    printf("Average value is: %f\n", avg);

    return 0;
}

void test2(int *p)
{
    *p += 1; //*p就访问num的值    
}

double getAverage(int *arr, int size)
{
    int i, sum = 0;
    double avg;

    for (i = 0; i < size; i++)
    {
        sum += arr[i];
        printf("\narr 存放的地址=%p ", &arr);
    }

    avg = (double) sum/size;
    return avg;
}

double getAverage2(int *arr, int size)
{
    int i, sum = 0;
    double avg;

    for (i = 0; i < size; i++)
    {
        sum += *arr;
        printf("\narr 存放的地址=%p ", &arr);
        arr++;
    }

    avg = (double) sum/size;
    return avg;
}

// 说明