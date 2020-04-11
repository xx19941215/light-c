#include <stdio.h>

void main() {
    //键盘输入语句
    char name[10] = "";
    int age = 0;
    double sal = 0.0;
    char gender = ' ';

    printf("请输入名字");
    scanf("%s", name);

    printf("请输入年龄");
    scanf("%d", &age);

    printf("请输入薪水");
    scanf("%lf", &sal);


    printf("请输入性别(m/f)");
    scanf("%s", &gender);

    printf("\nname %s age %d sal %.2f gender %c", name, age, sal, gender);

}

// 说明