#include<stdio.h>
#include<windows.h>

int main()
{
	int a[10];
	int i = 0;
	int j = 0;
	int temp = 0;

	printf("������Ҫ���������\n");
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
	printf("��С����˳��������:\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}