#pragma warning (disable:4996)
#include<stdio.h>
#include<windows.h>
//#include<string.h>

int my_strcmp(const char *str1, const char *str2)
{
	while (*str1&&*str2&&(*str1==*str2))
	{
			str1++;
			str2++;
	}
	return *str1 - *str2;
}

int my__stricmp(char *str1,char *str2)
{
	while (*str1&&*str2 )
	{
		if (*str1>= 'A'&&*str1 <= 'Z')
			*str1= *str1 + 'a' - 'A';
		if (*str2 >= 'A'&&*str2 <= 'Z')
			*str2 = *str2 + 'a' - 'A';
		if (*str1 != *str2)
		{
			break;
		}
			str1++;
			str2++;
	}
	return *str1 - *str2;
}

int main()
{
	char string1[] = "The quick brown dog jumps over the lazy fox";
	char string2[] = "The QUICK brown dog jumps over the lazy fox";

	char tmp[20];
	int result;

	/* 区分字符大小写 */
	printf("Compare strings:\n\t%s\n\t%s\n\n", string1, string2);
	result = my_strcmp(string1, string2);
	if (result > 0)
		strcpy(tmp, ">");
	else if (result < 0)
		strcpy(tmp, "<");
	else
		strcpy(tmp, "==");
	printf("\tstrcmp:   String 1  %s string 2\n", tmp);

	/* 不区分字符大小写( my_stricmp) */
	result = my__stricmp(string1, string2);
	if (result > 0)
		strcpy(tmp, ">");
	else if (result < 0)
		strcpy(tmp, "<");
	else
		strcpy(tmp, "==");
	printf("\t_stricmp:  String 1  %s string 2\n", tmp);


	system("pause");
	return 0;
}
