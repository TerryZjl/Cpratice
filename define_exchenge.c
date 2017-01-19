# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

#define EXCHANGE(x) (((x>>1)&(((unsigned)(-1))/3))+((x<<1)&(2*(((unsigned)(-1))/3))))

int main()
{
    int i = 0;
	scanf("%d", &i);
	printf("%d\n",EXCHANGE(i));
	system("pause");
	return 0;
}
