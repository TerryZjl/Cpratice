#include<stdio.h>
#include<windows.h>
#include<time.h>

int feib(int sum)
{
	if (sum < 3)
	{
		return 1;
}
	return feib(sum - 1)+feib(sum - 2);
}
int main()
{
	int a = clock();
	int num = 0;
	scanf_s("%d", &num);
	printf("%d", feib(num));
	int b = clock();
	printf("%d\n", b - a);
	system("pause");
	return 0;
}
