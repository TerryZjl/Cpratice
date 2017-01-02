#pragma warning (disable:4996)
#include<stdio.h>
#include<windows.h>
#include<string.h>

char *my_strncat(char *str1, const char *str2, size_t count)
{
	int len = strlen(str1);
	char *temp = str1 + len;
	while ((*temp++ = *str2++)&&(count--))
	{
		;
	}
	return str1;
}

int main()
{
	char string[80] = "This is the initial string!";
	char suffix[] = " extra text to add to the string...";

	printf("Before: %s\n", string);
	my_strncat(string, suffix, 18);
	printf("After:  %s\n", string);


	system("pause");
	return 0;
}