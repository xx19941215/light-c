#include<stdio.h>
#include<string.h>
int main()
{
	char ch,a[10],b[10];
	// scanf("%c",a);
	//%c才用getchar吃回车
	ch=getchar();
	if (ch == 10) {
		printf("打了空格\n");
	} else {
		//不是空格 保存字符
		// printf("ch=%c\n", ch);
		printf("没打空格\n");
		scanf("%s",b);
		strcat(a, &ch);
		strcat(a, b);
		printf("a=%s\n",a);
	}

	// printf("ch=%c\n",ch);
	// scanf("%s",b);
	// strcat(b, ch);
	// printf("a=%s\n",a);
	// printf("b=%s\n",b);
	// if (b[0] ==  10) {
	// 	printf("多少k");
	// }
}