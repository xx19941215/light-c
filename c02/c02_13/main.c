#include <stdio.h>

void printStar(int totalLevle)
{
    int i, j, k;
    for (i = 1; i <= totalLevle; i++)
    { //控制层
        //输出空格, 使用 k 控制空格的循环
        for (k = 1; k <= totalLevle - i; k++)
        {
            printf(" ");
        }

        for (j = 1; j <= 2 * i - 1; j++)
        {
            if (j == 1 || j == 2 * i - 1 || i == totalLevle)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}

void print99()
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d*%d=%d\t", i, j, i*j);
        }

        printf("\n");
        
    }
    
}

void main()
{
    //字符串函数
    // int totalLevel = 0;
    // printf("请输入金字塔的层数");
    // scanf("%d", &totalLevel); 
    //调用函数
    // printStar(totalLevel);
    print99();
}

// 说明