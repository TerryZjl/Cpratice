#include<stdio.h>
#include<windows.h>
#include<string.h>

char *Strstr(const char *string,const char *s1)
{
	int i = strlen(string);
	int j = strlen(s1);
	for (i = strlen(string); i > 0; i--)
	{
		for (j = strlen(s1); j > 0; j--)
		{
			if (*string == *s1)
			{
				string++;
				s1++;
			}
			else
			{
				break;
			}
		}
		if (0 ==j)
		{
			return string;
		}
	}
	return NULL;
}

int main()
{
	char str1[] = "cabcdefg";
	char str2 []= "cd";
	printf("%d\n", strstr(str1, str2)-str1+1);
	system("pause");
	return 0;
}
