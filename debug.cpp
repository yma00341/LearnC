#include <stdio.h>
#include <windows.h>
#include <assert.h>

//int main()
//{
//	int i = 0;
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	//此程序的结果为死循环，但是i判断条件改为 <= 11的时候就是报错，栈破坏
//	//由于栈区的使用方式默认是先使用高地址，此处是先创建i的
//	//由此，当数组越界访问之后，又可能a[12]便是i变量的存储区域
//	//此时i将会被改为0，由此便会发生死循环
//	//在VC 6.0环境下，<=10便会死循环
//	//在GCC 编译器下，<=11便会死循环
//	system("pause");
//	return 0;
//}


//字符串拷贝函数
//void my_strcpy(char* des, char* ori)	//此函数满分10分仅有7分
//{
//	while (*des++ = *ori++)
//	{
//		;
//	}
//}

//void my_strcpy(char* des, char* ori)	//8分
//{
//	assert(*des != NULL);	//断言，引用assert头文件
//	assert(*ori != NULL);	//会将错误提示出来
//	while (*des++ = *ori++)
//	{
//		;
//	}
//}

//char* my_strcpy(char* des, const char* ori)	//10分
//{
//	//const可以防止目的地和源地址两个变量写反
//	//假如写反会无法编译，提示左值指定const对象
//	//const放在指针变量的*左边修饰的是*p，即不能通过p来改变*p的值
//	//const放在指针变量的*右边修饰的是p，即p所代表的地址是不能被改变的
//	char* ret = des;
//	assert(*des != NULL);	//断言，引用assert头文件
//	assert(*ori != NULL);	//会将错误提示出来
//	//把ori指向的字符串拷贝到des指向的空间，包括'\0'
//	while (*des++ = *ori++)
//	{
//		;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[] = "################";
//	char arr2[] = "bit";
//
//	printf("%s\n", my_strcpy(arr1, arr2));
//	system("pause");
//	return 0;
//}




//字符串长度函数
int my_strlen(const char* ori)
{
	int count = 0;
	assert(ori != NULL);
	while (*ori != '\0')
	{
		count++;
		ori++;
	}
	return count;
}

int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);

	return 0;
}