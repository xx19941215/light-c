#include <stdio.h>
#include <string.h>

void main()
{
    //字符数组
    // 1.用来存放字符的数组称为字符数组
    //  1.char a[10]; //一维字符数组, 长度为 10
    //  2.char b[5][10]; //二维字符数组, 后面我们详细介绍二维数组
    //  2.char c[20]={'c', ' ', 'p', 'r', 'o', 'g', 'r', 'a','m'}; // 给部分数组元素赋值
    // 2.字符数组实际上是一系列字符的集合，也就是字符串(String)。在 C 语言中，没有专门的字符串变量，没有 string 类型，通常就用一个字符数组来存放一个字符串
    // 3.在 C 语言中，字符串实际上是使用 null 字符 ('\0') 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。
    // 4.'\0'是 ASCII 码表中的第 0 个字符，用 NUL 表示，称为空字符。该字符既不能显示，也不是控制字符，输出该 字符不会有任何效果，它在 C 语言中仅作为字符串的结束标志。

    char str[3] = {'a', 'b', 'c'};  //乱码
    char str2[2] = {'t', 'o', 'm'}; //乱码
    printf("\nstr=%s", str);
    printf("\nstr2=%s", str2);
    //如果在给某个字符数组赋值时，(1)赋给的元素的个数小于该数组的长度，则会自动在后面加 '\0', 表示字符串结束，(2)赋给的元素的个数等于该数组的长度，则不会自动添加 '\0'

    char c[7] = {'t', 'o', 'm'};
    char str3[4] = {'a', 'b', 'c', '\0'};
    char str4[] = {'j', 'a', 'c', 'k'};

    printf("\nc=%s", c);       //tom
    printf("\nstr3=%s", str3); // abc
    printf("\nstr4=%s", str4); // jack 乱码

    char greeting[] = "Hello";
    int i;
    int len = strlen(greeting);

    printf("\n greeting=%s", greeting);
    printf("\nlen=%d", len);                          //5
    printf("\n 字符串第 3 个字符是=%c", greeting[2]); //l printf("\n");
    for (i = 0; i < len; i++)
    { //遍历
        printf("%c ", greeting[i]);
        //H e l l o
    }
}

// 说明