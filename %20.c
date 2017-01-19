#include<stdio.h>
#include<windows.h>
#include<assert.h>

char* replace(char *p)
{
	assert(p);
	char *start = p;
	int len = 0;
	int spaceNums = 0;
	while (*start != '\0')
	{
		len++;
		start++;
		if (*start == ' ')
		{
			spaceNums++;
		}
	}
	int Numlen =len + 2 * spaceNums+1;
	char *end = p + len;
	char *numend = p + Numlen-1;
	while (end >=p)
	{
		if (*end == ' ')
		{
			*numend-- = '0';
			*numend-- = '2';
			*numend-- = '%';
			end--;
			continue;
		}
		*numend-- = *end--;
	}
	return p;
}

int main()
{
	char str[] = "we are happy.";
	printf("%s\n",replace(str));
	system("pause");
	return 0;
}
