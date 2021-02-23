#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/*
�ڴ��ʹ�÷�ʽ��
1.����һ������
int a = 10; //�ֲ����� - ջ��
int g_a = 10; //ȫ�ֱ��� - ��̬��

2.����һ������
int arr[10] = {0};//ջ�ռ俪��

3.���紴��һ�����ܻ�ı�Ĵ�ռ�����
��̬�ڴ����(����)
malloc
free
calloc
realloc
*/


//malloc��free
/*
malloc
���ڴ�����һ���������õĿռ䣬������ָ�����ռ��ָ��
*������ٳɹ��򷵻�ָ�򿪱ٿռ��ָ��
*������ٲ��ɹ��򷵻�NULL
*����ֵ��������void* ������malloc��������֪�����ص�����

free
*�������ptrָ��Ŀռ䲻�Ƕ�̬���ٵģ���ôfree��������Ϊ��δ�����
*�������ptr��NULLָ�룬����ʲô������
*/



//calloc
/*
void *calloc(size_t num,size_t size);
num��Ԫ�صĸ���
size��ÿ��Ԫ�ص��ֽڳ���
**���ٿռ䲢��Ԫ�س�ʼ��Ϊ0
*/


//realloc
/*
void* realloc(void* memblock,size_t size);
memblock:ָ��֮ǰ���ٵĵ�ַ
size:�µĿռ��С(�����)
������̬�����ڴ�Ĵ�С
ע�����(׷�ӿռ�ʱ)
*������ռ��㹻��ʱ��ֱ�ӵ���������ԭ�ȵ�p
*����ռ䲻���ʱ��һ���Կ����µ�����Ҫ��Ŀռ䣬����ͬʱ������������ԭ�ȿռ�free�������µĵ�ַ
*/


/*
�������⣺
1.�Կ�ָ����н����ã�����һ��Ҫ���鷵�ص��ǲ��ǿ�ָ��
2.�Զ�̬�����ڴ��Խ����ʣ����ʵĵ�ַ��С�����˿��ٵ�
3.�ԷǶ�̬���ٵĿռ�ʹ��free�ͷţ���̬���ٵķ��ڶ������Ƕ�̬����ջ�����ͷŻ������
4.ʹ��free�ͷŶ�̬���ٵ�һ�����ڴ棬����ʹ��p��ʱ��p++,��ָ��ĵ�ַ��䣬��ʱ��free(p)������
5.��ͬһ�鶯̬���ٵ��ڴ����ͷ�
6.�����ͷŶ�̬���ٵĿռ䣬����ڴ�й©�����ú����ڵ�mallocҪ�ǵ÷��ص�ַ�����ں������ͷ���
*/


//int main()
//{
//	//���ڴ�����10�����εĿռ�
//	int* p = (int*)malloc(5 * sizeof(int));
//	if (p == NULL)
//		printf("%s\n", strerror(errno));
//	else
//	{
//		//ʹ��malloc���ٵĿռ�
//		for (int i = 0; i < 5; i++)
//			*(p + i) = i;
//		for (int i = 0; i < 5; i++)
//			printf("%d ", *(p + i));
//	}
//	//���迪�ٵĲ����㣬ϣ���ܸ���
//	//p = (int*)realloc(p, 10 * sizeof(int));	
//	//���ر��ķ��գ��������ʧ��ԭ�ȵ�p�ͻᶪʧ
//	//����ԭ�ȿ��ٵĺ����ڴ��Ǳ�ռ�õģ��ͻ�Ƿ�����
//	//ʹ���µ�ָ�����
//	int* ptr = (int*)realloc(p, 10 * sizeof(int));	
//	if (ptr!= NULL)
//	{
//		p = ptr;//����ʹ��ԭ�ȵ�pȥά���ڴ棬��ȥʹ��p
//	}
//
//	free(p);	//�ռ���Ȼ���ͷ��ˣ�����p��Ȼ������ָ���Ǹ��ռ�
//	p = NULL;	//�ÿգ�����
//	return 0;
//}



//�������� - ��һ�ֽṹ���еĳ�Ա���ṹ������һ���Ա
//����ǰ��������һ����Ա��sizeof���صĽṹ��С����������������ڴ�
struct S
{
	int n;
	//1.ʹ��arr[]����arr[0]
	//int arr[];
	//2.ģ����������
	int * arr;
};
int main()
{
	//1.arr[]����arr[0]��ʹ��
	//�����������ڵĽṹ��Ŀռ�Ĵ���ʹ��malloc����
	//struct S ���ٵĿռ���n �����濪�ٵ�һƬ�����ռ��Ǹ�����ģ�5������Ԫ��
	//struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
	//ps->n = 100;
	//int i = 0;
	//for (i = 0; i < 5; i++)
	//{
	//	ps->arr[i] = i;//0,1,2,3,4,5
	//}
	//2.ģ����������
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
	//�ͷ��ڴ�
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}

//������
//void GetMemory(char *p)
//{
//	p = (char*)malloc(100);
//	//�ϸ���˵�����ڴ�й©������
//}
//void Test(void)
//{
//	char *str = NULL;
//	GetMemory(str);
//	//ֵ���ݣ�û�з��ؿ��ٿռ�ĵ�ַ
//	strcpy(str, "hello world");
//	//�����������������ʷǷ��ڴ�
//	printf("%s",str);
//}
//��������Tsst�����ʲô���
//������,GetMemory����ʱ��p��ŵ���NULL
//malloc�ڶ�����һƬ�����ռ䣬�ѷ���ֵ����p��p��������ָ�򿪱ٵĿռ�
//GetMemory��������֮��û�з��ص�ַ�����ٿռ�ĵ�ַ�Ͷ�ʧ�ˣ�str����NULL,strcpy��������



//������
//int* f1()
//{
//	int x = 10;
//	return (&x);
//	//������⣬x����ջ�����ٵĿռ䣬��������֮��������
//	//x��ָ��ָ��Ŀռ��û��
//}
//int f2()
//{
//	int *p;
//	*p = 10;
//	return p;
//	//�Ƿ������ڴ棬p�Ǹ�Ұָ�룬û��ָ����Ч�Ŀռ�
//}


int main()
{

	return 0;
}