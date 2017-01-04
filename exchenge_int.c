#include<stdio.h>
#include<windows.h>

int main()
{
	int a = 1, b = 2;
	printf("%d %d\n", a,b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}
