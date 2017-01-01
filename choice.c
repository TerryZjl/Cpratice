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
		for (j = i + 1; j < num; j++) //找到i+1后面最小的一个数组下标，赋给k
		{
			if (arr[j] < arr[k])
			k = j;
		}
		temp = arr[i];     //把中间这个最小的这个数组和前面的a[i]交换
		arr[i] = arr[k];
		arr[k] = temp;
	}
}

int main()
{
	int a[10];
	int i = 0;
	printf("请输入十个数字\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}
	sort(a, 10);
	printf("从小到大的顺序依次是：\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}