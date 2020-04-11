#include <stdio.h>

void main() {
    //运算符
    //算术运算符 (+ - / %)
    double d1 = 10 / 4;
    //截取整数 结果是2.000000
    double d2 = 10.0 / 4;

    //取模公式 a % b = a - a / b * b
    int res3 = 10 % -3; //10 - 10 / 3 * 3 = 10 - 9 = 1

    printf("d1=%f d2=%f res3=%d", d1, d2, res3);

    //赋值运算符（= += -= *= /= %= <<= >>= &= ^= !=）
    //赋值运算可能截断小数点后的数字

    //关系运算符 (><)
    int a = 8;
    int b = 9;
    //会使用非0的值表示结果 默认是1
    printf("a > b = %d", a > b);
    //逻辑运算符 (&& || !)
    //位运算符 (& | ^ ~)
    //三元运算符 (?:)
}

// 说明
// 1.对于除号 它的整数除和小数除是有区别的 整数之间做除法的时候 只保留整数部分而舍弃小数部分
// 2.当自增当作一个独立语句使用时 ++i 和 i++ 没有区别
// 运算符优先级
// 1.运算符结合的方向 只有三个是从右向左 其余的都是从左向右
// 2.所有的双目运算符中的只有赋值运算符的结合方向是从右向左 另外2个是单目运算 还有一个是三目运算
// 3.逗号的优先级最低
// 4.算术运算符 > 关系运算符 > 逻辑运算符 (逻辑非除外) > 赋值运算符 > 逗号运算符
