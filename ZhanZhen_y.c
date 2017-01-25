#include<stdio.h>
#include<windows.h>

int fun(int x, int y)
{
	printf("before£º\nx -> %d\ny -> %d\n", x, y);
	int c = 0xcccccccc;
	int *p = &x;
	p += 1;
	*p = 20;
	printf("after£º\nx -> %d\ny -> %d\n", x, y);

	return c;
}
int main()
{
	int a = 10;
	int b = 10;
	int ret = fun(a, b);
	printf("You should runing here!\n");
	system("pause");
	return 0;
}
