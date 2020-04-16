#include <stdio.h>
#include <string.h>

void main()
{
    //字符串函数
    char str1[12] = "Hello";
    char str2[12] = "World";
    char str3[12];
    int len;

    /* 复制 str1 到 str3 */
    strcpy(str3, str1);                         // str3 内容 "Hello"
    printf("strcpy( str3, str1) : %s\n", str3); //"Hello"
    /* 连接 str1 和 str2 */
    strcat(str1, str2);
    printf("strcat( str1, str2): %s\n", str1); //"HelloWorld"

    /* 连接后，str1 的总长度 */
    len = strlen(str1);                 //
    printf("strlen(str1) : %d\n", len); //10

    char str4[]={"I am happy"}; // 默认后面加 '\0'
    char str5[]="I am happy"; // 省略{}号 ,默认后面加 '\0'
    char str6[]={'I',' ','a','m',' ','h','a','p','p','y'}; // 字符数组后面不会加 '\0', 可能有乱码 
    char str7[5]={'C','h','i','n','a'}; //字符数组后面不会加 '\0', 可能有乱码
    char * pStr = "hello";//ok

    printf("\n str4=%s", str4); 
    printf("\n str5=%s", str5);
    printf("\n str6=%s", str6);
    printf("\n str7=%s", str7);

}

// 说明
// 1.程序中往往依靠检测 '\0' 的位置来判定字符串是否结束，而不是根据数组的长度来决定字符串长度。因此，字 符串长度不会统计 '\0', 字符数组长度会统计
// 2.在定义字符数组时应估计实际字符串长度，保证数组长度始终大于字符串实际长度，否则，在输出字符数组 时可能出现未知字符.
// 3.系统对字符串常量也自动加一个'\0'作为结束符。例如"CProgram”共有9个字符，但在内存中占10个字节， 最后一个字节'\0'是系统自动加上的。(通过 sizeof()函数可验证)
// 4.定义字符数组时，如果 给的字符个数 比 数组的长度小，则系统会默认将剩余的元素空间，全部设置为 '\0', 比 如 char str[6] = "ab" , str 内存布局就是[a][b][\0][\0][\0][\0]