#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

void Hanoi(int n, char A, char B, char C);
void Move(int n, char A, char B);
int count;
int main()
{
	int n;
	printf("请输入汉诺塔层数:\n");
	//2^n-1即为答案
	scanf("%d", &n);
	Hanoi(n, 'A', 'B', 'C');
	return 0;
}

void Hanoi(int n, char origin, char assist, char destination)
{
	if (n == 1)
	{
		Move(n, origin, destination);
	}
	else
	{
		Hanoi(n - 1, origin, destination, assist);
		Move(n, origin, destination);
		Hanoi(n - 1, assist, origin, destination);
	}
}

void Move(int n, char origin, char destination)
{
	count++;
	printf("第%d次移动 Move %d：Move from %c to %c !\n", count, n, origin, destination);
}