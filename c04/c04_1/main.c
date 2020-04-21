#include <stdio.h>
#include <string.h>

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
} stu3, stu4;

struct Dog
{
    char * name;
    int age;
    double weight;
};

struct Visitor
{
    char name[10];
    int age;
    double pay;
};

//因为结构体默认是值传递，会拷贝一份完整数据，效率较低
//为了提高效率，我们直接接收地址(指针)
void ticket(struct Visitor *visitor)
{
    if ((*visitor).age > 18) {
        (*visitor).pay = 20;
    } else {
        (*visitor).pay = 0;
    }
}

char * say(struct Dog dog)
{
    static char info[50];//局部静态变量
    sprintf(info, "name=%s age=%d weight=%.2f", dog.name, dog.age, dog.weight);
    return info;
}

int main() {
    struct Cat cat1; // cat1 就是 struct Cat 的一个变量
    cat1.name = "xiao";
    cat1.age = 3;
    cat1.color = "white";


    printf("\n 第 1 只猫 name=%s age=%d color=%s", cat1.name, cat1.age, cat1.color);
    
    struct Robot
    {
        char *name;
        char *version;
    } robot1 = {"xiao", "1.0"}, robot2 = {"test", "1.1"};

    //或者在定义结构体变量时，整体赋值，需要对应
    struct Robot robot3 = {"beta", "1.2"};
    struct Dog dog;

    char * info;

    dog.age = 10;
    dog.name = "test";
    dog.weight = 12.34;

    info = say(dog);//结构体变量默认是值传递
    printf("\n 小狗信息=%s", info);
    printf("\n main 小狗名字=%s", dog.name);

    struct Visitor visitor;
    while (1) {
        printf("\n 请输入游客名字");
        scanf("%s", visitor.name);
        if(!strcmp("n", visitor.name) ) {
            break; 
        }

        printf("\n 请输入游客年龄");
        scanf("%d", &visitor.age);
        ticket(&visitor);
        printf("\n 该游客应付票价=%.2f", visitor.pay);
    };

    return 0;
}

// 说明
// 1.成员声明语法同变量，示例:数据类型成员名;
// 2.字段的类型可以为:基本类型、数组或指针、结构体等
