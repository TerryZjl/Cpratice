# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
int main()
{
	int a = 0, i = 0, sum = 0, k = 0;
	printf("please enter a number less than ten\na=");
	scanf("%d", &a);
	k = a;
	for (i = 0; i < 5; i++)
	{
		sum += k;
	    k =a + k*10;

	}
	printf("Sn=a+aa+aaa+aaaa+aaaaa=%d\n", sum);
	system("pause");
	return 0;
 } 
