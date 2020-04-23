#include <stdio.h>
#define TOTAL 2

struct Person
{
    char name[20];
    int num;//编号
    char sex;//性别
    char profession;//s 学生 t老师
    union {
        float score;//4字节
        char course[20];// 20字节
    } sc;
};


void main() {
    int i;
    struct Person persons[TOTAL];
    for (i = 0; i < TOTAL; i++)
    {
        printf("Input info:");
        scanf("%s %d %c %c", persons[i].name, &persons[i].num, &persons[i].sex, &persons[i].profession);
        if (persons[i].profession == 's') {
            printf("请输入该学生成绩:");
            scanf("%f", &persons[i].sc.score);
        } else {
            printf("请输入老师课程:");
            scanf("%s", persons[i].sc.course);
        }

        fflush(stdin);
    }

    printf("\nName\t\tNum\tSex\tProfession\tScore / Course\n");
    for(i=0; i<TOTAL; i++){
        if (persons[i].profession == 's') {
            printf("%s\t\t%d\t%c\t%c\t\t%f\n", persons[i].name, persons[i].num, persons[i].sex, persons[i].profession,persons[i].sc.score);
        } else {
            printf("%s\t\t%d\t%c\t%c\t\t%s\n", persons[i].name, persons[i].num, persons[i].sex, persons[i].profession, persons[i].sc.course);
        }
    }
}

// 说明