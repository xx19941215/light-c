#include <stdio.h>
const int MAX = 3;

int main() {
    //指针数组
    // 要让数组的元素 指向 int 或其他数据类型的地址(指针)。可以使用指针数组。
    int var[] = {10, 100, 200};
    int i, *ptr[3];

    for (i = 0; i < MAX; i++)
    {
        ptr[i] = &var[i]; //赋值为整数的地址
    }
    

    for (i = 0; i < MAX; i++)
    {
        printf("Value of var[%d]=%d ptr[%d]本身的地址是=%p\n", i, *ptr[i], i, &ptr[i]); // 10, 100, 200
    }

    char *books[] = {
        "西游记",
        "三国演义",
        "红楼梦",
        "水浒传"
    };


    char *pStr = "abc";

    int len = 4;

    for (i = 0; i < len; i++)
    {
        printf("\nbooks[%d]指向的字符串是%s, pStr指向的内容是=%s", i, books[i], pStr);
    }
    
    return 0;
    
}

// 说明