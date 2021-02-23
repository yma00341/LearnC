#include <stdio.h>
#include <string.h>
#include <assert.h>

//strlen - 字符串长度
//size_t strlen(const char * str);
/*
字符串以'\0'作为结束标志，strlen函数返回的是在字符串中'\0'前面出现的字符个数不包括'\0'
参数指向的字符串必须要以'\0'结尾
注意函数的返回值是size_t，是无符号
模拟实现strlen
*/
int my_strlen(const char* str)
{
	int count = 0;
	assert(str);
	while (*str)	//等价于 *str != '\0'
	{
		count++;
		str++;
	}
	return count;
}



//长度不受限制的字符串函数
//strcpy - 字符串拷贝
//char* strcpy(char* destination, const char* source);
/*
Copies the C string pointed by source into the array pointed by destination,
including the terminating null charcter(and stopping at that point)
源字符串必须以'\0'结束
会将源字符串中的'\0'拷贝到目标空间
目标空间必须足够大，以确保能存放源字符串
目标空间必须可变
模拟实现strcpy
*/
char* my_strcpy(char * dest, const char * src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++)
	{
		//上述代码可以实现'\0'的拷贝
		//当 *dest = '\0'的时候，表达式的结果为\0即为假
		//循环自然停下
		;
	}
	//返回目的空间的起始地址
	return ret;
}



//strcat - 字符串追加
//char* strcat(char* destination, const char* source);
/*
源字符串必须以'\0'为结尾
从目的地的'\0'开始追加
目标空间必须足够大，能容纳下修改后的字符串的内容
目标空间必须可修改
字符串自己给自己追加，如何？ - 会崩溃

模拟实现
*/
char* my_strcat(char* dest, char* src)
{
	assert(dest && src);
	char* ret = dest;
	//1.找到目的字符串'\0'的位置
	while (*dest)
	{
		dest++;
	}
	//2.追加字符串
	while (*dest++ = *src++)
		;
	return ret;
}

//strcmp - 字符串比较大小关系
//int strcmp(const char& str1, const char* str2);
/*
比的对应字符串的ACSII码值的大小
对应位相等比较下一位
第一个字符串大于第二个字符串，则返回大于0的数组，不一定是1
第一个字符串等于第二个字符串，则返回0
第一个字符串小于第二个字符串，则返回小于0的数字，不一定是-1
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


//长度受限制的字符串函数
//strncpy
//char* strncpy(char* destination, const char* source, size_t count);
/*
count 的单位是要多倍多少字节
源数组不足的时候'\0'来补
*/
char* my_strncpy(char* dest,const char* source, size_t count)
{
	char* start = dest;
	//左值为真且右值为真时执行循环
	while (count && (*dest++ = *source++))
		count--;
	//当拷贝完，count依然不为0的时候
	if (count)
	{
		//剩余的追加'\0'
		while (--count)
			*dest++ = '\0';
	}
	//返回目标空间的地址
	return (start);
}



//strncat
//char* strncat(char* destination, const char* source, size_t count);
/*
从目标空间的'\0'开始追加，替换掉'\0'
追加指定数量的字符串后自动在追加的后面添加一个'\0'
如果追加的count 大于源字符串的长度，则超过的部分不管
*/
char* my_strncat(char* dest,const char* src,size_t count)
{
	assert(dest && src);
	char* start = dest;
	//1.找到目的字符串'\0'的位置
	while (*dest++)
		;
	//因为while多加了一次，所以要--
	*dest--;
	//2.追加字符串
	while (count--)
	{
		//拷贝字符串
		if (!(*dest++ = *src++))
			//拷贝遇到src 为'\0'的时候，!0为真，则返回地址
			return (start);
	}
	//
	*dest = '\0';
	return (start);
}


//strncmp
//int strncmp(const char* destination, const char* source, size_t count);
/*
比较到出现某个字符不一样或者一个字符串结束或者num个字符全部比较完
*/



//字符串查找
//strstr
//char* strstr(const char* str1, const char* str2);
/*
返回在str1中首次出现str2字符串的地址
否则返回空指针
*/
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* cp = (char*)str1;
	char *s1, *s2;
	if (!*str2)
		//如果str2是空字符串，即'\0'，则返回str1的地址
		return ((char*)str1);
	while (*cp)
	{
		s1 = cp;
		s2 = (char*)str2;
		while (*s1 && *s2 && !(*s1 - *s2))
			//当s1，s2都不为空，且s1和s2的ASCII码值相同，则!(*s1 - *s2)为真
			s1++, s2++;
		if (!*s2)
			//如果寻找完毕，s2直到'\0'都是匹配的，返回开始寻找时候的str1的地址
			return (cp);
		//没有匹配的，从前一次开始寻找的下一个字符重新匹配
		cp++;
	}
	//没找到匹配字符串返回空指针
	return (NULL);
}



//strtok
//char* strtok(char* str, const char* sep);
/*
sep参数是个字符串，定义了用作分隔符的字符集合
第一个参数指定一个字符串，包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记
strtok函数找到str中的下一个标记，并将其用'\0'结尾，返回一个指向这个标记的指针
例如:cad@qq  -  第一次切分的时候，把@变为'\0'，然后返回c的地址
strtok会改变备操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的
strtok函数的第一个参数不为NULL，函数将找到str中第一个标记strtok函数将保存它在字符串中的位置
strtok函数的第一个参数为NULL，函数将在同一个字符串中被保存的位置开始查找下一个标记
例如:cad@qq@aq  -  第一次正常使用，第二次传入NULL指针，会从qq@aq开始切分
如果字符串中不存在更多的标记，则返回NULL指针
*/



//错误信息报告
//strerror
//char* strerror(int errnum);
/*
必须包含的头文件 string.h		errno.h	
错误码			错误信息
0				No error
1				Opreation not permitted
...
此函数的基本作用就是把错误码转换为错误信息
使用方法: strerror(errno);
errno是一个全局的错误码变量
当C语言的库函数在执行过程中发生了错误，就会把对应的错误码放到errno中
*/



//字符分类函数
/*
函数			如果他的参数符合下列条件就返回真
iscntrl		-	任何控制字符
isspace		-	空白字符：空格' '，换页'\f',换行'\n'，回车'\r',制表符'\t',垂直制表符'\v'
isdigit		-	十进制数组 0-9
isxdigit	-	十六进制数字，0-9,a-z,A-Z
islower		-	小写字母a-z
isupper		-	大写字母A-Z
isalpha		-	是不是字母a-z,A-Z
isalnum		-	字母或者数组0-9,a-z,A-Z
ispunct		-	标点符号，任何不属于数组或者字母的图形字符(可打印)
isgraph		-	任何图形字符
isprint		-	任何可打印字符，包括图形字符和空白字符
*/
//字符转换函数
/*
tolower(char)	-	大写转小写
toupper(char)	-	小写转大写
*/



//内存操作函数
//memcpy - 内存拷贝函数
//void* memcpy(void* destination, const void* source, size_t num);
/*
C语言标准规定：memcpy只要处理不重叠的内存拷贝就可以
函数memcpy从source的位置开始向后复制num个字节到destination的内存位置
这个函数在遇到'\0'的时候并不会停下来
如果source和destination有任何的重叠，复制的结果都是未定义的
memcpy(arr2,arr1,sizeof(arr1))
memcpy(arr+2,arr,20) -> 结果未定义，因为有重叠，原本的某一位会因为改变变为新的数据
						从后往前拷贝也会出现问题，也可能存在覆盖的问题
						涉及重叠用memmove		
*/
void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		//指向下一个字节,因为num传入的是字节数
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}



//memmove - 内存移动
//void* memmove(void* dest,const void* src,size_t count)
/*
count是字节，传入的时候一般搭配sizeof函数使用来确定传入多少个元素
处理内存重叠的拷贝
分类从前往后覆盖或者从后往前覆盖
*/
void* my_memmove(void* dst, const void* src, size_t count)
{
	void * ret = dst;
	if (dst <= src || (char *)dst >= ((char *)src + count)) 
	{
		//地址空间在源地址之前或者地址空间在源地址+count字节之后
		//源空间的内容从前往后拷贝
		while (count--) 
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else 
	{
		//源空间的内容从后往前拷贝
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




//memcmp - 内存比较
int memcmp(const void* ptr1, const void* ptr2, size_t count);
/*
比较从ptr1和ptr2指针开始的num个字节
与字符串比较函数的返回值类似
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



//memset - 内存设置
//void* memset(void* dest, int c, size_t count);
/*
c代表设置的字符
count代表要设置多少个字符,单位是字节
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
	//创建一个arr的临时拷贝用来改变
	char buf[1024] = { 0 };
	strcpy(buf, arr);
	//接收返回的指针
	char* ret = NULL;
	for (ret = strtok(arr, p); ret != NULL;ret = strtok(NULL,p))
	{
		printf("%\n", ret);
	}
	return 0;
}