# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<math.h>

int main()
{
	int i = 0, j = 0, num = 1, a = 0;
	for (i = 101; i <= 200; i+=2)
	{
		for (j = 2; j <=sqrt(i); j++)
		if (i%j == 0)
			num = 0;
		if (num)
		{
			printf("%d ", i);
			a++;
			if (a % 5 == 0)
				printf("\n");
		}
		num = 1;
	}
	printf("共有%d个素数", a);
	system("pause");
	return 0;
}
