#include<stdio.h>
#include<windows.h>

int main()
{
	int i = 0,j = 0,k = 0;
	scanf_s("%d", &i);
	for (j = i; j > 10; j /= 10)
	{
		printf("%d ", j % 10);
	}
	printf("%d\n", j);
	system("pause");
	return 0;
}
