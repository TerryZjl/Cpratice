#include<stdio.h>
#include<windows.h>

int main()
{
	int a[10], i = 0,b = 0;
	printf("please enter ten numbers\n"); 
	for (i = 0; i < 10; i++)
	{
		scanf_s ("%d",&a[i]);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		if (a[i]>b)
		{
			b = a[i];
		}
	}
	printf("%d\n", b);

	system("pause");

	return 0;
}
