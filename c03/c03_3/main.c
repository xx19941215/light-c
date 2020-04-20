#include <stdio.h>

void main() {
    //字符串的表现形式
    // 1.用字符数组存放一个字符串
    char str[]="hello tom";
    char str2[] = {'h', 'e'};
    // 2.用字符指针指向一个字符串
    char* pStr=" hello tom";
    //C 语言对字符串常量" hello tom"是按字符数组处理的，在内存中开辟了一个字符数组用来存放字符串常量，程 序在定义字符串指针变量 str 时只是把字符串首地址(即存放字符串的字符数组的首地址)赋给 pStr
    //printf("%s\n",str); 可以输出 str 指向的字符串

}

// 说明
// 1.字符数组由若干个元素组成，每个元素放一个字符;而字符指针变量中存放的是地址(字符串/字符数组的首地址)，绝不是将字符串放到字符指针变量中(是字符串首地址)
// 2.对字符数组只能对各个元素赋值，不能用以下方法对字符数组赋值
// char str[14];
// str=" hello tom"; //错误 
// str[0] = 'i'; //ok
// 3.对字符指针变量，采用下面方法赋值, 是可以的
// char* a="yes"; 
// a=" hello tom";
// 4.如果定义了一个字符数组，那么它有确定的内存地址(即字符数组名是一个常量);而定义一个字符指针变量时， 它并未指向某个确定的字符数据，并且可以多次赋值