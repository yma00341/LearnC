#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

//int main()
//{
//	//数组的本质
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//		//[]下标引用操作符
//	int i = 0;
//	int size = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < size; i++)
//	{
//		printf("%p\n", &arr[i]);
//		//地址之间是连续的且差4个字节，即存储一个int型元素所需要的空间
//	}
//	return 0;
//}


//数组名
//int main()
//{
//	int arr[4] = { 1, 2, 3, 4 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	printf("%d\n", *arr);
//	//数组名实质上是数组首元素的地址
//	//但是有两个例外
//	//1.sizeof
//	printf("%d\n", sizeof(arr));
//	//此时的数组名表示整个地址,算出来的单位是字节
//	//2.&arr，数组名代表整个数组，取出的是整个数组的地址
//	printf("%p\n", &arr);
//	//取出的是整个数组的地址，但是打印的结果其实和上述的相同，注意区别
//	
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);		//加了4个字节
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);		//加了4个字节
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);		//加了16个字节
//
//}

//二维数组
//int main()
//{
//	int arr[3][4] = { { 1, 2, 3 }, { 3, 4, 5, 6 }, { 7, 8, 9, 10 }};
//	//二维数组的列不能省略创建的时候
//	int i, j;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4 ; j++)
//		{
//			printf("&arr[%d][%d] = %p \n", i, j, &arr[i][j]);
//			//二维数组存储的时候也是连续的
//		}
//		
//	}
//	return 0;
//}


//冒泡排序
void bubble_sort(int *arr,int size)
{
	int i, j,temp;
	for (i = 0; i < size - 1; i++)
	{
		//需要多少元素个数-1趟冒泡排序
		int flag = 1;	//flag标志假设此趟排序是有序的,此为优化方案
		for (j = 0; j < size - i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 0;
				//交换后，此趟无序，flag置0
			}
			
			//此处的break是作用于循环的
			//原则上break只能作用于循环之中或者switch
		}
		if (flag == 1)
				break;
	}
}
int main()
{
	int i;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, size);
	//传的参数arr其实是&arr[0],所以本质上是一个指针
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}




