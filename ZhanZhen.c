#include<stdio.h>
#include<windows.h>

int fun(int x, int y)
{
	int c = 0xcccccccc;
	return c;
}
int main()
{
	int a = 0xaaaaaaaa;
	int b = 0xbbbbbbbb;
	int ret = fun(a, b);
	printf("You should runing here!\n");
	system("pause");
	return 0;
}
