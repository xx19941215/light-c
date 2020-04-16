#include <stdio.h>

void f1(int arr[])
{
    printf("\nf1 函数中 的 arr 的地址 = %p", arr); 
    arr[0] = arr[0] + 1;

}

void main() {
    //数组
    //第一种初始化方式
    double hens[6];
    double totalWeight = 0.0;
    double avgWeight = 0.0;

    int i, arrLen;
    //初始化数组元素
    hens[0] = 3.0;
    hens[1] = 2;
    hens[2] = 3;
    hens[3] = 4;
    hens[4] = 6;
    hens[5] = 7;

    //遍历数组
    arrLen = sizeof(hens) / sizeof(double);

    for (i = 0; i < arrLen; i++)
    {
        totalWeight += hens[i];
    }

    avgWeight = totalWeight/6;
    printf("总体重 totalWeight=%.2f 平均体重 avgWeight=%.2f", totalWeight, avgWeight);

    //第二种初始化方式
    int arr2[3] = {10,20,30};
    //第三种初始化方式
    int arr3[] = {110, 220, 800};

    f1(arr2);

    for (i = 0; i < 3; i++)
    {
        printf("\narr2[%d]=%d\n", i, arr2[i]);
    }
    

    double arr[5];

    int arrLen2 = sizeof(arr)/sizeof(double);

    for (i = 0; i < arrLen2; i++)
    {
        printf("\n请输入一个小数");
        scanf("%lf", &arr[i]);//%lf代表长浮点型 
    }
    
    printf("\n============\n");
    for (i = 0; i < arrLen2; i++)
    {
        printf("arr[%d]=%.2f", i, arr[i]);
    }
}

// 说明
// 1.数组名就代表该数组的首地址，即a[0]地址
// 2.数组的各个元素是 连续分布的， 假如 a[0] 地址 0x1122 a[1] 地址= a[0]的地址+int 字节数(4) = 0x1122 + 4 = 0x1126,后面 a[2] 地址 = a[1]地址 + int 字节数(4) = 0x1126 + 4 = 0x112A, 依次类推
// 3.数组是多个相同类型数据的组合,一个数组一旦声明/定义了,其长度是固定的, 不能动态变化。
// 4.数组创建后，如果没有赋值，则遵守如下规则 全局数组默认值 0 非全局数组初值是机器垃圾值(即:原来系统分配给这块空间的值)
// 5.使用数组的步骤 1. 定义数组 2 给数组各个元素赋值 3 使用数组, 也可以一步到位
// 6.数组的下标是从0开始的,不是从1开始。
// 7.数组下标必须在指定范围内使用，编译通过，在运行时会因为数组越界而异常中断: 比如 int arr [5] 有效下标为 0-4
// 8.C 的数组属构造类型， 是引用传递(传递的是地址)，因此当把一个数组传递给一个函数时/或者变量，函数/变量操作数组会影响到原数组. 