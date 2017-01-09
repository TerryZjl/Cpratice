#include<stdio.h>
#include<windows.h>
#include<string.h>
int main()
{
	char ch[] = "123456";
	int i = 0;
	char ipt[10];
	printf("please enter the password:\n");
	for (i = 0; i < 3; i++)
	{
		gets(ipt,10);
		if (strcmp(ch, ipt) == 0)
		{
			printf("password is correct!\n");
			break;
		}
		else if (i <2)
			printf("password mistake£¬please intput again\n");
	}
	if (i == 3)
	{
		printf("password mistake\n");
		exit(1);
	}

	system("pause");
	return 0;
}
