#include <stdio.h>

void main() {
    //强制类型转换
    //1. 将精度高的数据类型转换为精度底的数据类型 使用时要加上强制转换符 () 但是可能造成精度降低 或者益处 所以要格外注意
    //2. 强制类型转换一般格式如下 (类型名) 表达式 这种强制转换并不改变 操作数本身

    double d1 = 156.89;
    int num1 = (int) d1;

    printf("num1=%d d1=%f", num1, d1);

    char c = 'a';
    int i = 5;
    float d = .314F;
    double d2 = 1.0;
    double result = c + i + d; // float -> double 
    char result2 = c + i + d + d2; // double -> char
}

// 说明
// 1.当进行数据的从 精度高到精度底 就需要强制类型转换
// 2.强制转换符号只针对于最近的操作数有效 往往会使用小括号提升优先级 