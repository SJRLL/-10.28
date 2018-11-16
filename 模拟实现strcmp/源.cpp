#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int my_strcmp(const char*str1, const char*str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return  0;
		}
		str1++;
		str2++;
	}
	
	if (*str1 > *str2)
		return 1;
	else
		return -1;
}
int main()
{
	int ret = 0;
	ret = my_strcmp("abcdef", "abcdef");
	printf("%d", ret);
	system("pause");
	return 0;
}
