#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//test15
int main()
{
	printf("%d", printf("%d", printf("%d", 43)));	//printf函数返回值为字符串的长度
	//结果为4321
	return 0;
}

//test14
//goto语句的初步测试
//int main()
//{
//	//shutdown -s t 60  //60秒内关机
//	//shutdown -a		//取消关机
//	//system  用来执行系统命令
//	char input[20];
//	system("shutdown -s -t 60");
//	printf("请注意，你的电脑在一分钟内关机!\n");
//again:
//	printf("如果输入：我是猪     可以取消关机\n");
//	scanf("%s", input);
//	if (strcmp(input,"我是猪") == 0)
//	{
//		system("shutdown -a");
//		printf("恭喜你，取消了关机\n");
//	}
//	else
//	{
//		printf("你很调皮！十秒内关机!\n");
//		system("shutdown -s -t 5");
//		goto again;
//	}
//
//	return 0;
//}


//test13
//void menu()
//{
//	printf("******************************\n");
//	printf("****   1.play    2.exit   ****\n");
//	printf("******************************\n");
//}
//
//void game()
//{
//	int ret,guess;
//	printf("请猜数字!\n");
//	//rand()函数生成数字是0-32767
//	ret = rand()%100+1;		//（0-32767）%100之后的余数是0-99，+1之后为1-100
//	while (1)
//	{
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了!\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了!\n");
//		}
//		else
//		{
//			printf("恭喜你，猜对了!\n");
//			system("pause");
//			system("cls");
//			break;
//		}
//	}
//
//}
//
//int main()
//{
//	//猜数字游戏
//	//时间戳  当前时间-计算机起始时间(1970.1.1  0:0:0) =（xxxx）秒
//	// time_t time(time_t *timer);返回值是time_t类型,本质上是长整型
//	srand((unsigned int)time(NULL));
//	//配合game()函数中的rand使用
//	int input = 0;
//	do
//	{
//		menu();
//		printf("请选择:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			system("cls");
//			game();
//			break;
//		case 0:
//			printf("退出游戏!");
//			break;
//		default:
//			printf("选择错误!请重新选择!\n");
//			system("pause");
//			system("cls");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//test12
//int main()
//{
//	//乘法口诀表
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d = %-2d  ",i,j, i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//test11
//int main()
//{
//	//素数的判断
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//判断i是否是素数
//		//素数的判断规则
//		//1.试除法，产生 2->i-1个数
//		for (j = 2; j <= sqrt(i) ; j++)
//		{
//			if (i%j == 0)
//			{
//				break;		//能整除说明不是素数
//			}
//		}
//		if (j >sqrt(i))
//		{
//			printf("%d ", i); //只有1和本身证明是素数
//		}
//
//		//2.一个数必定可以写成 a*b的形式
//		//即判断素数中，a和b中至少有一个数字小于等于 根号i
//	}
//}

//test10
//int main()
//{
//	//辗转相除法求最大公因数
//	int m, n, k;
//	scanf("%d %d", &m, &n);
//	while (m%n)		//结果不为0时循环，为0时结束
//	{
//		k = m%n;
//		m = n;
//		n = k;
//	}
//	printf("最大公因数为:%d\n", n);
//	return 0;
//}

//test09
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:\n");
//		scanf("%s", password);
//		//字符串的比较不能直接使用 == ，必须使用strcmp函数
//		//如果字符串长度大于比较的，返回大于0的数字，小于则返回小于0的数字，等于则返回0
//		if (strcmp(password, "123456") == 0)	
//		{
//			printf("登陆成功！\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误，请重试！\n");
//		}
//	}
//	if (i == 3)
//		printf("三次输入错误，退出程序！\n");
//	
//	return 0;
//}

//test 08
//int main()
//{
//	char arr1[] = "Welcome to bit!!!!!!";
//	char arr2[] = "####################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(500);
//		system("cls");
//		left++;
//		right--;
//	}
//	printf("%s\n", arr2);
//	return 0;
//}

//tese07
//int main()
//{
//	//有序数列的二分查找法
//	//时间复杂度 log2N
//	int arr[] = { 1, 2, 3, 4, 5, 6, 8, 9, 10 ,11, 12};
//	int key,mid;
//	scanf("%d", &key);		//要查找的元素
//	int size = sizeof(arr) / sizeof(arr[0]);		//元素个数
//	int left = 0;		//左下标
//	int right = size - 1;	//右下标
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (arr[mid] > key)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("找到了，下标为:%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到此元素!\n");
//	}
//
//	//system("pause");
//	return 0;
//}

//test06
//int main()
//{
//	int sum = 0;
//	int ret = 1;
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		ret = ret * i;
//		sum += ret;		//计算1-n的阶乘相加
//	}
//	printf("%d\n", sum);
//	//system("pause");
//	return 0;
//}

//tset 05
//int main()
//{
//	char ch = 0;
//	while ((ch = getchar()) != EOF)		//输入为数字字符时候会输出，且getchar一次只会读取一个字符，两位数或以上也能输出
//	{
//		if (ch < '0' || ch > '9')
//			continue;
//		else
//			putchar(ch);
//	}
//	system("pause");
//	return 0;
//}

//teset 04
//int main()
//{
//	int ret;
//	char ch;
//	char password[20] = { 0 };
//	printf("请输入密码：\n");
//	scanf("%s", password);
//	//输入缓冲区会剩余 '\n'，即回车符
//	//可以在此处加个 getchar()实现读取 '\n'的操作，至于读取到何处不关心
//	while ((ch = getchar()) != '\n')
//	{
//		//不需要内容，只需要读取即可
//	}
//	//当输入为 123456 ABCD(此处有个空格)的时候，函数又会出问题，因为scanf只会获取空格之前的内容
//	//此时便可以使用while循环直到读取 回车符停止
//	printf("请确认:Y/N?\n");
//	ret = getchar();		//getchar读取的是输入密码之后所敲的回车符，保留下来赋给了ret
//	if (ret == 'Y')
//	{
//		printf("确认成功!\n");
//	}
//	else
//	{
//		printf("取消确认!\n");
//	}
//	//结果为取消确认，因为ret的值为10，不是'Y'
//	//printf("%d\n", ret);  //ret 值为10 ，10为回车符的ASCII码值
//	system("pause");
//}


//test03
//int main()
//{
//	char ch;
//
//	//while(scanf("%d",&n)!=0) 等价于 while(~scanf("%d",&n))
//	//scanf函数按照正确的输入格式输入两个数据则返回2,一个就返回1，没有则返回0
//	//EOF = end of file  ->文件结束标志  本质上是-1
//	while ((ch = getchar())!= EOF)  //ctrl+Z代表结束
//	{
//		putchar(ch);
//	}
//	system("pause");
//}


//tset02
//int main()
//{
//	char arr1[] = "abc";  //默认含有 '/0'结束标识符
//	char arr2[] = { 'a', 'b', 'c'};  //不含有'/0'结束标识符
//
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));
//	printf("\\n\n");
//	printf("%d\n", strlen("C:\tset\x92\test.c"));   
//	//	\ddd表示八进制数转换为十进制后的ASCII码对应的标识符     \xdd表示十六进制的
//	system("pause");
//	return 0;
//}


//tset01
//int main()
//{
//	int j = 072;		//八进制数
//	int k = 0x2A;		//十六进制数
//	int m = 10;
//
//	printf("%d\n", j);
//	printf("%#X\n", m);		//输出十六进制，字符为大写,格式为0Xdd
//	printf("%#x\n", m);		//输出十六进制，字符为小写,格式为0xdd
//	printf("(are you ok??)\n");
//	system("pause");
//	
//}
