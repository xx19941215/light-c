#include <stdio.h>

void main() {
    // \t制表符
    // \n换行
    printf("北京\t上海\t天津\n");
    // \\输出一个斜杠
    printf("输出一个斜杠\\");
    //\r输出一个回车（回车不是换行）
    printf("Who is Coding?\rXiao");
    getchar();
}

//变量的数据类型
//1.基本类型 有数值类型（整型short int long、浮点型float double）、字符类型char
//2.构造类型有数组、结构体struct、共用体union、枚举类型enum
//3.指针类型
//4.空void
//5.C没有字符串类型 使用的字符数组表示字符串
//6 不同系统上 部分数据类型字节长度不一样