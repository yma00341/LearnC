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
//	//��ӡ����10��hehe
//	//j�� 0~9֮��Ϊ10
//	//i=1֮��j��10��ʼ���ڶ���Ƕ�ײ�ѭ��
//	
//	return 0;
//}

//int main()
//{
//	int i, j;
//	for (i = 0, j = 0; j = 0; ++i, j++)
//		j++;
//	//k=0�����ֵ���ʽ������Ϊ��
//	//��ѭ����ִ�У�ѭ��0��
//	return 0;
//}


//����n�Ľ׳�
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

//����1!+����+10��
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

//���������в��Ҿ�������֣����ַ���
//int main()
//{
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


//����ַ��������ƶ����м�
//int main()
//{
//	char arr1[] = "Welcome to bit!!!!!!";
//	char arr2[] = "####################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	//�ϱ��ʽ�����Ը�Ϊ��right=sizeof(arr1)/sizeof(arr1[0])-1,��Ϊ�ַ���arr1��������you���ص�'\0'�����Ҫʹ��sizeof���㣬��Ҫ-2
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

//��д����ʵ�ֵ�¼ϵͳ
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

//���Լ����շת�����
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

//��������Ϸ
void menu();
void game();
int main()
{
	//ʱ���  ��ǰʱ��-�������ʼʱ��(1970.1.1  0:0:0) =��xxxx����
	// time_t time(time_t *timer);����ֵ��time_t����,�������ǳ�����
	srand((unsigned int)time(NULL));
	//���game()�����е�randʹ��
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
			break;
		case 0:
			printf("�˳���Ϸ!");
			break;
		default:
			printf("ѡ�����!������ѡ��!\n");
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
	printf("�������!\n");
	//rand()��������������0-32767
	ret = rand()%100+1;		//��0-32767��%100֮���������0-99��+1֮��Ϊ1-100
	while (1)
	{
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���!\n");
		}
		else if (guess < ret)
		{
			printf("��С��!\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���!\n");
			system("pause");
			system("cls");
			break;
		}
	}

}


//int main()
//{
//	//�˷��ھ���
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d = %-2d  ",i,j, i*j);
//			//%-2d����������%2d�Ҷ�������
//		}
//		printf("\n");
//	}
//	return 0;
//}


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