#include <stdio.h>

void main() {
    int b = 10; //b指向内存一片空间 保存着10
    int d = 3;//d指向内存一片空间 保存着3
    d = 10; //把空间保存的值修改为10
    printf("b is %d\n", b); //%d表示输出为整型
    getchar();
    test();
}

test() {
    int num = 1;
    double score = 2.3;
    char gender = 'A';
    char name[] = "xiao";

    //如果输出是整数使用%d表示
    //如果输出是小数数使用%f表示 保留2位小数使用.2f
    //如果输出是字符使用%c表示
    //如果输出是字符串使用%s表示
    printf("num=%6d score=%.2f gender=%c name=%s", num, score, gender, name);
}

//变量的注意事项
//1.变量表示内存中的一个存储区域 不用的数据类型 占用的空间大小不一致
//2.变量有自己的名称和类型
//3.变量必须先声明后使用
//4.该区域的数据可以在同一范围内不断变化
//5.变量在同一个作用域内不能重名
//6.变量三要素 变量名+值+数据类型