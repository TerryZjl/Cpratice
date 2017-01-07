#include<stdio.h>
#include<windows.h>
int main()
{
	int i = 0, n = 0, k = 0, a[32];
	printf("please enter a decimal number\n");
	scanf_s("%d", &n);
	while (n > 0)
	{
		a[i] = n % 2;
		n = n / 2;
		i++;
	}
	for ( ; i<32; i++)
	{
		a[i] = 0;
	}
	for (k = 31; k+1 > 0; k--)
	{
		printf("%d", a[k]);
	}
	printf("\nodd bits of binary output\n");
	for (k = 31; k+1 > 0; k-=2)
	{
		printf("%d", a[k]);
	}
	printf("\neven bits of binary output\n");
	for (k = 30; k+1 > 0; k-=2)
	{
		printf("%d", a[k]);
	}
	system("pause");
	return 0;
}
