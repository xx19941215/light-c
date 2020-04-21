#include <stdio.h>

//共用体
union data
{
    // data 就是一个共用体(内存布局)， 包含三个成员, 共享数据空间, 该空间的大小以占用最大的成员为准
    int n;//4个字节
    char ch;//1个字节
    short m;//2个字节
};

void main() {
    union data a;//定义两个一个 共用体变量 a
    printf("%d, %d\n", sizeof(a), sizeof(union data));//4, 4
    a.n = 0x40;
    printf("%d, %c, %d\n", a.n, a.ch, a.m);
    a.ch = '9'; //
    printf("%d, %c, %d\n", a.n, a.ch, a.m);
    a.m = 0x2059;
    printf("%d, %c, %d\n", a.n, a.ch, a.m);
    a.n = 0x3E25AD54;
    printf("%d, %c, %d\n", a.n, a.ch, a.m);
}

// 说明
// 1.结构体和共用体的区别在于:结构体的各个成员会占用不同的内存，互相之间没有影响;而共用体的所有成员 占用同一段内存，修改一个成员会影响其余所有成员