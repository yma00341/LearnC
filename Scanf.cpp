//此源文件为了展示 scanf的不同输入以及读取情况

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//#include <stdio.h> 
//int main()
//{
//	//输入 i love you！只会输出i
//	//scanf遇到空格读取停止
//	char str[80];
//	char ch;
//	scanf("%s", str);
//	printf("%s\n", str);
//	//解决方法
//	while ((ch = getchar()) != '\n')
//	{
//	}
//	scanf("%[^\n]", str);
//	printf("%s\n", str);
//	return 0;
//}

//解决方法
//#include <stdio.h> 
//int main()
//{
//	char str[80];
//
//	scanf("%[^\n]", str); //读到'\n'结束读取
//	printf("%s", str);
//	return 0;
//}

//读到'\n'结束读取,存入str,再抛弃一个字符
//scanf("%[^\n]%*c", str);

//读到'\n'结束读取,并将其读到的数据抛弃,然后再抛弃一个字符（这个字符是'\n'）
//此时缓存中不存在任何字符
//scanf("%*[^\n]%*c");


//int c;
//while ((c = getchar()) != '\n'&&c != EOF);
//读取一个字符，直到是\n或者是EOF停止
//等价于
//scanf("*[^\n]");

#include <stdio.h>
int main()
{
	char  c;
	//直到遇到字符a停止读取，
	//舍弃a
	//读取将a后的一个字符存入变量c
	scanf("%*[^a]%*c%c", &c);
	printf("%c\n", c);
	return 0;
}