#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void fun(unsigned int a)//�޷��ŵ��������֣�����
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
	printf("���� %d �������к��� %d �� 1 \n", a, count);
}
int main()
{
	int unsigned a = 0;
	printf("��������Ҫ���������:");
	scanf("%d", &a);
	fun(a);
	system("pause");
	return 0;
}

