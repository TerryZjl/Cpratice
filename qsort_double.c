#include<stdio.h>
#include<string.h>
#include<windows.h>

int cmpere_double(const void *e1, const void *e2)
{
	double a = *(double *)e1;
	double b = *(double *)e2;
	return a > b ? 1 : a == b ? 0 : -1;
}

int main()
{
	int i = 0;
	double a[] = { 1.23, 3.14, 54.1, 3.123, 6.25, 8.78 };
	int len = sizeof(a) / sizeof(a[0]);

	qsort(a, len, sizeof(double), cmpere_double);

	for (; i < len; i++)
	{
		printf("%lf ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

