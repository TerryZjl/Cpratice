# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>

int main()
{
	char suspect;  //осри╥╦
	for (suspect = 'a'; suspect <= 'd'; suspect++)
	{
		if ((suspect != 'a') + (suspect == 'c') + (suspect == 'd') + (suspect != 'd') == 3)
		{
			printf("suspect is %c\n", suspect);
			break;
		}
	}
	system("pause");
	return 0;
}
