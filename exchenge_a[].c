#include<stdio.h>
#include<windows.h>
int main()
{
	int a[10], b[10];
	int i, j, k;
	printf("«Î ‰»Îa[i]=");
	for (i = 0; i < 10; i++)
		scanf_s("%d", &a[i]);
	printf("\n");
	printf("«Î ‰»Îb[i]=");
	for (j = 0; j < 10; j++)
		scanf_s("%d", &b[j]);
	printf("\n");
	for (k = 0; k < 10; k++)
    {
        a[k] ^= b[k];
	    b[k] ^= a[k];
	    a[k] ^= b[k];
    }
	printf("a[i]=");
	for (i = 0; i <sizeof(a)/sizeof(a[0]); i++)
		printf("%d ",a[i]);
	printf("\nb[j]=");
	for (j = 0; j < sizeof(a) / sizeof(a[0]); j++)
		printf("%d ",b[j]);
	printf("\n");
	system("pause");
	return 0;
}
