#include<stdio.h>
#include<windows.h>

int main()
{
	int a[10];
	int i = 0;
	int j = 0;
	int temp = 0;

	printf("请输入要排序的数字\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d",&a[i]);
	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	printf("从小到大顺序依次是:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}