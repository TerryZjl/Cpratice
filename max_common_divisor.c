#include<stdio.h>
#include<windows.h>
int main()
{
	int i = 0, a = 0, b = 0, j = 0;
	printf("please enter a and b\n");
 	scanf_s("%d,%d", &a, &b);
 	if (a > b)
	{
		i = b;
	}
	else
	{
		i = a;
	}
	for (j = i; j > 0; j--)
	{
		if (a%j==0&&b%j==0)
		{
			printf("The biggest common divisor is %d\n",j);
			break;
		}
	}

	system("pause");
	return 0;
}
