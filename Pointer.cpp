#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <search.h>
/********************************************************************************/
//�ҵ�����ָĿ��Ϊ��ַ���ڴ浥Ԫ
//ͨ����ַ�ҵ�����ı�����Ԫ
//һ��С���ڴ浥Ԫ�Ĵ�С�� 1 Byte��һ���ֽ�
//����32λ�Ļ�����������32����ַ�ߣ�ÿ����ַ�߶����������ź�
//�ͻ���� 2^32 ����ַ����
//32λ��ƽ̨�ϣ�ָ���С��4�ֽڣ�64λƽ̨����8�ֽ�
//ͬһ��ƽ̨�ϣ�����ʲô���͵�ָ���������С����ͬ��
//ָ������������Ϊ�˱�ʾ��ָĿ�������
//��ͬ���͵�ֻ�ܱ�����������ʱ������Բ�ͬ���������ڵĲ�ͬ�ֽ������в���
//���� int* p���������ò��� *p = 0 ��ʱ�����ĸ��ֽڲ���
//���� char* p ,�������ò��� *p = 0��ʱ��ֻ���һ���ֽڽ��в���
//��ָ�����;�����ָ����н����ò�����ʱ�������ʵĿռ�Ĵ�С
//ָ�����;�����ָ����һ���߶�Զ���� p+1 �������ٸ��ַ���(int����4�ֽ�)
/*******************************************************************************/
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int* p = &a;	//ָ�����������p�������� int*��������ŵ�ַ
//	return 0;
//}

//ָ�����͵�����
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	//arr������������Ԫ�ص�ַ
//	int* p = arr;	//������һ��ָ�����������˵�һ��Ԫ�صĵ�ַ
//	//����Ҫ����������ȫ������1
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = 1;
//		//ͨ���˲������԰���������ȫ���ĳ�1
//		//��������������Ͳ��ԣ����޷�ʵ�ִ˲���
//	}
//	printf("%d", i);
//	return 0;
//}


//Ұָ����ָ��ָ���λ���ǲ���֪��ָ�룬Ҫ����Ұָ��
//����Ұָ���ԭ��ָ��δ��ʼ����ָ��Խ����ʣ�ָ����ָ���ڴ�ռ䱻�ͷ��ˣ�


//ָ�������
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int* p = arr;
//	for (i = 0; i < size; i++)
//	{
//		printf("%d ", *p);
//		p++;	//ָ���һ��int�ͱ������ֽ���
//	}
//	//&arr[10] - &arr[0] == 10,ָ���ȥָ��õ�����Ԫ�صĸ���
//}

//C��������ָ������Ԫ�ص�ָ����ָ���������һ��Ԫ�ص�ָ�������Ǹ��ڴ�λ�õ�ָ����бȽ�
//���ǲ�������ָ���һ��Ԫ��֮ǰ���Ǹ��ڴ�λ�õ�ָ����бȽ�






//��������
//int main()	//����ָ�� ����������ָ�� (*parr)[]			ָ�����飺���ָ������� *parr[]  ����Ϊ�����ŵĽ�����ȼ�����*
//{
//	char* arr[10];
//	char* (*parr)[10] = &arr;
//	//��ʼ���ķ�����
//	//���� &arr������ĵ�ַ��������Ҫ *parrָ�����洢
//	//����arr������10��Ԫ�أ�������Ҫ����ָ�����洢10��Ԫ�أ���(*parr)[10]
//	//���arr[10]�����ʱ������������char* ������(*parr)[10] ���������Ҳ��Ҫ�� char *
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int(*pa)[10] = &arr;
//	int i = 0;
//	//����ָ��Ĵ�ӡ����
//	for (i = 0; i < 10; i++)
//	{
//		//printf("%d ", (*pa)[i]);
//		printf("%d ", *(*pa + i));	//*pa == arr ����Ϊ��&arr�Ľ�����,����*pa+i���൱���ҳ�ÿ��Ԫ�صĵ�ַ���ٽ��н����ò������õ�ÿ��Ԫ�ص�ֵ
//	}
//	printf("\n");
//	return 0;
//}

//����ָ����÷�,һ���õ���ά��������
//void my_print(int(*p)[5], int x, int y);
//int main()
//{
//	int arr[3][5] = { { 1, 2, 3, 4, 5 }, { 2, 3, 4, 5, 6 }, { 3, 4, 5, 6, 7 } };
//	my_print(arr,3,5);	
//	//��ν�����������׵�ַ������sizeof��ȡ��ַ����������ڶ�ά�������棬��Ԫ�ؾ��ǵ�һ��Ԫ��
//	//��ÿһ���־��ж���ʱ��n��Ԫ�أ��ڴ˼�Ϊint [5]
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
//			//����д���ȼ�
//			//*(p+i)����Ѱ�ҵڼ��У�*p����ָ�����Ԫ�ش�����һ�е�����Ԫ�ش�С���ܺ�
//			//*(p+i)+j��Ѱ�ҵ�i�еĵ�j��Ԫ�أ�i+1��ָ��һ��
//			//�����Ϊ(*p+i)����ÿ�λ�������һ����ά������Ԫ�صĴ�С��������һ��
//
//			//*(p+i)+jҲ������ָ�룬����ͨ������Ľ�������Ѱ����ָ��ֵ
//			//arr[i] == *(arr+i) == *(p+i) == p[i]
//			
//		}
//		printf("\n");
//	}
//}

//�ַ�ָ��
//int main()
//{
//	char ch = 'W';
//	char *p = &ch;
//	const char *p2 = "abcdef";
//	//��ʵ���ַ������ַ�a�ĵ�ַ����p2
//	//�Ǹ������ַ����������޸����ݣ���const�����
//
//	int(*p3[10])[5];
//	//����p3��һ�����飬����������ʮ��Ԫ�أ�ÿ��Ԫ����ָ������
//	//���ÿ��ָ��������ָ�룬������Ԫ��
//}

//����ָ���������һ��ָ������ĵ�ַ
//&������ �� ������  ���Ǻ����ĵ�ַ����%p��ӡû���κ�����
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

//�Ķ�����
//����1
//(*(void(*)())0)();
//��������һ���£� int (*p)[5]�������pȥ������int (*)[5]�ͻ��Ϊp������
//void(*)(char*)ͬ��Ҳ��һ�����ͣ��������һ������ָ��
//�ڴˣ�0֮ǰ�ģ�void(*)()��һ��ָ��void�ĺ���ָ������
//��ô�˴�����ǿ��ת������0ǿ��ת��Ϊĳ�����ĵ�ַ������Ϊvoid(*)()
//��ǰ���*������,��(void(*)())0���н����ã�����0��ַ���ĸú���
//�������Ŵ�������Ҫ����
//�ܽ᣺��0ǿ��ת���ɺ���ָ������ͣ���ָ��ָ����������޲η���������void�����н����õ���0λ��ַ�ĸú���

//����2
//void(*signal(int, void(*)(int)))(int);
//signal������������ int �� void(*)(int)     �ڶ��������Ǻ���ָ������
//����ķ������;��ǰ�signal(int, void(*)(int))����ȥ������void(*)(int)
//���ǰ���ԭ����д����void(*)(int) signal(int, void(*)(int))�����Ǵ�д���Ǵ����
//���׿�����void(*           	signai( int , void(*)(int) )         )(int)
//signal��һ������������������������һ����int���ͣ�һ���Ǻ���ָ�룬�ú���ָ��ָ��ĺ����Ĳ�����int������������void
//���������ķ�������Ҳ�Ǻ���ָ�룬�ú���ָ��ָ��Ĳ���������int������������void
//��������typedef���м�
//typedef void(* pfun_t)(int);
//���ں���ָ�����ͣ���������Ҫ�ŵ������ָ�벿��
//pfun_t signal(int,pfun_t);�ͳ�Ϊ��ԭ���ĺ���





//����ָ��
//int add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int(*pa)(int ,int ) = add;
//	printf("%d\n", (*pa)(2, 3));
//	//ͨ��������pa�ҵ�������Ȼ�󴫵ݲ���
//	printf("%d\n", (pa)(2, 3));
//	//add����������pa������add��pa��һ���£�Ҳ�������5
//	//��Ϊ��������������һ����ַ
//	printf("%d\n", (**pa)(2, 3));
//	printf("%d\n", (***pa)(2, 3));
//	//������������Ϊ5
//	//�����������������*��ȫ�ǰ��裬û�о��������
//	//һ�㲻��ʹ�ú������ַ���
//	
//	return 0;
//}



//����ָ������
//���ȸ�ϰָ�����飬int *arr[10],�����ÿ��Ԫ��������int *����10��Ԫ��
//���Ҫ�Ѻ����ĵ�ַ�浽��������
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
//	//add,sub�����Ĳ��������Լ��������Ͷ���һ����
//	//��Ҫһ��������Դ���ĸ������ĵ�ַ��������ָ�������
//	int(*par[2])(int, int) = { add, sub };
//	int i = 0;
//	for (i = 0; i < 2; i++)
//	{
//		printf("%d\n",par[i](2, 3));
//	}
//	return 0;
//}

//дһ������ָ��pf�ܹ�ָ��my_strcpy
//дһ������ָ������pfArr���ܹ����my_strcpy�����ĵ�ַ���ĸ�
//char * my_strcpy(char* dest,const char* src)
//char* (*pf)(char*, const char*) = my_strcpy;
//char* (*pfArr[4])(char *, const char*);


//����ָ�����鰸����������
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
//void Calc(int(*pf)(int, int))	//��Ҫ����ĺ�����ַ����
//{
//	//�ܺõĽ���������������
//	//��ͬ�Ĵ������ͨ���������
//	int x = 0;
//	int y = 0;
//	printf("����������������:>");
//	scanf("%d%d", &x, &y);
//	printf("%d\n", pf(x, y));
//}
//int main()
//{
//	//ת�Ʊ�
//	int input = 0;
//	//int x = 0;
//	//int y = 0;
//	//int(*pfArr[5])(int, int) = { 0, Add, Sub, Mul, Div };
//	do
//	{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		
//		if (input >= 1 && input <= 4)
//		{
//			printf("����������������:>");
//			scanf("%d%d", &x, &y);
//			int ret = pfArr[input](x, y);
//			printf("%d", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�!\n");
//
//		}
//		else
//		{
//			printf("ѡ�����!\n");
//
//		}
//	} while (input);
//
//	do{
//		menu();
//		printf("��ѡ��:>");
//		scanf("%d", &input);
//		//�ص�������ͨ������ָ����õĺ��� Calc
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
//			printf("�˳���\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��!\n");
//			break;
//		}
//	} while (input);
//
//	return 0;
//}
//



//ָ����ָ�������ָ��
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int (*p)[10] = &arr;	//ȡ������ĵ�ַ
//
//	int(*pfArr[4])(int, int);
//	int (*(*ppfArr)[4])(int ,int) = &pfArr;		//ָ����ָ�������ָ��
//	//ppfArr���Ⱥ�*��ϣ���һ��ָ�룬֮����[]�����һ�����飬����������ָ��
//	//ָ��ָ���������4��Ԫ��
//	//ָ��������ÿ��Ԫ�ص�������һ������ָ�룬������	int(*)(int,int)
//
//	return 0;
//}



//��ϰ
//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	//ָ������
//	//int * arr[10];
//	//����ָ��
//	//int* (*pa)[10] = &arr;
//	//����ָ��
//	int(*pAdd)(int, int) = Add;
//	//int sum = (*pAdd)(1, 2);
//	//int sum = pAdd(1, 2);
//	//Add(1, 2);
//	//��������д��������ʵ��Add�ĵ���
//	//����ָ������
//	int(*pArr[5])(int, int);
//	//ָ����ָ�������ָ��
//	int(*(*PArr)[5])(int, int) = &pArr;
//	//����ȥ����Ϊ��������
//
//}


//void BubbleSort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	int temp;
//	//���������
//	for (i = 0; i < sz - 1; i++)
//	{
//		//һ��������ٴ�
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
//	//ð������ֻ��������������
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






//qsort ���������������͵ĺ���
//void qsort(void *base, size_t num, size_t width, int(__cdecl *compare)(const void *elem1, const void *elem2));
//4������,���һ����һ������ָ�룬��������void����������int
//base:start of target array	Ҫ�����������ʼλ��		
//num:array size elements	���ֵ�Ԫ�ظ���
//width:element size in bytes	(һ��Ԫ�ش�С),ѡ��sizeof(arr[0])
//compare:comparison function(�ȽϺ���)����������ֱ��һ���ð�ݾͿ��ԣ��������ƽṹ��������Ҫ��Ѱ����
//compare����:	elem1<elem2,����<0����ȷ���0�����ڷ���>0������ͨ��elem1-elem2
//elem1��elem2��	Ҫ�Ƚϵ�����Ԫ�صĵ�ַ������void*���Խ����������͵ĵ�ַ

//void*ָ��
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	void* p = &a;	//�����͵�ָ�룬û�о�������
//
//	//*p = 0;		//�����ᱨ������֪�����ʶ����ֽ�
//
//	//void*ָ����Խ����������͵ĵ�ַ
//	//void*���͵�ָ�벻�ܽ��н����õĲ���
//	//Ҳ���ܽ��мӼ��˳�����֪���������ֽ�
//}

//struct  stu
//{
//	char name[20];
//	int age;
//};
//
//int cmp_int(const void *e1, const void *e2)
//{
//	//�Ƚ���������
//	//ͨ��ǿ������ת�����Ա�Ϊ��Ӧ������
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
//	//�����ȣ�������
//}
//
//int cmp_struct_by_age(const void *e1,const void *e2)
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//
//int cmp_struct_by_name(const void *e1, const void *e2)
//{
//	//�Ƚ����־��ǱȽ��ַ���
//	//�ַ����Ƚϲ���ֱ�ӱȽϣ���strcmp����,����ʵ����ĸ˳�������
//	//���ڷ��ش���0����ȷ���0��С�ڷ���С��0����
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
////����bubble_sortģ��qsort����
////���õ�ʱ��֪�����Ƚ�Ԫ�ص��������ͣ�����ָ����void*��������������Ԫ��
//void swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char temp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = temp;
//		//ѭ��ֱ������Ϊ�����ֵ
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
//			//�˴�������Ҫ��������ݵ����򷽷�
//			if (compare((char*)base + j*width, (char*)base + (j + 1)*width) > 0 )
//			{
//				//����
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


//������
//int main()
//{
//	//��������ʾ��Ԫ�صĵ�ַ��һ�������������
//	//1.sizeof(������) - ��������ʾ��������
//	//2.&������ - ��������ʾ������������
//	//��������
//	int arr[] = { 1, 2, 3, 4 };
//	printf("%d\n", sizeof(arr));//16 - sizeof���������������ĳ���
//	printf("%d\n", sizeof(arr+0));//4/8 - �������������ʾ��Ԫ�ص�ֵ��+0���Ǳ�ʾ��Ԫ�صĴ�С
//	printf("%d\n", sizeof(*arr));//4 - �����׵�ַ�����ã���Ԫ�ص����ʹ�С
//	printf("%d\n", sizeof(arr+1));//4/8 - �ڶ���Ԫ�صĵ�ַ��С����ͬƽ̨��4����8
//	printf("%d\n", sizeof(arr[1]));//4 - �ڶ���Ԫ�صĴ�С
//	printf("%d\n", sizeof(&arr));//4/8 - &aȡ����������ĵ�ַ����������ĵ�ַҲ�ǵ�ַ����ַ�Ĵ�С����4����8
//	printf("%d\n", sizeof(*&arr));//16 - &a������ĵ�ַ������ĵ�ַ�����÷��ʵ������飬����������С
//	printf("%d\n", sizeof(&arr+1));//4/8 - ȡ��ַ֮���ǵ�ַ����ַ�Ĵ�С4����8
//	printf("%d\n", sizeof(&arr[0]));//4/8 - ȡ��һ��Ԫ�صĵ�ַ��ַ����С4����8
//	printf("%d\n", sizeof(&arr[0]+1));//4/8 - �ڶ���Ԫ�ص�ַ��4����8
//	//�ַ�����
//	const char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; //6��Ԫ��
//	printf("%d\n", sizeof(arr));//6 - �����С���ַ�������
//	printf("%d\n", sizeof(arr+0));//4/8 - ��Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*arr));//1 - �׵�ַ��������Ԫ�����͵Ĵ�С
//	printf("%d\n", sizeof(arr[1]));//1 - �ڶ���Ԫ�صĴ�С
//	printf("%d\n", sizeof(&arr));//4/8 - �������ǵ�ַ����ַ����4/8���ֽ�
//	printf("%d\n", sizeof(&arr+1));//4/8 - ����������������飬���Ǳ����ϻ��ǵ�ַ
//	printf("%d\n", sizeof(&arr[0]+1));//4/8 - �������ǵ�ַ���˴������ǵڶ���Ԫ�صĵ�ַ
//	printf("%d\n", strlen(arr));//���ֵ����Ϊ��֪����ʱ���ҵ�'\0'������־
//	printf("%d\n", strlen(arr+0));//���ֵ��������������Ԫ�ص�ַ���͵�һ��д���ȼ�
//	printf("%d\n", strlen(*arr));//strlen�����Ĳ���Ҫ���ǵ�ַ���˴�����'a' - 97- 0x61���Ƿ�����
//	printf("%d\n", strlen(arr[1]));//�˴�����98��Ҳ�Ǵ���
//	printf("%d\n", strlen(&arr));//err���޷���const char (*)[6]ת��Ϊconst char *
//	printf("%d\n", strlen(&arr[0]+1));//���������ֵ��1	
//	//�ַ���
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7 - ��ռ�ռ����'\0'�����������Ĵ�С
//	printf("%d\n", sizeof(arr+0));//4/8 - �������ǵ�ַ
//	printf("%d\n", sizeof(*arr));//1 - ��Ԫ���������͵Ĵ�С
//	printf("%d\n", sizeof(arr[1]));//1 - �ڶ���Ԫ�ص����ݴ�С
//	printf("%d\n", sizeof(&arr));//4/8 - �������ǵ�ַ
//	printf("%d\n", sizeof(&arr+1));//4/8 - �������ǵ�ַ
//	printf("%d\n", sizeof(&arr[0]+1));//4/8 - �ڶ���Ԫ�صĵ�ַ���������ǵ�ַ
//	//�ַ�ָ��
//	char *p = "abcdef";
//	printf("%d\n", sizeof(p));//4/8 - ָ��
//	printf("%d\n", sizeof(p+1));//4/8 - ָ�뱾��
//	printf("%d\n", sizeof(*p));//1 - �ַ����ĵ�һ���ַ���С
//	printf("%d\n", sizeof(p[0]));//1 - �ַ����ĵ�һ���ַ���С
//	printf("%d\n", sizeof(&p));//4/8 - �������ǵ�ַ
//	printf("%d\n", sizeof(&p+1));//4/8 - �������ǵ�ַ
//	printf("%d\n", sizeof(&p[0]+1));//4/8 - ������Ҳ�ǵ�ַ
//	printf("%d\n", strlen(&p));//���ֵ��char** ��const char* ���Ͳ�ƥ��
//	//��ά����
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48
//	printf("%d\n", sizeof(a[0][0]));//4
//	printf("%d\n", sizeof(a[0]));//16 - ������ǵ�һ�еĴ�С
//	printf("%d\n", sizeof(a[0]+1));//4/8 - a[0]+1 �����ĵ�һ����Ԫ�صĵ�ַ��+1��ʾ�ڶ���Ԫ�صĵ�ַ
//	printf("%d\n", sizeof(*(a[0]+1)));//4 - ��һ�еڶ���Ԫ���������͵Ĵ�С
//	printf("%d\n", sizeof(a+1));//4/8 - �ڶ���Ԫ�صĵ�ַ��a�Ƕ�ά��������������˴�����Ԫ�ص�ַ
//									  //����ά�������Ԫ���ǵ�һ�У�����a���ǵ�һ�еĵ�ַ
//									  //a+1���ǵڶ��е�ַ
//	printf("%d\n", sizeof(*(a+1)));//16 - *(a+1) == a[1]���൱�ڼ���ڶ�������Ĵ�С
//	printf("%d\n", sizeof(&a[0]+1));//4/8 - �ڶ��еĵ�ַ��&a[0]������һ�еĵ�ַ����һ��+1���ǵڶ���
//	printf("%d\n", sizeof(*(&a[0]+1)));//16 - �ڶ�������Ĵ�С
//	printf("%d\n", sizeof(*a));//16 - *a��ʾ��һ��
//	printf("%d\n", sizeof(a[3]));//16 - ����������Ĵ�С
//
//	return 0;
//}



//������1
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int *ptr = (int *)(&a + 1);	//�����ַ+1������������
//	printf("%d,%d\n", *(a + 1), *(ptr - 1)); //2,5
//	//ptr-1 �������һ��Ԫ�أ�a+1�����ڶ���Ԫ��
//	return 0;
//}

//������2
//struct Test
//{
//	int Num;
//	char *pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}* p;
////����p��ֵΪ0x00100000�����б���ʽֵ�ֱ�Ϊ����
////��֪�ṹ��Test���͵ı�����С��20���ֽ�
//int main()
//{
//	p = (struct Test *)0x00100000;
//	//0x1��ֵ����1
//	printf("%p\n", p + 0x1);//0x00100014 - +1��������һ���ṹ�����͵Ĵ�С
//	printf("%p\n", (unsigned long)p + 0x1);//0x00100001 - ����ת��Ϊunsigned long����Ϊ1048576,
//										   //��+1��Ϊ1048577,��תΪʮ������
//										   //�������0x00100001
//	printf("%p\n", (unsigned int*)p + 0x1);//0x00100004 - int*����ָ��+1������ַ+4
//}

//������3
//int main()
//{
//	int a[4] = {1, 2, 3, 4};
//	int *ptr1 = (int *)(&a + 1);//����һ������Ĵ�С����תΪint* ����
//	int *ptr2 = (int *)((int)a + 1);
//	//(int)a+1����a�ĵ�ַתΪ����+1�����Ϊ��ַ���ƫ��1���ֽ�
//	//С�˴洢ʱ�򣬵��ֽڴ�͵�ַ
//	//01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 - a���ڴ�洢���
//	//ÿ��Ԫ���ĸ��ֽڣ����ֽڴ�͵�ַ
//	//���ƫ��һ���ֽ�֮��תΪint*������ptr2ָ��Ĵ�01���濪ʼ
//	//ptr2 Ϊ 00 00 00 02,С�˴洢
//	//������Ϊ 02 00 00 00 ��ʮ�����ƴ�ӡ�������
//	printf("%#x,%#x", ptr1[-1], *ptr2);//���� *(ptr1-1)
//	//ptr[-1]����ǰ���Ǹ��������ĩβ��Ԫ�أ���0x4
//
//	return 0;
//}

//������4 
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	//����Բ���Ŵ������ű���ʽ
//	//int a[3][2] = { 1, 3, 5 };
//	//����Ķ�û�г�ʼ��
//	int *p;
//	p = a[0];
//	printf("%d", p[0]);//���Ϊ1
//	return 0;
//}

//������5
//int main()
//{
//	int a[5][5];
//	int(*p)[4]; //ָ����4������Ԫ�ص�����
//	p = a;	//�˴�����������ԭ��˼·�����޷���ֵ
//	//a���������е����飬����ǿ�и���ֻ�����е�p
//	//p+4��p[4]�Ľ���ͻ�ָ��a[3][1]
//	//p[4][2]�൱��*(*(p+4)+2),����ָ��a[3][1]֮�����������Ԫ��
//	//����p[4][2]��ָ��a[3][3]
//	printf("%p,%d\n",&p[4][2] - &a[4][2],&p[4][2] - &a[4][2]);
//	//��ַ�����ʱ��p[4][2]��a[4][2]����ĸ�Ԫ��
//	//���Ϊ 0xfffffffc				-4
//	//-4 ԭ�� 10000000 00000000 00000000 00000100
//	//-4 ���� 11111111 11111111 11111111 11111100
//	//��ӡ��ַ��ʱ��ֱ�Ӱѷ����ӡ0xfffffffc
//	return 0;
//}

//������6
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int *ptr1 = (int *)(&aa + 1);
//	int *ptr2 = (int *)(*(aa + 1));
//	//aa����aa[0],����һ��Ԫ�أ�*(aa+1) == a[1]
//	//ptr2 ָ��ڶ�����Ԫ�صĵ�ַ
//	printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1)); //10,5
//	return 0;
//}

//������7
//int main()
//{
//	char *a[] = { "work", "at", "alibaba" };
//	//a����������Ԫ�أ����Ͷ���char*����������ַ������׵�ַ
//	char **pa = a;
//	//a����Ԫ�ص�ַ����'w'�ĵ�ַ�ŵ�pa�У�pa�Ǹ�ָ�������������char**
//	//a��������char*�ĵ�ַ��������Ҫchar**�����
//	pa++;
//	//paָ���Ԫ����char*�������ľ���char*�ı�������ָ��ڶ���Ԫ��
//	printf("%s\n", *pa); //���Ϊat
//	return 0;
//}


//������8
int main()
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char **cp[] = { c + 3, c + 2, c + 1, c };
	char ***cpp = cp;
	//cp�������Ԫ�ص�ַ�浽cpp
	printf("%s\n", **++cpp);	//���ΪPOINT
	//cpp��ǰ��++�������ú�õ�c+2Ԫ�أ��ٽ����ú�õ�cp����c+2Ԫ����ָ��c�����c[3]
	//��ӡ������c[3]��ŵ���PΪ��Ԫ�ص��ַ���POINT
	printf("%s\n", *--*++cpp +3);//���ΪER
	//��ǰ��++cpp�����ڵ�һ����ӡ�Լӹ������Դ�ʱ�����ú�õ�����c+1Ԫ�أ���--�õ�c
	//�ٽ�����֮��õ�����ENTER��E�ĵ�ַ��+3֮��ָ��ENTER��E����ӡ�ʹ�E��ʼ��ӡER
	printf("%s\n", *cpp[-2]+3);//���ΪST
	//*cpp[-2]+3�� **(cpp-2)+3
	//����ǰ��������ӡ�Ĺ�ϵ���˴�-2֮����ָ����cp�������Ԫ�ص�ַ�������õõ�c+3Ԫ��
	//�ٽ����õõ�FIRST��F�ĵ�ַ��+3֮���S��ʼ��ӡST
	printf("%s\n", cpp[-1][-1]+1);//���ΪEW
	//�ȼ���  *(*(cpp-1)-1)+1
	//�������������ӡ���ԼӺ��Լ��Ĺ�ϵ��cpp��ִ�д˴�ӡ�����ָ��c+2��
	//������֮��õ�c+2Ԫ�أ�c+2Ԫ��-1�õ� c+1 ���ٶ�c+1�����õõ�����NEW
	//��+1 ��E��ʼ��ӡEW
	return 0;
}