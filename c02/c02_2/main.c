#include <stdio.h>

void main() {
    //枚举
    enum DAY{
        MON = 1, TUE = 2, WED = 3, THU = 4, FRI = 5, SAT = 6, SUN = 7
    };//这里DAY就是枚举类型 包含了7个枚举元素

    enum DAY day; //enum DAY 是枚举类型 day 就是枚举变量
    day = WED; // 给枚举变量day赋值 值就是某个枚举元素

    printf("%d", day);//每个枚举元素对应一个值

    //枚举的遍历
    for (day = MON; day <= SUN; day++)
    {
        printf("枚举元素：%d\n", day);
    }

    //switch使用枚举
    enum SEASONS {
        SPRING = 1, SUMMER, AUTUMN, WINTER
    };

    enum SEASONS season;

    printf("请输入你喜欢的季节：（1.spring 2.summer 3.autumn 4.winter）");
    scanf("%d", &season);
    switch (season)
    {
        case SPRING:
        printf("你喜欢春天\n");
        break;
        case SUMMER:
        printf("你喜欢夏天\n");
        break;
        case AUTUMN:
        printf("你喜欢秋天\n");
        break;
        case WINTER:
        printf("你喜欢冬天\n");
        break;
        default:
        printf("你没有选择\n");
        break;
    }

    enum STATUS {PENDDING = 1, HANDLE, FINISHED};
    enum STATUS status;

    int n = 2;
    status = (enum STATUS) n;
    printf("status=%d", status);

}

// 说明
// 1.C语言中 枚举是被当作int或者unsigned int 来处理的 枚举类型必须连续是可以实现有条件的遍历
// 2.第一个枚举成员的默认值为整形0，后续的枚举成员的值在前一个成员加1，如果没有赋值 就会自动按照顺序赋值
// 3.枚举变量的定义形式 首先定义枚举类型 再定义枚举变量
// 4.还可以在定义枚举类型的时候直接定义枚举变量
// emum DAY {MON, TUE} day;
// 5.可以省略枚举名称 直接定义枚举变量 但是这样的形式的枚举变量只可以使用一次 
// enum {MON, TUE} day;
// 6.可以将整数转换为对应的枚举值 不可以直接将一个整数 赋值给枚举变量 但是可以将整数转成枚举类型 再赋给枚举变量
