#include<stdio.h>
#include<stdio.h>

int main()
{
	int money = 0;
	printf("������Ǯ����");
	scanf_s("%d", &money);
	int bottle = money;
	int num = money;
	while (bottle>1)
	{

		num += bottle / 2;
		bottle -= bottle / 2;
	}
	printf("���Ժȣ�%dƿ\n", num);
	system("pause");
	return 0;
}