#include<stdio.h>
#include<stdlib.h>
void adjust_arr(int arr[], int size)
{
	int temp; int i, j;
	/*����λ������ǰ��żλ�����ں�*/
	//if (size % 2 == 1)
	//{
	//  i = 1; j = size-1;
	//}
	//else
	//{
	//  i = 1; j = size - 2;
	//}
	//for (; i <= j; i += 2, j -= 2)
	//{
	//  temp = arr[i];
	//  arr[i] = arr[j];
	//  arr[j] = temp;
	//}

	/*����������ǰ��ż�����ں�*/
	for (i = 0, j = size - 1; i <j;)
	{
		if ((arr[i] % 2 == 0) && (arr[j] % 2 == 1))     //��������ں�ż����ǰ������е���
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		if (arr[i] % 2 == 1)   //���arr[i]Ϊ������i++
			i++;
		if (arr[j] % 2 == 0)   //���arr[j]Ϊż����j--
			j--;
	}
}

int main()
{
	int arr[] = { 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15, 16, 8, 9, 17, 18, 19, 20 };
	int i;
	int size = sizeof(arr) / sizeof(arr[0]);
	adjust_arr(arr, size);    //�������ã��������������
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
	return 0;
}
