#pragma warning (disable:4996)
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<assert.h>


char *my_strcat(char *str1, const char *str2)
{
    assert(str1);
	assert(str2);

	int len = strlen(str1);
	char *temp = str1 + len;
	while (*temp++ = *str2++)
	{
		;
	}
	return str1;
}

int main()
{
	char string[80];
	strcpy(string, "Hello world from ");
	my_strcat(string, "strcpy ");
	printf("String = %s\n", string);
	printf("String = %s\n", my_strcat(string, "and strcat!"));

	system("pause");
	return 0;
}
