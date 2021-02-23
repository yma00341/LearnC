#include <stdio.h>
#include <string.h>
#include <assert.h>

//strlen - �ַ�������
//size_t strlen(const char * str);
/*
�ַ�����'\0'��Ϊ������־��strlen�������ص������ַ�����'\0'ǰ����ֵ��ַ�����������'\0'
����ָ����ַ�������Ҫ��'\0'��β
ע�⺯���ķ���ֵ��size_t�����޷���
ģ��ʵ��strlen
*/
int my_strlen(const char* str)
{
	int count = 0;
	assert(str);
	while (*str)	//�ȼ��� *str != '\0'
	{
		count++;
		str++;
	}
	return count;
}



//���Ȳ������Ƶ��ַ�������
//strcpy - �ַ�������
//char* strcpy(char* destination, const char* source);
/*
Copies the C string pointed by source into the array pointed by destination,
including the terminating null charcter(and stopping at that point)
Դ�ַ���������'\0'����
�ὫԴ�ַ����е�'\0'������Ŀ��ռ�
Ŀ��ռ�����㹻����ȷ���ܴ��Դ�ַ���
Ŀ��ռ����ɱ�
ģ��ʵ��strcpy
*/
char* my_strcpy(char * dest, const char * src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++)
	{
		//�����������ʵ��'\0'�Ŀ���
		//�� *dest = '\0'��ʱ�򣬱��ʽ�Ľ��Ϊ\0��Ϊ��
		//ѭ����Ȼͣ��
		;
	}
	//����Ŀ�Ŀռ����ʼ��ַ
	return ret;
}



//strcat - �ַ���׷��
//char* strcat(char* destination, const char* source);
/*
Դ�ַ���������'\0'Ϊ��β
��Ŀ�ĵص�'\0'��ʼ׷��
Ŀ��ռ�����㹻�����������޸ĺ���ַ���������
Ŀ��ռ������޸�
�ַ����Լ����Լ�׷�ӣ���Σ� - �����

ģ��ʵ��
*/
char* my_strcat(char* dest, char* src)
{
	assert(dest && src);
	char* ret = dest;
	//1.�ҵ�Ŀ���ַ���'\0'��λ��
	while (*dest)
	{
		dest++;
	}
	//2.׷���ַ���
	while (*dest++ = *src++)
		;
	return ret;
}

//strcmp - �ַ����Ƚϴ�С��ϵ
//int strcmp(const char& str1, const char* str2);
/*
�ȵĶ�Ӧ�ַ�����ACSII��ֵ�Ĵ�С
��Ӧλ��ȱȽ���һλ
��һ���ַ������ڵڶ����ַ������򷵻ش���0�����飬��һ����1
��һ���ַ������ڵڶ����ַ������򷵻�0
��һ���ַ���С�ڵڶ����ַ������򷵻�С��0�����֣���һ����-1
*/
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}


//���������Ƶ��ַ�������
//strncpy
//char* strncpy(char* destination, const char* source, size_t count);
/*
count �ĵ�λ��Ҫ�౶�����ֽ�
Դ���鲻���ʱ��'\0'����
*/
char* my_strncpy(char* dest,const char* source, size_t count)
{
	char* start = dest;
	//��ֵΪ������ֵΪ��ʱִ��ѭ��
	while (count && (*dest++ = *source++))
		count--;
	//�������꣬count��Ȼ��Ϊ0��ʱ��
	if (count)
	{
		//ʣ���׷��'\0'
		while (--count)
			*dest++ = '\0';
	}
	//����Ŀ��ռ�ĵ�ַ
	return (start);
}



//strncat
//char* strncat(char* destination, const char* source, size_t count);
/*
��Ŀ��ռ��'\0'��ʼ׷�ӣ��滻��'\0'
׷��ָ���������ַ������Զ���׷�ӵĺ������һ��'\0'
���׷�ӵ�count ����Դ�ַ����ĳ��ȣ��򳬹��Ĳ��ֲ���
*/
char* my_strncat(char* dest,const char* src,size_t count)
{
	assert(dest && src);
	char* start = dest;
	//1.�ҵ�Ŀ���ַ���'\0'��λ��
	while (*dest++)
		;
	//��Ϊwhile�����һ�Σ�����Ҫ--
	*dest--;
	//2.׷���ַ���
	while (count--)
	{
		//�����ַ���
		if (!(*dest++ = *src++))
			//��������src Ϊ'\0'��ʱ��!0Ϊ�棬�򷵻ص�ַ
			return (start);
	}
	//
	*dest = '\0';
	return (start);
}


//strncmp
//int strncmp(const char* destination, const char* source, size_t count);
/*
�Ƚϵ�����ĳ���ַ���һ������һ���ַ�����������num���ַ�ȫ���Ƚ���
*/



//�ַ�������
//strstr
//char* strstr(const char* str1, const char* str2);
/*
������str1���״γ���str2�ַ����ĵ�ַ
���򷵻ؿ�ָ��
*/
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* cp = (char*)str1;
	char *s1, *s2;
	if (!*str2)
		//���str2�ǿ��ַ�������'\0'���򷵻�str1�ĵ�ַ
		return ((char*)str1);
	while (*cp)
	{
		s1 = cp;
		s2 = (char*)str2;
		while (*s1 && *s2 && !(*s1 - *s2))
			//��s1��s2����Ϊ�գ���s1��s2��ASCII��ֵ��ͬ����!(*s1 - *s2)Ϊ��
			s1++, s2++;
		if (!*s2)
			//���Ѱ����ϣ�s2ֱ��'\0'����ƥ��ģ����ؿ�ʼѰ��ʱ���str1�ĵ�ַ
			return (cp);
		//û��ƥ��ģ���ǰһ�ο�ʼѰ�ҵ���һ���ַ�����ƥ��
		cp++;
	}
	//û�ҵ�ƥ���ַ������ؿ�ָ��
	return (NULL);
}



//strtok
//char* strtok(char* str, const char* sep);
/*
sep�����Ǹ��ַ����������������ָ������ַ�����
��һ������ָ��һ���ַ�����������0�����߶����sep�ַ�����һ�����߶���ָ����ָ�ı��
strtok�����ҵ�str�е���һ����ǣ���������'\0'��β������һ��ָ�������ǵ�ָ��
����:cad@qq  -  ��һ���зֵ�ʱ�򣬰�@��Ϊ'\0'��Ȼ�󷵻�c�ĵ�ַ
strtok��ı䱸�������ַ�����������ʹ��strtok�����зֵ��ַ���һ�㶼����ʱ������
strtok�����ĵ�һ��������ΪNULL���������ҵ�str�е�һ�����strtok���������������ַ����е�λ��
strtok�����ĵ�һ������ΪNULL����������ͬһ���ַ����б������λ�ÿ�ʼ������һ�����
����:cad@qq@aq  -  ��һ������ʹ�ã��ڶ��δ���NULLָ�룬���qq@aq��ʼ�з�
����ַ����в����ڸ���ı�ǣ��򷵻�NULLָ��
*/



//������Ϣ����
//strerror
//char* strerror(int errnum);
/*
���������ͷ�ļ� string.h		errno.h	
������			������Ϣ
0				No error
1				Opreation not permitted
...
�˺����Ļ������þ��ǰѴ�����ת��Ϊ������Ϣ
ʹ�÷���: strerror(errno);
errno��һ��ȫ�ֵĴ��������
��C���ԵĿ⺯����ִ�й����з����˴��󣬾ͻ�Ѷ�Ӧ�Ĵ�����ŵ�errno��
*/



//�ַ����ຯ��
/*
����			������Ĳ����������������ͷ�����
iscntrl		-	�κο����ַ�
isspace		-	�հ��ַ����ո�' '����ҳ'\f',����'\n'���س�'\r',�Ʊ��'\t',��ֱ�Ʊ��'\v'
isdigit		-	ʮ�������� 0-9
isxdigit	-	ʮ���������֣�0-9,a-z,A-Z
islower		-	Сд��ĸa-z
isupper		-	��д��ĸA-Z
isalpha		-	�ǲ�����ĸa-z,A-Z
isalnum		-	��ĸ��������0-9,a-z,A-Z
ispunct		-	�����ţ��κβ��������������ĸ��ͼ���ַ�(�ɴ�ӡ)
isgraph		-	�κ�ͼ���ַ�
isprint		-	�κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�
*/
//�ַ�ת������
/*
tolower(char)	-	��дתСд
toupper(char)	-	Сдת��д
*/



//�ڴ��������
//memcpy - �ڴ濽������
//void* memcpy(void* destination, const void* source, size_t num);
/*
C���Ա�׼�涨��memcpyֻҪ�����ص����ڴ濽���Ϳ���
����memcpy��source��λ�ÿ�ʼ�����num���ֽڵ�destination���ڴ�λ��
�������������'\0'��ʱ�򲢲���ͣ����
���source��destination���κε��ص������ƵĽ������δ�����
memcpy(arr2,arr1,sizeof(arr1))
memcpy(arr+2,arr,20) -> ���δ���壬��Ϊ���ص���ԭ����ĳһλ����Ϊ�ı��Ϊ�µ�����
						�Ӻ���ǰ����Ҳ��������⣬Ҳ���ܴ��ڸ��ǵ�����
						�漰�ص���memmove		
*/
void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		//ָ����һ���ֽ�,��Ϊnum��������ֽ���
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}



//memmove - �ڴ��ƶ�
//void* memmove(void* dest,const void* src,size_t count)
/*
count���ֽڣ������ʱ��һ�����sizeof����ʹ����ȷ��������ٸ�Ԫ��
�����ڴ��ص��Ŀ���
�����ǰ���󸲸ǻ��ߴӺ���ǰ����
*/
void* my_memmove(void* dst, const void* src, size_t count)
{
	void * ret = dst;
	if (dst <= src || (char *)dst >= ((char *)src + count)) 
	{
		//��ַ�ռ���Դ��ַ֮ǰ���ߵ�ַ�ռ���Դ��ַ+count�ֽ�֮��
		//Դ�ռ�����ݴ�ǰ���󿽱�
		while (count--) 
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else 
	{
		//Դ�ռ�����ݴӺ���ǰ����
		dst = (char *)dst + count - 1;
		src = (char *)src + count - 1;
		while (count--) 
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	}
	return(ret);
}




//memcmp - �ڴ�Ƚ�
int memcmp(const void* ptr1, const void* ptr2, size_t count);
/*
�Ƚϴ�ptr1��ptr2ָ�뿪ʼ��num���ֽ�
���ַ����ȽϺ����ķ���ֵ����
*/
int my_memcmp(const void* ptr1, const void* ptr2, size_t count)
{
	assert(ptr1 && ptr2);
	if (!count)
		return 0;
	while (--count && *(char*)ptr1 == *(char*)ptr2)
	{
		ptr1 = (char*)ptr1 + 1;
		ptr2 = (char*)ptr2 + 1;
	}
	return (*((unsigned char *)ptr1) - *((unsigned char *)ptr2));
}



//memset - �ڴ�����
//void* memset(void* dest, int c, size_t count);
/*
c�������õ��ַ�
count����Ҫ���ö��ٸ��ַ�,��λ���ֽ�
*/
void* my_memset(void* dest, int c, size_t count)
{
	assert(dest);
	void* start = dest;
	while (count--)
	{
		*(char*)dest = (char)c;
		dest = (char*)dest + 1;
	}
	return start;
}



int main()
{
	//strtok
	char arr[] = "asdda@fakfajsfi.asf.ad";
	char* p = "@.";
	//����һ��arr����ʱ���������ı�
	char buf[1024] = { 0 };
	strcpy(buf, arr);
	//���շ��ص�ָ��
	char* ret = NULL;
	for (ret = strtok(arr, p); ret != NULL;ret = strtok(NULL,p))
	{
		printf("%\n", ret);
	}
	return 0;
}