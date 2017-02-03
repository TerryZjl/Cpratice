#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

unsigned int DigitSum(unsigned int num)
{
	if (num <10)
	{
		return num;
	}
	return  DigitSum( num / 10) + num % 10;
}
int main()
{
	unsigned int a = 0;
	int ret = 0;

	printf("please enter a non-negative integer");
	scanf("%d", &a);

	ret = DigitSum(a);

	printf("%d\n", ret);
	system("pause");
	return 0;
}
