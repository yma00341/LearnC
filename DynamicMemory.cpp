#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/*
内存的使用方式：
1.创建一个变量
int a = 10; //局部变量 - 栈区
int g_a = 10; //全局变量 - 静态区

2.创建一个数组
int arr[10] = {0};//栈空间开辟

3.假如创建一个可能会改变的大空间数组
动态内存分配(堆区)
malloc
free
calloc
realloc
*/


//malloc和free
/*
malloc
向内存申请一款连续可用的空间，并返回指向这块空间的指针
*如果开辟成功则返回指向开辟空间的指针
*如果开辟不成功则返回NULL
*返回值的类型是void* ，所以malloc函数并不知道返回的类型

free
*如果参数ptr指向的空间不是动态开辟的，那么free函数的行为是未定义的
*如果参数ptr是NULL指针，则函数什么都不做
*/



//calloc
/*
void *calloc(size_t num,size_t size);
num：元素的个数
size：每个元素的字节长度
**开辟空间并把元素初始化为0
*/


//realloc
/*
void* realloc(void* memblock,size_t size);
memblock:指向之前开辟的地址
size:新的空间大小(总体的)
调整动态开辟内存的大小
注意事项：(追加空间时)
*当后面空间足够的时候，直接调整，返回原先的p
*后面空间不足的时候，一次性开辟新的满足要求的空间，数据同时拷贝下来，把原先空间free，返回新的地址
*/


/*
常见问题：
1.对空指针进行解引用，所以一定要检验返回的是不是空指针
2.对动态开辟内存的越界访问，访问的地址大小超过了开辟的
3.对非动态开辟的空间使用free释放，动态开辟的放在堆区，非动态的在栈区，释放会出问题
4.使用free释放动态开辟的一部分内存，例如使用p的时候p++,则指向的地址会变，这时候free(p)出问题
5.对同一块动态开辟的内存多次释放
6.忘记释放动态开辟的空间，造成内存泄漏，调用函数内的malloc要记得返回地址或者在函数内释放完
*/


//int main()
//{
//	//向内存申请10个整形的空间
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (p == NULL)
//		printf("%s\n", strerror(errno));
//	else
//	{
//		//使用malloc开辟的空间
//		for (int i = 0; i < 5; i++)
//			*(p + i) = i;
//		for (int i = 0; i < 5; i++)
//			printf("%d ", *(p + i));
//	}
//	//假设开辟的不满足，希望能更大
//	//p = (int*)realloc(p, 10 * sizeof(int));	
//	//有特别大的风险，如果开辟失败原先的p就会丢失
//	//假如原先开辟的后面内存是被占用的，就会非法访问
//	//使用新的指针接收
//	int* ptr = (int*)realloc(p, 10 * sizeof(int));	
//	if (ptr!= NULL)
//	{
//		p = ptr;//依旧使用原先的p去维护内存，再去使用p
//	}
//
//	free(p);	//空间虽然被释放了，但是p依然有能力指向那个空间
//	p = NULL;	//置空，保险
//	return 0;
//}



//柔性数组 - 是一种结构体中的成员，结构体的最后一组成员
//数组前面至少有一个成员，sizeof返回的结构大小不包括柔型数组的内存
struct S
{
	int n;
	//1.使用arr[]或者arr[0]
	//int arr[];
	//2.模拟柔性数组
	int * arr;
};
int main()
{
	//1.arr[]或者arr[0]的使用
	//柔型数组所在的结构体的空间的创建使用malloc函数
	//struct S 开辟的空间存放n ，后面开辟的一片连续空间是给数组的，5个整形元素
	//struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
	//ps->n = 100;
	//int i = 0;
	//for (i = 0; i < 5; i++)
	//{
	//	ps->arr[i] = i;//0,1,2,3,4,5
	//}
	//2.模拟柔性数组
	struct S *ps = (struct S*)malloc(sizeof(struct S*));
	ps->arr = (int *) malloc(5 * sizeof(int));
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	int* ptr = (int *)realloc(ps->arr, 10 * sizeof(int));
	if (ptr)
	{
		ps->arr = ptr;
	}
	//释放内存
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}

//笔试题
//void GetMemory(char *p)
//{
//	p = (char*)malloc(100);
//	//严格来说还有内存泄漏的问题
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	//值传递，没有返回开辟空间的地址
//	strcpy(str, "hello world");
//	//拷贝函数崩溃，访问非法内存
//	printf("%s",str);
//}
//请问运行Tsst会产生什么结果
//崩溃了,GetMemory调用时候，p存放的是NULL
//malloc在堆上找一片连续空间，把返回值给了p，p就有能力指向开辟的空间
//GetMemory函数结束之后没有返回地址，开辟空间的地址就丢失了，str就是NULL,strcpy函数崩溃



//笔试题
//int* f1()
//{
//	int x = 10;
//	return (&x);
//	//会出问题，x是在栈区开辟的空间，函数结束之后变回收了
//	//x的指针指向的空间就没了
//}
//int f2()
//{
//	int *p;
//	*p = 10;
//	return p;
//	//非法访问内存，p是个野指针，没有指向有效的空间
//}


int main()
{

	return 0;
}