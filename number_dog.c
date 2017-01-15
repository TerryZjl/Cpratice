#include<stdio.h>
#include<windows.h>

int main()
{
	int i = 0;
	int arr[7] = { 1,3,5,8,1,3,5 };
	for (i = 1; i < 7; i++)
	{
		arr[0] = arr[0] ^ arr[i];
	}
	printf("%d", arr[0]);
	system("pause");
	return 0;
}
