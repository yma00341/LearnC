#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

//��ʵ���ݸ������Ĳ�����ʵ�Σ�ʵ�ο����ǳ��������������ʽ�������ȣ�����ʵ���Ǻ������͵�ֵ�����Ƕ�������ȷ����ֵ
//�β��Ǻ����������еı�����ֻ���ں��������ù����вŻ�ʵ�������β�ֻ���ں����вŻ���Ч

//int is_Prime(int x)		//�����жϺ���,��������1�����Ƿ���0
//{
//	int i;
//	for (i = 2; i < x / 2; i++)
//	{
//		if (x%i == 0)
//			return 0;
//	}
//	return 1;
//}

//int binary_search(int arr[], int k, int size)//�ҵ��˷����±꣬û�ҵ�����-1
//{
//	int left, right, mid;
//	//size = sizeof(arr) / sizeof(arr[0]);		//�������鴫����ʵ������������Ԫ�صĵ�ַ�����Դ˷�����������Ϊ1�����size�ŵ�������
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


//�ݹ麯��   �Ѵ��»�С
//�������������������ÿ�εݹ�ҪԽ��Խ�ӽ�����ֵ������������ֵ֮��ֹͣ�ݹ�
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



//�����ַ������ȵݹ�
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


//�ݹ����׳�
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


//쳲��������о���ݹ�
//int Fib(int n)	//�˺���Ч�ʼ��ͣ���Ϊ�������ظ�����Fib����
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//int Fib(int n)	//�����޸�ʹ��ѭ���ķ�ʽ
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
