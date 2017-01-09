#include<stdio.h>
#include<windows.h>
#include<string.h>
int main()
{
	int m = 0, n = 0;
	char ch1[] = "welcome to xi'an!";
	char ch2[] = "#################";
	int i = 0;
	i = strlen(ch1);
	Sleep(1000);
	printf("%s\n", ch1);
	Sleep(50);
	system("cls");
	for (m = 0, n = (i - 1); n >= m; m++, n--)
	{
		ch2[m] = ch1[m];
		ch2[n] = ch1[n];
		Sleep(50);
		system("cls");       
		printf("%s\n", ch2);
	}
	system("pause");
	return 0;
}
