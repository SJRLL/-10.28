#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j, k, n;
	for (n = 0; n < 999; n++)
	{
		i = n / 100;
		j = (n - i * 100) / 10;
		k = n - i * 100 - j * 10;
		if (n == i*i*i + j*j*j + k*k*k)
			printf("%d\n", n);
	}
	system("pause");
	return 0;
}
