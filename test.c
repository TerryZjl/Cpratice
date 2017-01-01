#include<stdio.h>
#include<stdio.h>

int main()
{
	int money = 0;
	printf("请输入钱数：");
	scanf_s("%d", &money);
	int bottle = money;
	int num = money;
	while (bottle>1)
	{

		num += bottle / 2;
		bottle -= bottle / 2;
	}
	printf("可以喝：%d瓶\n", num);
	system("pause");
	return 0;
}