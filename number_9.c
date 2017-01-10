#include<stdio.h>
#include<windows.h>

int main()
{
	int i = 0, k = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
		{
			k++;
			printf("%d ", i);
		}
		if (i / 10 == 9)
		{
			k++;
			printf("%d ", i);
		}
	}
	printf("\nnumber=%d\n", k);
	system("pause");
	return 0;
}
