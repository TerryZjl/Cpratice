#include<stdio.h>
#include<windows.h>

int main()
{
	int num = 0, i = 0;
	printf("please enter 10 numbers\n");
	scanf_s("%d", &num);
	printf("\n");
	count_one_bits(num);
	system("pause");
	return 0;
}
int count_one_bits(unsigned int a)
{
	int  c = 0;
	while (a> 0)
	{
		if ((a & 1) == 1)
			++c;
		a >>= 1;
	}
	printf("%d\n",c);
	return c;
}
