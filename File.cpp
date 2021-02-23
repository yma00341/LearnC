#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
/*
磁盘上的文件就是文件
但是程序设计中的文件一般分为：
程序文件：.c、.h、.obj、.exe
数据文件：程序运行时需要从中读取数据的文件
文件名：文件路径、文件名主干、文件后缀
例如:c:\code\test.txt
文件标识常备成为文件名

文件类型：
数据文件被成为文本文件或者二进制文件
数据在内存中以二进制IDE形式存储，如果不加转换的输出到外存，就是二进制文件
如果外存要求以ASCII嘛的形式存储，需要存储前转换，这种就是文本文件

字符一律以ASCII码值的形式存储，数值型数据可以用ASCII形式存储，也可以使用二进制存储

文件缓冲区：
ASCII标准采用缓冲文件系统来处理文件，系统自动在内存中为每一个正在使用的文件开辟一块文件缓冲区
从内存向磁盘输出的数据会先送到内存中的缓冲区，装满缓冲区后再仪器送到磁盘中
如果磁盘向计算机读入数据，则从磁盘文件中先读取数据输入到内存缓冲区(充满缓冲区)
再从缓冲区逐个将数据送到程序数据区(程序变量等)，缓冲区大小根据C编译系统决定

文件指针：存放文件的相关信息
通过文件指针变量能够找到与之相关联的文件
FILE* pf;
在文件读写之前应该先打开文件，使用结束后关闭文件
打开:FILE * fopen(const char* filename,const char* mode);
			//fopen函数返回一个FILE*类型的指针变量指向该文件
			//..表示上一级路径，.表示当前路径
			fopen("../test.txt","r");		//相对路径写法
			fopen("c:\\Desktop\\project\\test.txt","r");		//绝对路径写法


*/

/*
文件使用方式				如果文件不存在
"r"			只读			报错
"w"			只写			会新建一个文件，老文件的内容会销毁
"a"			追加			报错
"rb"		二进制读		出错
"wb"		二进制写		建立新文件
"ab"		二进制文件追加	出错
"r+"		读写			出错
"w+"		读写			创建新文件
"a+"		追加读写		建立新文件
"rb+"						出错
"wb+"						建立新文件
"ab+"						建立新文件
*/



/*
字符输入函数		fgetc				从输入流中读取数据
字符输出函数		fputc				向输出流中写入数据
文本行输入函数		fgets				从输入流中读取数据
文本行输出函数		fputs				向输出流中写入数据
格式化输入函数		fscanf				从输入流中读取数据
格式化输出函数		fprintf				向输出流中写入数据，即将结果输出到文件
二进制输入			fread				读取数据
二进制输出			fwrite				写入数据
char buf[1024] = {0};
fgets(buf,1024,pf);			fgets(buf,7,stdin);	//从标准输入流即输入缓冲区里读取7个字符
												//键盘是标准输入流的一种设备
//数据读出来存入buf，读1024个字符，去pf中去读，文件的一行，会读取\n
fwrite(const void* buffer,size_t size,size_t count,FILE* stream)
	buffer:数据源头的指针
	size:数据元素大小
	count:最大的被写入元素个数
	stream:文件流的地址，即文件指针
fread与fwirte对应，参数类型相同





scanf/fscanf/sscanf
printf/fprintf/sprintf

scanf/printf:针对标准输入输出流的格式化输入输出语句
fscanf/fprintf:针对所有输入输出流的格式化输入输出语句，如果选择标准的，就在指针地方选择 stdin 和 stdout
sscanf/sprintf:从字符串中读取格式化的数据	把格式化的数据输出成(存储到)字符串

struct S
{
	int n;
	float score;
	char arr[10];
}
int main()
{
	struct S s = {100,314f,"abcdef" };
	struct S t = {0};
	char buf[1024] = {0};
	//把s中的数据输出成字符串存到buf中
	sprintf(buf,"%d %f %s",s.n,s.score,s.arr);
	printf("%s\n",buf);
	//把buf中的字符串数据读取并格式化到结构体变量t中
	sscanf(buf,"%d %f %s",&(t.n),&(t.score),t.arr);
	printf("%d %f %s",t.n,t.score,t.arr)
	return 0;
}


fseek(FILE *stream,long offset,int origin)
	文件指针		偏移量		源位置SEEK_CUR(当前位置)	SEEK_END(文件末尾)	SEEK_SET(文件开始)
ftell - 返回文件指针相对起始位置的偏移量
rewind - 回到文件指针起始位置
feof - 在已知失败的情况下，判断文件读取结束时是什么原因导致的，是否是文件尾自然结束
fread - 返回的是实际读取文件的个数，加入你要求读10个，但是返回值是5，证明读取出问题
perror - 返回错误信息，比strerror好用
perror("hehe");//内部写相应的错误地点，自己写
*/
//示例
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("open file text.txt");
//		return 0;
//	}
//	char ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		putchar(ch);
//	}
//	if (ferror(pf))
//	{
//		//读取错误结束
//		printf("error\n");
//	}
//	else if (feof(pf))
//	{
//		//读取到文件末尾结束
//		printf("end of file\n");
//	}
//	fclose(pf);
//	pf = NULL;
//}


int main()
{
	char arr[10];
	char arr1[10];
	char* str;
	//打开文件
	FILE *pf = fopen("test.txt", "wt+");
	//假设tset.txt文件存在，函数会根据文件内容内存中开辟一个文件信息区，并自动填充信息区内容
	//把文件信息区的起始地址返回
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
	}
	//向输出流中写入数据
	scanf("%s", arr);
	//从输出流arr中读取数据输出到文件上，相当于把数据写入文件
	fprintf(pf,"%s", arr);
	rewind(pf);
	//从输入流中读取数据，即从文件中读出数据放到arr1
	fscanf(pf, "%s", arr1);
	printf("%s", arr1);
	fclose(pf);
	pf = NULL;
	return 0;
}