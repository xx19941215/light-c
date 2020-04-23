#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARR_LEN 1000

enum TYPE {IN = 1, OUT = 2};

typedef struct Flow
{
    enum TYPE type;
    double amount; 
    double total; 
    char des[100]; 
} Flow;

void printMenu();
void doFlow(int type, double amount, char * des, Flow flows[], int currentLen);
char * flowDetail(Flow flows[], int currentLen, char * str);
double * calcTotal(Flow flows[], int currentLen);




int main() {
    char operate;
    Flow flows[ARR_LEN];
    int currentLen = 0;
    char detail[10000];
    char str[1000];

    do
    {
        rewind(stdin);
        printMenu();
        printf("请输入操作\n");
        // printf("operate：%c", operate);
        scanf("%c", &operate);
        

        switch (atoi(&operate))
        {
            case 1:{
                strcpy(detail, "---------当前收支明细记录---------\n收支\t收支金额\t账户金额\t说明\n");
                // printf("出鬼了%s", detail);
                strcpy(str, "");
                flowDetail(flows, currentLen, str);
                strcat(detail, str);
                printf("%s", detail);
                break;
                }
                
            case 2: {
                enum TYPE type = 0;
                double amount = 0.0;
                char des[10];
                type = IN;
                printf("请输入金额\n");
                scanf("%lf", &amount);
                printf("%.2f", amount);
                printf("请输入说明\n");
                scanf("%s", des);
                printf("%s", des);
                doFlow(type, amount, des, flows, currentLen);
                currentLen++; 
                break;
            }
                
            case 3: {
                enum TYPE type = 0;
                double amount = 0.0;
                char des[10];
                type = OUT;
                printf("请输入金额\n");
                scanf("%lf", &amount);
                printf("请输入说明\n");
                scanf("%s", des);
                doFlow(type, amount, des, flows, currentLen);
                currentLen++;
            break;
            }
               
        
            default:
            break;
        }

        operate = ' ';

    } while (atoi(&operate) != 4);

    free(flows);

    return 0;
    
}

// 说明
void printMenu()
{
    printf("-----------家庭收支软件-----------\n");
    printf("1.收支明细\n");
    printf("2.登记收支\n");
    printf("3.登记支出\n");
    printf("4.退    出\n");
}

void doFlow(int type, double amount, char des[], Flow flows[], int currentLen)
{
    double* currentAmount = calcTotal(flows, currentLen);
    int a = *currentAmount;
    // printf("currentAmount=%.2f\n", *currentAmount);
    if (type == IN) {
        a += amount;
    } else {
        a -= amount;
    }
    char des1[100];
    strcpy(des1, des);
    Flow new;
    new.amount = amount;
    new.type = type;
    new.total = a;
    strcpy(new.des, des1);
    // 重置静态变量为0
    *currentAmount = 0;

    flows[currentLen] = new;
}

char * flowDetail(Flow flows[], int currentLen, char* str)
{
    for (int i = 0; i < currentLen; i++)
    {
        char str1 [200] = "";
        char * type;
        if (flows[i].type == IN) {
            type = "收入";
        } else {
            type = "支出";
        }

        sprintf(str1, "%s\t%.2f\t%.2f\t%s\n", type, flows[i].amount, flows[i].total, flows[i].des); 
        strcat(str, str1); 
    }

    return str;
}

double * calcTotal(Flow flows[], int currentLen)
{
    double static total = 0.00;

    for (int i = 0; i < currentLen; i++)
    {
        Flow currentFlow = flows[i];
        if (currentFlow.type == IN) {
            total += currentFlow.amount;
        } else {
            total -= currentFlow.amount;
        }
    }

    return &total;
}