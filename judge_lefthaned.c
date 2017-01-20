#include<stdio.h>
#include<windows.h>

int lefthanded(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int num = strlen(s1);
	char *p = s1;
	char *temp1 = s1;
	char *temp2 = temp1;
	if (strcmp(s1, s2) == 0)
	{
		return 1;
	}
	for (i = num; i > 0; i--)
	{
		temp1 = p;
		temp2 = temp1;
		*temp1++ = *s1++;
		p = s1;
		for (j = num-1; j > 0; j--)
		{
			*s1 = *s1++;
		}
		*s1++ = *temp2++;
		*s1 = '\0';
		if (strcmp(p,s2) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char s1[] = "abcde";
	char s2[] = "bcdea";
	int num = 2;
	num = lefthanded(s1, s2);
	if (1 == num)
	{
		printf("T");
	}
	if (0 == num)
	{
		printf("F");
	}
	system("pause");
	return 0;
}
