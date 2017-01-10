# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
	int i = 0, k = 0, j = 0, m = 0;
	int count = 0;
	for (i = 0; i < 10; i++)
	for (k = 0; k < 10; k++)
	for (j = 0; j < 10; j++)
	{
		m = i * 100 + k * 10 + j;
		if (m == (i*i*i + k*k*k + j*j*j))
		{
			count++;
			printf("%d  ", m);
		}
	}
	printf("\nnumber=%d\n", count);
	system("pause");
	return 0;
 } 

