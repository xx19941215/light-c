#include <stdio.h>

struct Cat {
    char * name;
    int age;
    char * color;
};

//在定义结构体的同时定义结构体变量
struct Stu{
    char *name; //姓名
    int num; //学号
    int age; //年龄
    char group; //所在学习小组
    float score; //成绩
} stu1, stu2;

// 匿名结构体
struct { //没有写 Stu 
    char *name; //姓名
    int num; //学号
    int age; //年龄
    char group; //所在学习小组
    float score; //成绩
} stu1, stu2;



void main() {
    struct Cat cat1; // cat1 就是 struct Cat 的一个变量
    cat1.name = "xiao";
    cat1.age = 3;
    cat1.color = "white";


    printf("\n 第 1 只猫 name=%s age=%d color=%s", cat1.name, cat1.age, cat1.color);
    
    struct Robot
    {
        char *name;
        char *version;
    } robot1 = {"xiao", "1.0"}, robot2 = {"test", '1.1'};

    //或者在定义结构体变量时，整体赋值，需要对应
    struct Robot robot3 = {"beta", "1.2"};
    
    
    
}

// 说明