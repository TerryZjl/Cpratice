#include<stdio.h>
#include<windows.h>
void flie(char *p)
{
	int i = 0;
	char arr[256];
	char *pi = arr;
	while (*p++)
	{
		i++;
	}
	*p--;
	while (i--)
	{
		*pi++ = *--p;
	}
	*pi = '\0';
	printf("%s\n", arr);
}
int main()
{
	char str[] = "tneduts a ma i";
    flie(str);
	system("pause");
	return 0;
}
