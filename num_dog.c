#include <stdio.h>
#include <stdlib.h>

void find(int a[], int sz)
{
	int i = 0;
	int num1 = 0;
	int num2 = 0;
	int num = 0;
	int flag = 0;
	for (i = 0; i < sz; i++)
	{
		num = num^a[i];
	}
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) != 1)//找异或之后这个数字二进制数中最先出现的1的位置
		{
			flag++;
		}
		else
			break;

	}
	for (i = 0; i < sz; i++)
	{
		if (((a[i] >> flag) & 1) == 1)//分成2组
			num1 ^= a[i];
		else
			num2 ^= a[i];
	}
	printf("%d %d\n", num1, num2);
}

int main()
{
	int a[] = { 1, 2, 2, 3 };
	int sz = sizeof(a) / sizeof(a[0]);
	find(a, sz);
	system("pause");
	return 0;
}

