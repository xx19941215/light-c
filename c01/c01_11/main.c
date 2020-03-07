#include <stdio.h>

void main() {
    //基本数据类型转换
    //1.在进行赋值或者运算时 精度小的类型自动转换为精度大的数据类型 这个就是自动类型转换
    //2.数据类型按精度大小排序为
    //short < int < unsigned int < long < unsigned long float < double < long double
    // 3.自动类型转换规则如下
    // double <- float
    //  ^
    //  |
    // long
    //  ^
    //  |
    // unsigned
    //  ^
    //  |
    // int  <- char, short
    char c1 = 'a';
    int num1 = c1;
    double d1 = num1;

    short s1 = 10;
    int s2 = 20;

    int num3 = s1 + s2;

    float f1 = 1.1f;
    double d2 = 4.5876567;

    f1 = d2; //精度损失
    printf("f1=%.7f", f1);
}

// 说明
// 1.有多种类型的数据混合计算时 系统首先将自动将所有的数据类型转换成精度最大的那个类型 然后再进行计算（如int型和short型运算时，先把short转换成int型再进行运算）
// 2.若2种类型的字节数不同 转换成字节数大的类型 若两种类型的字节数相同 且一种有符号 另外一种无符号 则转换成无符号类型
// 3.在赋值运算种 赋值号两边的数据类型不同时 赋值号右边的类型转换为左边的类型 如果右边的变量的数据类型长度比左边的长时 将丢失一部分数据 这样会降低精度 丢失部分数据。