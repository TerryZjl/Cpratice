#include<stdio.h>
#include<string.h>
#include<windows.h>

int cmpere_int(const void *e1, const void *e2)
{
	int s1 = (int)e1;
	int s2 = (int)e2;
	return s1 > s2? 1 : s1 == s2 ? 0 : -1;
}

int main()
{
	int i = 0;
	int arr[] = { 1, 2, 56, 3, 879, 5, 23, 6, 22, 68 };
	int len = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, len, sizeof(int), cmpere_int);
	
	for (; i < len; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
