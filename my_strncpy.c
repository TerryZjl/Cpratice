#pragma warning (disable:4996)
#include<stdio.h>
#include<windows.h>
#include<assert.h>

char *my_strncpy(char *st1, const char *st2, int num)
{
	assert(st1);
	assert(st2);
	int i = 0;
	char *temp = st1;
	for (i = 0; i < num; i++)
	{
		*temp++ = *st2++;
	}
	return st1;
}

int main()
{
	char str1[] = {"abcdefghij"};
	char str2[] = {"1234567"};
	my_strncpy(str1, str2, 4);
	printf("%s\n",str1);
	printf("%s\n", my_strncpy(str1, str2, 7));
	system("pause");
	return 0;
}