#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

//真实传递给函数的参数叫实参，实参可以是常量、变量、表达式、函数等，无论实参是何种类型的值，他们都必须是确定的值
//形参是函数名括号中的变量，只有在函数被调用过程中才会实例化，形参只有在函数中才会有效

//int is_Prime(int x)		//素数判断函数,素数返回1，不是返回0
//{
//	int i;
//	for (i = 2; i < x / 2; i++)
//	{
//		if (x%i == 0)
//			return 0;
//	}
//	return 1;
//}

//int binary_search(int arr[], int k, int size)//找到了返回下标，没找到返回-1
//{
//	int left, right, mid;
//	//size = sizeof(arr) / sizeof(arr[0]);		//由于数组传进来实际上是数组首元素的地址，所以此方法算出来结果为1，因此size放到外面算
//	left = 0;
//	right = size - 1;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}


//递归函数   把大事化小
//必须存在限制条件，且每次递归要越来越接近限制值，当满足限制值之后停止递归
//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//	printf("%d ", x % 10);
//}
//int main()
//{
//	int m;
//	scanf("%d", &m);
//	print(m);
//	return 0;
//}



//计算字符串长度递归
int my_Strlen(char * str)
{
	if (*str != '\0')
	{
		return 1 + my_Strlen(str+1);
	}
	else
		return 0;
}
int main()
{
	char arr[] = "abc";
	int len = my_Strlen(arr);
	printf("len = %d", len);
	return 0;
}


//递归计算阶乘
//int Fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//		return n*Fac(n - 1);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", Fac(n));
//	return 0;
//}


//斐波那契数列经典递归
//int Fib(int n)	//此函数效率极低，因为大量的重复计算Fib函数
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int Fib(int n)	//初次修改使用循环的方式
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
