# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<assert.h>

char *my_strcpy(char *str1, const char *str2)
{
	assert(str1);
	assert(str2);
	char *temp = str1;
	while (*temp++ = *str2++)
	{
		;
	}
	return str1;
}

int main()
{
	char a[20];
	my_strcpy(a, "hello world");
	printf("%s\n", a);
	system("pause");
	return 0;
}