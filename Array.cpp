#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

//int main()
//{
//	//����ı���
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//		//[]�±����ò�����
//	int i = 0;
//	int size = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < size; i++)
//	{
//		printf("%p\n", &arr[i]);
//		//��ַ֮�����������Ҳ�4���ֽڣ����洢һ��int��Ԫ������Ҫ�Ŀռ�
//	}
//	return 0;
//}


//������
//int main()
//{
//	int arr[4] = { 1, 2, 3, 4 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	printf("%d\n", *arr);
//	//������ʵ������������Ԫ�صĵ�ַ
//	//��������������
//	//1.sizeof
//	printf("%d\n", sizeof(arr));
//	//��ʱ����������ʾ������ַ,������ĵ�λ���ֽ�
//	//2.&arr�������������������飬ȡ��������������ĵ�ַ
//	printf("%p\n", &arr);
//	//ȡ��������������ĵ�ַ�����Ǵ�ӡ�Ľ����ʵ����������ͬ��ע������
//	
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);		//����4���ֽ�
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0]+1);		//����4���ֽ�
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);		//����16���ֽ�
//
//}

//��ά����
//int main()
//{
//	int arr[3][4] = { { 1, 2, 3 }, { 3, 4, 5, 6 }, { 7, 8, 9, 10 }};
//	//��ά������в���ʡ�Դ�����ʱ��
//	int i, j;
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 4 ; j++)
//		{
//			printf("&arr[%d][%d] = %p \n", i, j, &arr[i][j]);
//			//��ά����洢��ʱ��Ҳ��������
//		}
//		
//	}
//	return 0;
//}


//ð������
void bubble_sort(int *arr,int size)
{
	int i, j,temp;
	for (i = 0; i < size - 1; i++)
	{
		//��Ҫ����Ԫ�ظ���-1��ð������
		int flag = 1;	//flag��־������������������,��Ϊ�Ż�����
		for (j = 0; j < size - i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 0;
				//�����󣬴�������flag��0
			}
			
			//�˴���break��������ѭ����
			//ԭ����breakֻ��������ѭ��֮�л���switch
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
	//���Ĳ���arr��ʵ��&arr[0],���Ա�������һ��ָ��
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}




