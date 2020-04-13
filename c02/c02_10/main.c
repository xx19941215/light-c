#include <stdio.h>
#include <time.h>

void test()
{
    int i = 0;
    int sum = 0;
    int j = 0;

    for (i = 0; i < 80000000; i++) {
        sum = 0;
        for (j = 0; j < 10; j++) {
            sum += j;
        }
    }


}

void main() {
    //时间日期函数
    time_t curtime;
    // time(&curtime);

    printf("当前时间=%s", ctime(&curtime));
    time_t start_t, end_t;
    double diff_t;

    printf("程序启动");
    time(&start_t);

    test();
    time(&end_t);

    diff_t = difftime(end_t, start_t);

    printf("执行test()函数 耗时了%.2f秒", diff_t);
}

// 说明