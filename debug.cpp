#include <stdio.h>
#include <windows.h>
#include <assert.h>

//int main()
//{
//	int i = 0;
//	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	//�˳���Ľ��Ϊ��ѭ��������i�ж�������Ϊ <= 11��ʱ����Ǳ���ջ�ƻ�
//	//����ջ����ʹ�÷�ʽĬ������ʹ�øߵ�ַ���˴����ȴ���i��
//	//�ɴˣ�������Խ�����֮���ֿ���a[12]����i�����Ĵ洢����
//	//��ʱi���ᱻ��Ϊ0���ɴ˱�ᷢ����ѭ��
//	//��VC 6.0�����£�<=10�����ѭ��
//	//��GCC �������£�<=11�����ѭ��
//	system("pause");
//	return 0;
//}


//�ַ�����������
//void my_strcpy(char* des, char* ori)	//�˺�������10�ֽ���7��
//{
//	while (*des++ = *ori++)
//	{
//		;
//	}
//}

//void my_strcpy(char* des, char* ori)	//8��
//{
//	assert(*des != NULL);	//���ԣ�����assertͷ�ļ�
//	assert(*ori != NULL);	//�Ὣ������ʾ����
//	while (*des++ = *ori++)
//	{
//		;
//	}
//}

//char* my_strcpy(char* des, const char* ori)	//10��
//{
//	//const���Է�ֹĿ�ĵغ�Դ��ַ��������д��
//	//����д�����޷����룬��ʾ��ֵָ��const����
//	//const����ָ�������*������ε���*p��������ͨ��p���ı�*p��ֵ
//	//const����ָ�������*�ұ����ε���p����p������ĵ�ַ�ǲ��ܱ��ı��
//	char* ret = des;
//	assert(*des != NULL);	//���ԣ�����assertͷ�ļ�
//	assert(*ori != NULL);	//�Ὣ������ʾ����
//	//��oriָ����ַ���������desָ��Ŀռ䣬����'\0'
//	while (*des++ = *ori++)
//	{
//		;
//	}
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[] = "################";
//	char arr2[] = "bit";
//
//	printf("%s\n", my_strcpy(arr1, arr2));
//	system("pause");
//	return 0;
//}




//�ַ������Ⱥ���
int my_strlen(const char* ori)
{
	int count = 0;
	assert(ori != NULL);
	while (*ori != '\0')
	{
		count++;
		ori++;
	}
	return count;
}

int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);

	return 0;
}