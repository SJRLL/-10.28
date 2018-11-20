#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void fun(unsigned int a)//无符号的整形数字！！！
{
	int b = 0;
	int count = 0;
	for (b = 0; b < 32; b++)
	{
		if (((a >> b) & 1) == 1)
		{
			count++;
		}
	}
	printf("数字 %d 二进制中含有 %d 个 1 \n", a, count);
}
int main()
{
	int unsigned a = 0;
	printf("请输入你要计算的数字:");
	scanf("%d", &a);
	fun(a);
	system("pause");
	return 0;
}

