#include<stdio.h>
#include<windows.h>

char *lefthanded(char *string,  int num)
{
	int i = 0;
	int j = 0;
	char *temp1 = string;
	char *temp2 = temp1;
	for (j = num; j > 0; j--)
	{
		*temp1++ = *string++;
	}
    char *p = string;
	for (i = strlen(string)-1; i > 0; i--)
	{
		*string = *string++;
	}
	for (j = num; j > 0; j--)
	{

		*string++ = *temp2++;
	}
	*string = '\0';
	return p;
}
int main()
{
	char str[] = "abcdefg";
	int num = 0;
	scanf_s("%d", &num);
	printf("%s\n",lefthanded(str, num));
	system("pause");
	return 0;
}
