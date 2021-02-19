#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (; i < 10;i++)
//	for (; j < 10; j++)
//		printf("hehe\n");
//	//打印出来10个hehe
//	//j从 0~9之后为10
//	//i=1之后，j从10开始，第二次嵌套不循环
//	
//	return 0;
//}

//int main()
//{
//	int i, j;
//	for (i = 0, j = 0; j = 0; ++i, j++)
//		j++;
//	//k=0舒服赋值表达式，其结果为假
//	//此循环不执行，循环0次
//	return 0;
//}


//计算n的阶乘
//int main()
//{
//	int i = 0;
//	int ret = 1;
//	scanf("%d", &i);
//	for (int j = 1; j <= i; j++)
//	{
//		ret *= j;
//	}
//	printf("%d", ret);
//	return 0;
//}

//计算1!+……+10！
//int main()
//{
//	int n;
//	int ret = 1;
//	int sum = 0;
//	for (n = 1; n <= 3; n++)
//	{
//		ret *= n;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//有序数组中查找具体的数字（二分法）
//int main()
//{
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


//多个字符从两端移动到中间
//int main()
//{
//	char arr1[] = "Welcome to bit!!!!!!";
//	char arr2[] = "####################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	//上表达式不可以改为：right=sizeof(arr1)/sizeof(arr1[0])-1,因为字符型arr1数组的最后you隐藏的'\0'，如果要使用sizeof计算，需要-2
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

//编写代码实现登录系统
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

//最大公约数（辗转相除）
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

//猜数字游戏
void menu();
void game();
int main()
{
	//时间戳  当前时间-计算机起始时间(1970.1.1  0:0:0) =（xxxx）秒
	// time_t time(time_t *timer);返回值是time_t类型,本质上是长整型
	srand((unsigned int)time(NULL));
	//配合game()函数中的rand使用
	int input = 0;
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
			break;
		case 0:
			printf("退出游戏!");
			break;
		default:
			printf("选择错误!请重新选择!\n");
			system("pause");
			system("cls");
			break;
		}
	} while (input);
	return 0;
}
void menu()
{
	printf("******************************\n");
	printf("****   1.play    2.exit   ****\n");
	printf("******************************\n");
}

void game()
{
	int ret,guess;
	printf("请猜数字!\n");
	//rand()函数生成数字是0-32767
	ret = rand()%100+1;		//（0-32767）%100之后的余数是0-99，+1之后为1-100
	while (1)
	{
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了!\n");
		}
		else if (guess < ret)
		{
			printf("猜小了!\n");
		}
		else
		{
			printf("恭喜你，猜对了!\n");
			system("pause");
			system("cls");
			break;
		}
	}

}


//int main()
//{
//	//乘法口诀表
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d = %-2d  ",i,j, i*j);
//			//%-2d左对齐的两格，%2d右对齐两格
//		}
//		printf("\n");
//	}
//	return 0;
//}


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