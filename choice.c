#include<stdio.h>
#include<windows.h>

void sort(int arr[], int num)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int temp = 0;

	for (i = 0; i < num - 1; i++)
	{
		k = i;
		for (j = i + 1; j < num; j++) //�ҵ�i+1������С��һ�������±꣬����k
		{
			if (arr[j] < arr[k])
			k = j;
		}
		temp = arr[i];     //���м������С����������ǰ���a[i]����
		arr[i] = arr[k];
		arr[k] = temp;
	}
}

int main()
{
	int a[10];
	int i = 0;
	printf("������ʮ������\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	sort(a, 10);
	printf("��С�����˳�������ǣ�\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}