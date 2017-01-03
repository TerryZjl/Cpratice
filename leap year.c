#include<stdio.h>
int main()
{
	int year1=1000, year2=2000, a = 0;
	for (year1=1000; year1 <= year2; year1++)
	{
		if (year1 % 4 == 0 && year1 % 100 != 0 || year1 % 400 == 0)
		{
			printf("%d  ", year1);
			a++;
		}
		if (a % 10 == 0)
			printf("\n");
	}
	getchar();
	return 0;
}
