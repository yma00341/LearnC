//��Դ�ļ�Ϊ��չʾ scanf�Ĳ�ͬ�����Լ���ȡ���

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//#include <stdio.h> 
//int main()
//{
//	//���� i love you��ֻ�����i
//	//scanf�����ո��ȡֹͣ
//	char str[80];
//	char ch;
//	scanf("%s", str);
//	printf("%s\n", str);
//	//�������
//	while ((ch = getchar()) != '\n')
//	{
//	}
//	scanf("%[^\n]", str);
//	printf("%s\n", str);
//	return 0;
//}

//�������
//#include <stdio.h> 
//int main()
//{
//	char str[80];
//
//	scanf("%[^\n]", str); //����'\n'������ȡ
//	printf("%s", str);
//	return 0;
//}

//����'\n'������ȡ,����str,������һ���ַ�
//scanf("%[^\n]%*c", str);

//����'\n'������ȡ,�������������������,Ȼ��������һ���ַ�������ַ���'\n'��
//��ʱ�����в������κ��ַ�
//scanf("%*[^\n]%*c");


//int c;
//while ((c = getchar()) != '\n'&&c != EOF);
//��ȡһ���ַ���ֱ����\n������EOFֹͣ
//�ȼ���
//scanf("*[^\n]");

#include <stdio.h>
int main()
{
	char  c;
	//ֱ�������ַ�aֹͣ��ȡ��
	//����a
	//��ȡ��a���һ���ַ��������c
	scanf("%*[^a]%*c%c", &c);
	printf("%c\n", c);
	return 0;
}