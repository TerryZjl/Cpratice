#include<stdio.h>
#include<windows.h>
int main()
{
	int i = 0;
	int j = 0;
	int a = 0;
	int count = 0;
	scanf_s("%d%d", &i, &j);
	a = i^j;
	while(a>0)
	{
		if ((a& 1) == 1)
		{
			count++;
		}
		a >>=1;
	}
	printf("%d",count);
	system("pause");
	return 0;
}
