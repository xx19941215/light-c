#include <stdio.h>

void main() {
    //字符数组
    char name[10] = "xiao";
    //短整型
    short age = 23;
    //单精度浮点型
    float score = 78.5f;

    //字符型
    char gender = 'M';
    char hobby[20] = "篮球足球";

    printf("姓名\t年龄\t成绩\t性别\t爱好\n%s\t%d\t%.2f\t%c\t%s", name, age, score, gender, hobby);
}

// 说明