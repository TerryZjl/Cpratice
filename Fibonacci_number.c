#include<stdio.h>
#include<windows.h>
#include<time.h>

int main()
{
	int a = clock();
	int sum = 0;
	int i = 1;
	int j = 1;
	int num = 0;
	scanf_s("%d", &num);
	if (num == 1 )
	{
		printf("1");
	}
	while(i < num)
	{
		sum = j + i;
		i = j;
		j = sum;
	}
	printf("%d\n", sum);
	int b = clock();
	printf("%d\n", b - a);
	system("pause");
	return 0;
}
