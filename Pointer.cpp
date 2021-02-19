#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <search.h>
/********************************************************************************/
//找到以所指目标为地址的内存单元
//通过地址找到所需的变量单元
//一个小的内存单元的大小是 1 Byte，一个字节
//对于32位的机器，假设有32根地址线，每根地址线都有正负电信号
//就会产生 2^32 个地址序列
//32位的平台上，指针大小是4字节，64位平台上是8字节
//同一个平台上，不论什么类型的指针变量，大小是相同的
//指针区分类型是为了表示所指目标的类型
//不同类型的只能变量，操作的时候结果会对不同类型所对于的不同字节量进行操作
//例如 int* p，当解引用操作 *p = 0 的时候会对四个字节操作
//但是 char* p ,当解引用操作 *p = 0的时候只会对一个字节进行操作
//即指针类型决定了指针进行解引用操作的时候所访问的空间的大小
//指针类型决定了指针走一步走多远，即 p+1 跳过多少个字符，(int跳过4字节)
/*******************************************************************************/
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int* p = &a;	//指针变量，变量p的类型是 int*，用来存放地址
//	return 0;
//}

//指针类型的意义
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	//arr是数组名，首元素地址
//	int* p = arr;	//创建了一个指针变量，存放了第一个元素的地址
//	//假设要把数组内容全部给成1
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 1;
//		//通过此操作可以把数组内容全部改成1
//		//但是如果数组类型不对，则无法实现此操作
//	}
//	printf("%d", i);
//	return 0;
//}


//野指针是指针指向的位置是不可知的指针，要避免野指针
//导致野指针的原因：指针未初始化；指针越界访问；指针所指的内存空间被释放了；


//指针的运算
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", *p);
//		p++;	//指针加一个int型变量的字节数
//	}
//	//&arr[10] - &arr[0] == 10,指针减去指针得到的是元素的个数
//}

//C语言允许指向数组元素的指针与指向数组最后一个元素的指针后面的那个内存位置的指针进行比较
//但是不允许与指向第一个元素之前的那个内存位置的指针进行比较






//进阶数组
//int main()	//数组指针 ：存放数组的指针 (*parr)[]			指针数组：存放指针的数组 *parr[]  →因为方括号的结合优先级大于*
//{
//	char* arr[10];
//	char* (*parr)[10] = &arr;
//	//初始化的方法：
//	//首先 &arr是数组的地址，所以需要 *parr指针来存储
//	//接着arr数组有10个元素，所以需要数组指针来存储10和元素，即(*parr)[10]
//	//最后，arr[10]定义的时候数据类型是char* ，所以(*parr)[10] 定义的类型也需要是 char *
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int(*pa)[10] = &arr;
//	int i = 0;
//	//数组指针的打印方法
//	for (i = 0; i < 10; i++)
//	{
//		//printf("%d ", (*pa)[i]);
//		printf("%d ", *(*pa + i));	//*pa == arr ，因为是&arr的解引用,所以*pa+i就相当于找出每个元素的地址，再进行解引用操作，得到每个元素的值
//	}
//	printf("\n");
//	return 0;
//}

//数组指针的用法,一般用到二维数组以上
//void my_print(int(*p)[5], int x, int y);
//int main()
//{
//	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
//	my_print(arr,3,5);	
//	//所谓数组名就是首地址，除了sizeof和取地址两种情况，在二维数组里面，首元素就是第一行元素
//	//而每一行又具有定义时的n个元素，在此即为int [5]
//
//	return 0;
//}
//void my_print(int (*p)[5],int x,int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < x; i++)
//	{
//		for (j = 0; j < y;j ++)
//		{
//			printf("%d ", *(*(p + i) + j));	
//			printf("%d ", (*(p + i))[j]);
//			printf("%d ", *(p[i] + j));
//			printf("%d ", p[i][j]);
//			//以上写法等价
//			//*(p+i)可以寻找第几行，*p代表指向的首元素代表的一行的所有元素大小的总和
//			//*(p+i)+j是寻找第i行的第j个元素，i+1则指下一行
//			//假如改为(*p+i)，则每次会往后跳一个二维数组内元素的大小，而不是一行
//
//			//*(p+i)+j也是属于指针，所有通过整体的解引用来寻找所指的值
//			//arr[i] == *(arr+i) == *(p+i) == p[i]
//			
//		}
//		printf("\n");
//	}
//}

//字符指针
//int main()
//{
//	char ch = 'W';
//	char *p = &ch;
//	const char *p2 = "abcdef";
//	//其实是字符串首字符a的地址赋给p2
//	//是个常量字符串不允许修改内容，加const最合理
//
//	int(*p3[10])[5];
//	//首先p3是一个数组，数组里面存放十个元素，每个元素是指针类型
//	//其次每个指针是数组指针，存放五个元素
//}

//二级指针用来存放一级指针变量的地址
//&函数名 和 函数名  都是函数的地址，用%p打印没有任何区别
//void Print(char* str)
//{
//	printf("%s", str);
//}
//int main()
//{
//	void(*p)(char*) = Print;
//	(*p)("hello world!\n");
//	return 0;
//}

//阅读代码
//代码1
//(*(void(*)())0)();
//首先理解一件事， int (*p)[5]，如果把p去掉，即int (*)[5]就会成为p的类型
//void(*)(char*)同理也是一种类型，定义的是一个函数指针
//在此，0之前的，void(*)()是一种指向void的函数指针类型
//那么此处便是强制转换，把0强制转换为某函数的地址，类型为void(*)()
//用前面的*解引用,对(void(*)())0进行解引用，调用0地址处的该函数
//最后的括号代表不需要传参
//总结：把0强制转换成函数指针的类型，该指针指向的类型是无参返回类型是void，进行解引用调用0位地址的该函数

//代码2
//void(*signal(int, void(*)(int)))(int);
//signal函数，参数有 int 和 void(*)(int)     第二个参数是函数指针类型
//整体的返回类型就是把signal(int, void(*)(int))函数去掉，即void(*)(int)
//但是按照原本的写法，void(*)(int) signal(int, void(*)(int))，但是此写法是错误的
//容易看懂：void(*           	signai( int , void(*)(int) )         )(int)
//signal是一个函数声明，参数有两个，一个是int类型，一个是函数指针，该函数指针指向的函数的参数是int，返回类型是void
//整个函数的返回类型也是函数指针，该函数指针指向的参数类型是int，返回类型是void
//可以利用typedef进行简化
//typedef void(* pfun_t)(int);
//对于函数指针类型，重命名需要放到里面的指针部分
//pfun_t signal(int,pfun_t);就成为了原本的函数





//函数指针
//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int(*pa)(int ,int ) = add;
//	printf("%d\n", (*pa)(2, 3));
//	//通过解引用pa找到函数，然后传递参数
//	printf("%d\n", (pa)(2, 3));
//	//add函数传给了pa，所以add和pa是一回事，也可以输出5
//	//因为函数名本身就是一个地址
//	printf("%d\n", (**pa)(2, 3));
//	printf("%d\n", (***pa)(2, 3));
//	//以上输出结果都为5
//	//后面两个函数多余的*完全是摆设，没有具体的作用
//	//一般不会使用后面两种方法
//	
//	return 0;
//}



//函数指针数组
//首先复习指针数组，int *arr[10],数组的每个元素类型是int *，有10个元素
//如果要把函数的地址存到数组里面
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int *arr[5];
//	int(*pa)(int, int) = add;
//	//add,sub函数的参数类型以及返回类型都是一样的
//	//需要一个数组可以存放四个函数的地址，即函数指针的数组
//	int(*par[2])(int, int) = { add, sub };
//	int i = 0;
//	for (i = 0; i < 2; i++)
//	{
//		printf("%d\n",par[i](2, 3));
//	}
//	return 0;
//}

//写一个函数指针pf能够指向my_strcpy
//写一个函数指针数组pfArr，能够存放my_strcpy函数的地址，四个
//char * my_strcpy(char* dest,const char* src)
//char* (*pf)(char*, const char*) = my_strcpy;
//char* (*pfArr[4])(char *, const char*);


//函数指针数组案例→计算器
//void menu()
//{
//	printf("****   1.add             2.sub    ****\n");
//	printf("****   3.mul             4.div    ****\n");
//	printf("****           0.exit             ****\n");
//	printf("**************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void Calc(int(*pf)(int, int))	//将要调入的函数地址传入
//{
//	//很好的解决代码冗余的问题
//	//相同的代码可以通过函数解决
//	int x = 0;
//	int y = 0;
//	printf("请输入两个操作数:>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//int main()
//{
//	//转移表
//	int input = 0;
//	//int x = 0;
//	//int y = 0;
//	//int(*pfArr[5])(int, int) = { 0, Add, Sub, Mul, Div };
//	do
//	{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入两个操作数:>");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出!\n");
//
//		}
//		else
//		{
//			printf("选择错误!\n");
//
//		}
//	} while (input);
//
//	do{
//		menu();
//		printf("请选择:>");
//		scanf("%d", &input);
//		//回调函数→通过函数指针调用的函数 Calc
//		switch (input)
//		{
//		case 1:
//			Calc(Add);
//			break;
//		case 2:
//			Calc(Sub);
//			break;
//		case 3:
//			Calc(Mul);
//			break;
//		case 4:
//			Calc(Div);
//			break;
//		case 0:
//			printf("退出！\n");
//			break;
//		default:
//			printf("选择错误，请重新选择!\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}
//



//指向函数指针数组的指针
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int (*p)[10] = &arr;	//取出数组的地址
//
//	int(*pfArr[4])(int, int);
//	int (*(*ppfArr)[4])(int ,int) = &pfArr;		//指向函数指针数组的指针
//	//ppfArr首先和*结合，是一个指针，之后与[]结合是一个数组，所以是数组指针
//	//指针指向的数组有4个元素
//	//指向的数组的每个元素的类型是一个函数指针，类型是	int(*)(int,int)
//
//	return 0;
//}



//复习
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	//指针数组
//	//int * arr[10];
//	//数组指针
//	//int* (*pa)[10] = &arr;
//	//函数指针
//	int(*pAdd)(int, int) = Add;
//	//int sum = (*pAdd)(1, 2);
//	//int sum = pAdd(1, 2);
//	//Add(1, 2);
//	//以上三种写法都可以实现Add的调用
//	//函数指针数组
//	int(*pArr[5])(int, int);
//	//指向函数指针数组的指针
//	int(*(*PArr)[5])(int, int) = &pArr;
//	//名字去掉即为数据类型
//
//}


//void BubbleSort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	int temp;
//	//排序多少趟
//	for (i = 0; i < sz - 1; i++)
//	{
//		//一趟排序多少次
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//
//			}
//		}
//	}
//}

//int main()
//{
//	//冒泡排序只能排序整形数组
//	int i = 0;
//	int arr[] = { 1, 4, 5, 6, 7, 3, 9, 10, 2, 8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//BubbleSort(arr, sz);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}






//qsort 可以排序任意类型的函数
//void qsort(void *base, size_t num, size_t width, int(__cdecl *compare)(const void *elem1, const void *elem2));
//4个参数,最后一个是一个函数指针，参数两个void，返回类型int
//base:start of target array	要排序数组的起始位置		
//num:array size elements	数字的元素个数
//width:element size in bytes	(一个元素大小),选用sizeof(arr[0])
//compare:comparison function(比较函数)，比如整形直接一般的冒泡就可以，但是类似结构体这种需要另寻方法
//compare函数:	elem1<elem2,返回<0，相等返回0，大于返回>0，类似通过elem1-elem2
//elem1，elem2：	要比较的两个元素的地址，利用void*可以接收任意类型的地址

//void*指针
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	void* p = &a;	//无类型的指针，没有具体类型
//
//	//*p = 0;		//此语句会报错，不知道访问多少字节
//
//	//void*指针可以接受任意类型的地址
//	//void*类型的指针不能进行解引用的操作
//	//也不能进行加减乘除，不知道跳多少字节
//}

//struct  stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_int(const void *e1, const void *e2)
//{
//	//比较两个整形
//	//通过强制类型转换可以变为相应的类型
//	return *(int*)e1 - *(int*)e2;
//}
//
//int cmp_float(const void* e1, const void* e2)
//{
//	if (*(float*)e1 == *(float*)e2)
//		return 0;
//	else if (*(float*)e1 < *(float*)e2)
//		return -1;
//	else return 1;
//	//return ((int)(*(float*)e1 - *(float*)e2));
//	//丢精度，有问题
//}
//
//int cmp_struct_by_age(const void *e1,const void *e2)
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//
//int cmp_struct_by_name(const void *e1, const void *e2)
//{
//	//比较名字就是比较字符串
//	//字符串比较不能直接比较，用strcmp函数,可以实现字母顺序的排序
//	//大于返回大于0，相等返回0，小于返回小于0的数
//	return strcmp(((struct stu*)e1)->name , ((struct stu*)e2)->name);
//}
//
//void test_int()
//{
//	int arr[10] = { 1, 4, 5, 6, 7, 3, 9, 10, 2, 8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void test_float()
//{
//	float f[] = { 9.5, 8.2, 5.2, 12.2, 4.1, 5.7, 8.3, 9.2, 3.2, 1.5 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f, sz, sizeof(f[0]), cmp_float);
//	int j = 0;
//	for (j = 0; j < sz; j++)
//	{
//		printf("%f ", f[j]);
//	}
//}
//
//void test_struct()
//{
//	struct stu s[3] = { { "zhangsan", 18 }, { "lisi", 20 }, { "wangwu", 10 } };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_struct_by_name);
//	int j = 0;
//	for (j = 0; j < sz; j++)
//	{
//		printf("%s %d ",s[j].name,s[j].age);
//	}
//}
//
////利用bubble_sort模拟qsort函数
////调用的时候不知道待比较元素的数据类型，函数指针用void*，传入两个相邻元素
//void swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char temp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = temp;
//		//循环直到宽度为传入的值
//		buf1++;
//		buf2++;
//	}
//}
//
//void bubble_sort(void* base,int sz,int width,int (*compare)(const void* elment1,const void* elment2))
//{
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			//此处插入需要排序的数据的排序方法
//			if (compare((char*)base + j*width, (char*)base + (j + 1)*width) > 0 )
//			{
//				//交换
//				swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
//			}
//
//		}
//	}
//}
//
//void test_bubble()
//{
//	struct stu s[3] = { { "zhangsan", 18 }, { "lisi", 20 }, { "wangwu", 10 } };
//	int sz = sizeof(s) / sizeof(s[0]);
//	bubble_sort(s, sz, sizeof(s[0]), cmp_struct_by_age);
//	int j = 0;
//	for (j = 0; j < sz; j++)
//	{
//		printf("%s %d ", s[j].name, s[j].age);
//	}
//}
//
//int main()
//{
//	
//	test_int();
//	printf("\n");
//	test_float();
//	printf("\n");
//	test_struct();
//	printf("\n");
//	test_bubble();
//	return 0;
//}
//


//笔试题
//int main()
//{
//	//数组名表示首元素的地址，一下两种情况除外
//	//1.sizeof(数组名) - 数组名表示整个数组
//	//2.&数组名 - 数组名表示的是整个数组
//	//整形数组
//	int arr[] = { 1, 2, 3, 4 };
//	printf("%d\n", sizeof(arr));//16 - sizeof数组名计算的数组的长度
//	printf("%d\n", sizeof(arr+0));//4/8 - 这里的数组名表示首元素的值，+0还是表示首元素的大小
//	printf("%d\n", sizeof(*arr));//4 - 数组首地址解引用，首元素的类型大小
//	printf("%d\n", sizeof(arr+1));//4/8 - 第二个元素的地址大小，不同平台有4或者8
//	printf("%d\n", sizeof(arr[1]));//4 - 第二个元素的大小
//	printf("%d\n", sizeof(&arr));//4/8 - &a取出的是数组的地址，但是数组的地址也是地址，地址的大小就是4或者8
//	printf("%d\n", sizeof(*&arr));//16 - &a是数组的地址，数组的地址解引用访问的是数组，计算的数组大小
//	printf("%d\n", sizeof(&arr+1));//4/8 - 取地址之后还是地址，地址的大小4或者8
//	printf("%d\n", sizeof(&arr[0]));//4/8 - 取第一个元素的地址地址，大小4或者8
//	printf("%d\n", sizeof(&arr[0]+1));//4/8 - 第二个元素地址，4或者8
//	//字符数组
//	const char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; //6个元素
//	printf("%d\n", sizeof(arr));//6 - 数组大小，字符型数组
//	printf("%d\n", sizeof(arr+0));//4/8 - 首元素的地址
//	printf("%d\n", sizeof(*arr));//1 - 首地址所代表的元素类型的大小
//	printf("%d\n", sizeof(arr[1]));//1 - 第二个元素的大小
//	printf("%d\n", sizeof(&arr));//4/8 - 本质上是地址，地址就是4/8个字节
//	printf("%d\n", sizeof(&arr+1));//4/8 - 含义是跳过这个数组，但是本质上还是地址
//	printf("%d\n", sizeof(&arr[0]+1));//4/8 - 本质上是地址，此处含义是第二个元素的地址
//	printf("%d\n", strlen(arr));//随机值，因为不知道何时能找到'\0'结束标志
//	printf("%d\n", strlen(arr+0));//随机值，数组名代表首元素地址，和第一种写法等价
//	printf("%d\n", strlen(*arr));//strlen函数的参数要的是地址，此处传的'a' - 97- 0x61，非法访问
//	printf("%d\n", strlen(arr[1]));//此处传入98，也是错误
//	printf("%d\n", strlen(&arr));//err，无法将const char (*)[6]转换为const char *
//	printf("%d\n", strlen(&arr[0]+1));//比以上随机值少1	
//	//字符串
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7 - 所占空间加上'\0'，计算的数组的大小
//	printf("%d\n", sizeof(arr+0));//4/8 - 本质上是地址
//	printf("%d\n", sizeof(*arr));//1 - 首元素数据类型的大小
//	printf("%d\n", sizeof(arr[1]));//1 - 第二个元素的数据大小
//	printf("%d\n", sizeof(&arr));//4/8 - 本质上是地址
//	printf("%d\n", sizeof(&arr+1));//4/8 - 本质上是地址
//	printf("%d\n", sizeof(&arr[0]+1));//4/8 - 第二个元素的地址，本质上是地址
//	//字符指针
//	char *p = "abcdef";
//	printf("%d\n", sizeof(p));//4/8 - 指针
//	printf("%d\n", sizeof(p+1));//4/8 - 指针本质
//	printf("%d\n", sizeof(*p));//1 - 字符串的第一个字符大小
//	printf("%d\n", sizeof(p[0]));//1 - 字符串的第一个字符大小
//	printf("%d\n", sizeof(&p));//4/8 - 本质上是地址
//	printf("%d\n", sizeof(&p+1));//4/8 - 本质上是地址
//	printf("%d\n", sizeof(&p[0]+1));//4/8 - 本质上也是地址
//	printf("%d\n", strlen(&p));//随机值，char** 与const char* 类型不匹配
//	//二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48
//	printf("%d\n", sizeof(a[0][0]));//4
//	printf("%d\n", sizeof(a[0]));//16 - 计算的是第一行的大小
//	printf("%d\n", sizeof(a[0]+1));//4/8 - a[0]+1 代表的第一行首元素的地址，+1表示第二个元素的地址
//	printf("%d\n", sizeof(*(a[0]+1)));//4 - 第一行第二个元素数据类型的大小
//	printf("%d\n", sizeof(a+1));//4/8 - 第二行元素的地址，a是二维数组的数组名，此处是首元素地址
//									  //而二维数组的首元素是第一行，所以a就是第一行的地址
//									  //a+1就是第二行地址
//	printf("%d\n", sizeof(*(a+1)));//16 - *(a+1) == a[1]，相当于计算第二行数组的大小
//	printf("%d\n", sizeof(&a[0]+1));//4/8 - 第二行的地址，&a[0]代表第一行的地址，第一行+1就是第二行
//	printf("%d\n", sizeof(*(&a[0]+1)));//16 - 第二行数组的大小
//	printf("%d\n", sizeof(*a));//16 - *a表示第一行
//	printf("%d\n", sizeof(a[3]));//16 - 第四行数组的大小
//
//	return 0;
//}



//笔试题1
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *)(&a + 1);	//数组地址+1跳过整个数组
//	printf("%d,%d\n", *(a + 1), *(ptr - 1)); //2,5
//	//ptr-1 就是最后一个元素，a+1代表第二个元素
//	return 0;
//}

//笔试题2
//struct Test
//{
//	int Num;
//	char *pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}* p;
////假设p的值为0x00100000，下列表达式值分别为多少
////已知结构体Test类型的变量大小是20个字节
//int main()
//{
//	p = (struct Test *)0x00100000;
//	//0x1的值就是1
//	printf("%p\n", p + 0x1);//0x00100014 - +1代表跳过一个结构体类型的大小
//	printf("%p\n", (unsigned long)p + 0x1);//0x00100001 - 首先转换为unsigned long类型为1048576,
//										   //再+1，为1048577,再转为十六进制
//										   //结果就是0x00100001
//	printf("%p\n", (unsigned int*)p + 0x1);//0x00100004 - int*类型指针+1代表地址+4
//}

//笔试题3
//int main()
//{
//	int a[4] = {1, 2, 3, 4};
//	int *ptr1 = (int *)(&a + 1);//跳过一个数组的大小，再转为int* 类型
//	int *ptr2 = (int *)((int)a + 1);
//	//(int)a+1就是a的地址转为整形+1，结果为地址向后偏移1个字节
//	//小端存储时候，低字节存低地址
//	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 - a的内存存储情况
//	//每个元素四个字节，低字节存低地址
//	//向后偏移一个字节之后，转为int*，所以ptr2指向的从01后面开始
//	//ptr2 为 00 00 00 02,小端存储
//	//读出来为 02 00 00 00 ，十六进制打印就是这个
//	printf("%#x,%#x", ptr1[-1], *ptr2);//等于 *(ptr1-1)
//	//ptr[-1]就是前面那个数组的最末尾的元素，即0x4
//
//	return 0;
//}

//笔试题4 
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	//用了圆括号代表逗号表达式
//	//int a[3][2] = { 1, 3, 5 };
//	//后面的都没有初始化
//	int *p;
//	p = a[0];
//	printf("%d", p[0]);//结果为1
//	return 0;
//}

//笔试题5
//int main()
//{
//	int a[5][5];
//	int(*p)[4]; //指向有4个整形元素的数组
//	p = a;	//此处报错，按照原题思路做，无法赋值
//	//a是五行五列的数组，但是强行赋给只有四列的p
//	//p+4即p[4]的结果就会指向a[3][1]
//	//p[4][2]相当于*(*(p+4)+2),即先指向a[3][1]之后向后找两个元素
//	//最终p[4][2]会指向a[3][3]
//	printf("%p,%d\n",&p[4][2] - &a[4][2],&p[4][2] - &a[4][2]);
//	//地址相减的时候，p[4][2]和a[4][2]相差四个元素
//	//结果为 0xfffffffc				-4
//	//-4 原码 10000000 00000000 00000000 00000100
//	//-4 补码 11111111 11111111 11111111 11111100
//	//打印地址的时候直接把反码打印0xfffffffc
//	return 0;
//}

//笔试题6
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int *ptr1 = (int *)(&aa + 1);
//	int *ptr2 = (int *)(*(aa + 1));
//	//aa代表aa[0],即第一行元素，*(aa+1) == a[1]
//	//ptr2 指向第二行首元素的地址
//	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1)); //10,5
//	return 0;
//}

//笔试题7
//int main()
//{
//	char *a[] = { "work", "at", "alibaba" };
//	//a数组有三个元素，类型都是char*，存放三个字符串的首地址
//	char **pa = a;
//	//a的首元素地址，即'w'的地址放到pa中，pa是个指针变量，类型是char**
//	//a代表的是char*的地址，所以需要char**来存放
//	pa++;
//	//pa指向的元素是char*，跳过的就是char*的变量，即指向第二个元素
//	printf("%s\n", *pa); //结果为at
//	return 0;
//}


//笔试题8
int main()
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char **cp[] = { c + 3, c + 2, c + 1, c };
	char ***cpp = cp;
	//cp数组的首元素地址存到cpp
	printf("%s\n", **++cpp);	//结果为POINT
	//cpp先前置++，解引用后得到c+2元素，再解引用后得到cp数组c+2元素所指的c数组的c[3]
	//打印出来即c[3]存放的以P为首元素的字符串POINT
	printf("%s\n", *--*++cpp +3);//结果为ER
	//先前置++cpp，由于第一条打印自加过，所以此时解引用后得到的是c+1元素，再--得到c
	//再解引用之后得到的是ENTER中E的地址，+3之后指向ENTER的E，打印就从E开始打印ER
	printf("%s\n", *cpp[-2]+3);//结果为ST
	//*cpp[-2]+3即 **(cpp-2)+3
	//由于前面另个打印的关系，此处-2之后又指向了cp数组的首元素地址，解引用得到c+3元素
	//再解引用得到FIRST中F的地址，+3之后从S开始打印ST
	printf("%s\n", cpp[-1][-1]+1);//结果为EW
	//等价于  *(*(cpp-1)-1)+1
	//由于最初两个打印中自加和自减的关系，cpp再执行此打印最初是指向c+2的
	//解引用之后得到c+2元素，c+2元素-1得到 c+1 ，再对c+1解引用得到就是NEW
	//再+1 从E开始打印EW
	return 0;
}