#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
char* my_strstr(const char*str1, const char*str2)
{
	const char *s1 = str1;
	const char *s2 = str2;
	const char *cp = str1;
	assert(str1!= NULL);
	assert(str2!= NULL);
	if (*str2 == '\0')
		return (char *)str1;
	while(*cp)
	{
		s1 = cp;
		s2 = str2;
		while(*s1 && *s2  && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		  return cp;

        cp++;
	}
	return NULL;
}
int main()
{
	char *p1 = "abcdef";
	char *p2 = "abcdabcdefhihklmn";
	char *ret = my_strstr(p2,p1);
	printf("%s\n", ret);
	system("pause");
	return 0;
}
