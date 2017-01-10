
# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

int main()
{
	int i = 0, j = 0;
	int n = 0;
	printf("«Î ‰»Î–– ˝\n");
	scanf("%d", &n);
	for (i = 1; i <= n/2+1; i++)
	{
		for (j = 1; j <= n/2+1 - i; j++)
			printf(" ");
		for (j = 1; j <= 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
	for (i = n/2; i >= 1; i--)
	{
		for (j = 1; j <= n/2+1 - i; j++)
			printf(" ");
		for (j = 1; j <= 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
	system("pause");
	return 0;	
} 
	 
