#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<assert.h>

char* filp(char* p)
{
	assert(p);
	char temp = 0;
	int i = strlen(p);
	int count = 0;
	char *s1 = p;
	char *s2 = p + i - 1;
	for (; count < i/2; s1++, s2--, count++)
	{
		temp = *s1;
		*s1 = *s2;
		*s2 = temp;
	}
	return p;
}

int main()
{
	char str[] = "abcdefg";
	printf("%s\n",filp(str));
	system("pause");
	return 0;
}
