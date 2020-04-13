#include <stdio.h>
#include <stdlib.h>

void main() {
    //字符串函数
    //基本数据类型和字符串类型的转换
    //1.基本类型转字符串类型
    char str1[20];
    char str2[20];
    char str3[30];

    int a = 20984, b = 48090;
    double d = 14.322323;

    sprintf(str1, "%d %d", a, b);
    sprintf(str2, "%.2f", d);
    sprintf(str3, "%8.2f", d);//%8.2f 含义是格式化后，一共有 8 位，小数点后占用 2 位， 不够用空格占位

    printf("str1=%s str2=%s str3=%s\n", str1, str2, str3);

    //2.字符串类型转基本数据类型
    char str4[10] = "123456"; 
    char str5[10] = "12.67423";
    char str6[3] = "ab"; 
    char str7[4] = "111";

    int num1 = atoi(str4);
    short s1 = atoi(str7);

    double f = atof(str5);
    char c = str6[0];//表示数组第一个元素
    printf("num1=%d f=%f c=%c s1=%d", num1, f, c, s1);
}

// 说明
// 1.在将char数组类型转成基本数据类型时，要确保能够转成有效的数据，比如我们可以把"123",转成一个 整数，但是不能把 "hello" 转成一个整数
// 2.如果格式不正确，会默认转成 0 或者 0.0