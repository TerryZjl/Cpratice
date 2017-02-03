#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int fun(int n, int k)
{
	if (k == 1)
	{
		return n;
	}
	return n*fun(n, k - 1);
}

int main()
{
	int num = 0;
	int n = 0;
	int k = 0;
	printf("please enter n and k \n");
	scanf("%d %d", &n, &k);
	num = fun(n, k);
	printf("n^k is %d\n", num);

	system("pause");
	return 0;
}
