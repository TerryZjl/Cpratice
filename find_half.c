#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
	int ch[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
	int  i = 0;
	i = (sizeof(ch) / sizeof(ch[0]))-1;
	seek(ch,left,i);
	system("pause");
	return 0;
}
int seek(int a[],int left,int right)
{
	int k = 0;
	scanf_s("%d", &k);
	while (left <= right)
	{
		if (k == a[i / 2])
		{
			return i/2;
		}
		else if (k > a[i / 2])
			left = (i / 2) + 1;
		else
			right = (i / 2) - 1;
		i = (right + left);
	}
	if (left>right)
	{
		return -1;
	}
	return 0;
}
