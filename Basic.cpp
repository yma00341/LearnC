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
	printf("%d", printf("%d", printf("%d", 43)));	//printf��������ֵΪ�ַ����ĳ���
	//���Ϊ4321
	return 0;
}

//test14
//goto���ĳ�������
//int main()
//{
//	//shutdown -s t 60  //60���ڹػ�
//	//shutdown -a		//ȡ���ػ�
//	//system  ����ִ��ϵͳ����
//	char input[20];
//	system("shutdown -s -t 60");
//	printf("��ע�⣬��ĵ�����һ�����ڹػ�!\n");
//again:
//	printf("������룺������     ����ȡ���ػ�\n");
//	scanf("%s", input);
//	if (strcmp(input,"������") == 0)
//	{
//		system("shutdown -a");
//		printf("��ϲ�㣬ȡ���˹ػ�\n");
//	}
//	else
//	{
//		printf("��ܵ�Ƥ��ʮ���ڹػ�!\n");
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
//	printf("�������!\n");
//	//rand()��������������0-32767
//	ret = rand()%100+1;		//��0-32767��%100֮���������0-99��+1֮��Ϊ1-100
//	while (1)
//	{
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("�´���!\n");
//		}
//		else if (guess < ret)
//		{
//			printf("��С��!\n");
//		}
//		else
//		{
//			printf("��ϲ�㣬�¶���!\n");
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
//	//��������Ϸ
//	//ʱ���  ��ǰʱ��-�������ʼʱ��(1970.1.1  0:0:0) =��xxxx����
//	// time_t time(time_t *timer);����ֵ��time_t����,�������ǳ�����
//	srand((unsigned int)time(NULL));
//	//���game()�����е�randʹ��
//	int input = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			system("cls");
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ!");
//			break;
//		default:
//			printf("ѡ�����!������ѡ��!\n");
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
//	//�˷��ھ���
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
//	//�������ж�
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//�ж�i�Ƿ�������
//		//�������жϹ���
//		//1.�Գ��������� 2->i-1����
//		for (j = 2; j <= sqrt(i) ; j++)
//		{
//			if (i%j == 0)
//			{
//				break;		//������˵����������
//			}
//		}
//		if (j >sqrt(i))
//		{
//			printf("%d ", i); //ֻ��1�ͱ���֤��������
//		}
//
//		//2.һ�����ض�����д�� a*b����ʽ
//		//���ж������У�a��b��������һ������С�ڵ��� ����i
//	}
//}

//test10
//int main()
//{
//	//շת��������������
//	int m, n, k;
//	scanf("%d %d", &m, &n);
//	while (m%n)		//�����Ϊ0ʱѭ����Ϊ0ʱ����
//	{
//		k = m%n;
//		m = n;
//		n = k;
//	}
//	printf("�������Ϊ:%d\n", n);
//	return 0;
//}

//test09
//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������:\n");
//		scanf("%s", password);
//		//�ַ����ıȽϲ���ֱ��ʹ�� == ������ʹ��strcmp����
//		//����ַ������ȴ��ڱȽϵģ����ش���0�����֣�С���򷵻�С��0�����֣������򷵻�0
//		if (strcmp(password, "123456") == 0)	
//		{
//			printf("��½�ɹ���\n");
//			break;
//		}
//		else
//		{
//			printf("������������ԣ�\n");
//		}
//	}
//	if (i == 3)
//		printf("������������˳�����\n");
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
//	//�������еĶ��ֲ��ҷ�
//	//ʱ�临�Ӷ� log2N
//	int arr[] = { 1, 2, 3, 4, 5, 6, 8, 9, 10 ,11, 12};
//	int key,mid;
//	scanf("%d", &key);		//Ҫ���ҵ�Ԫ��
//	int size = sizeof(arr) / sizeof(arr[0]);		//Ԫ�ظ���
//	int left = 0;		//���±�
//	int right = size - 1;	//���±�
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
//			printf("�ҵ��ˣ��±�Ϊ:%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("�Ҳ�����Ԫ��!\n");
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
//		sum += ret;		//����1-n�Ľ׳����
//	}
//	printf("%d\n", sum);
//	//system("pause");
//	return 0;
//}

//tset 05
//int main()
//{
//	char ch = 0;
//	while ((ch = getchar()) != EOF)		//����Ϊ�����ַ�ʱ����������getcharһ��ֻ���ȡһ���ַ�����λ��������Ҳ�����
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
//	printf("���������룺\n");
//	scanf("%s", password);
//	//���뻺������ʣ�� '\n'�����س���
//	//�����ڴ˴��Ӹ� getchar()ʵ�ֶ�ȡ '\n'�Ĳ��������ڶ�ȡ���δ�������
//	while ((ch = getchar()) != '\n')
//	{
//		//����Ҫ���ݣ�ֻ��Ҫ��ȡ����
//	}
//	//������Ϊ 123456 ABCD(�˴��и��ո�)��ʱ�򣬺����ֻ�����⣬��Ϊscanfֻ���ȡ�ո�֮ǰ������
//	//��ʱ�����ʹ��whileѭ��ֱ����ȡ �س���ֹͣ
//	printf("��ȷ��:Y/N?\n");
//	ret = getchar();		//getchar��ȡ������������֮�����õĻس�������������������ret
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�!\n");
//	}
//	else
//	{
//		printf("ȡ��ȷ��!\n");
//	}
//	//���Ϊȡ��ȷ�ϣ���Ϊret��ֵΪ10������'Y'
//	//printf("%d\n", ret);  //ret ֵΪ10 ��10Ϊ�س�����ASCII��ֵ
//	system("pause");
//}


//test03
//int main()
//{
//	char ch;
//
//	//while(scanf("%d",&n)!=0) �ȼ��� while(~scanf("%d",&n))
//	//scanf����������ȷ�������ʽ�������������򷵻�2,һ���ͷ���1��û���򷵻�0
//	//EOF = end of file  ->�ļ�������־  ��������-1
//	while ((ch = getchar())!= EOF)  //ctrl+Z�������
//	{
//		putchar(ch);
//	}
//	system("pause");
//}


//tset02
//int main()
//{
//	char arr1[] = "abc";  //Ĭ�Ϻ��� '/0'������ʶ��
//	char arr2[] = { 'a', 'b', 'c'};  //������'/0'������ʶ��
//
//	printf("%d\n", strlen(arr1));
//	printf("%d\n", strlen(arr2));
//	printf("\\n\n");
//	printf("%d\n", strlen("C:\tset\x92\test.c"));   
//	//	\ddd��ʾ�˽�����ת��Ϊʮ���ƺ��ASCII���Ӧ�ı�ʶ��     \xdd��ʾʮ�����Ƶ�
//	system("pause");
//	return 0;
//}


//tset01
//int main()
//{
//	int j = 072;		//�˽�����
//	int k = 0x2A;		//ʮ��������
//	int m = 10;
//
//	printf("%d\n", j);
//	printf("%#X\n", m);		//���ʮ�����ƣ��ַ�Ϊ��д,��ʽΪ0Xdd
//	printf("%#x\n", m);		//���ʮ�����ƣ��ַ�ΪСд,��ʽΪ0xdd
//	printf("(are you ok??)\n");
//	system("pause");
//	
//}
