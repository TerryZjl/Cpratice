#include <stdio.h>
#include<stdlib.h>
#define ROWS 3
#define COLS 3
#include<string.h>
int find_num(int arr[ROWS][COLS], int k, int cols, int rows)
{
	int row = 0;
	int col = cols - 1;
	while ((row<rows) && (col >= 0))
	{
		if (arr[row][col]>k)
			col--;
		else if (arr[row][col]<k)
			row++;
		else
			return 1;
	}
	return-1;
}
int main()
{
	int arr[ROWS][COLS] = { 1, 2, 3, 2, 3, 4, 4, 5, 6 };
	int ret = find_num(arr, 6, ROWS, COLS);//6在数组中，7不在//
	if (ret == 1)
		printf("ok\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
