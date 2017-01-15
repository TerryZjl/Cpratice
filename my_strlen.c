#include<stdio.h>
#include<windows.h>
#include<assert.h>

int my_strlen(char *p)
{
	int i = 0;
	assert(p!= NULL);//╤оят
	while (*p++)
	{
		i++;
	}
	return i;
}

int main()
{
	char str1[] = { "abcdef" };
	printf("%d\n", my_strlen(str1));
	system("pause");
	return 0;
}
