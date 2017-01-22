#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

char firstSingle(char * str);

int main(void)
{
	char str[] = "abaccdeff";
	char tmp = firstSingle(str);
	printf("%c\n", tmp);

	return 0;
}

char firstSingle(char * str)
{
	int asc[255] = { 0 };
	int i;

	//遍历字符串，同时做字符的ASCII值映射到数组下标统计出现次数；
	for (i = 0; str[i] != '\0'; i++)
		asc[str[i]]++;

	//再次遍历，找到第一个出现一次的字符即为所求
	for (i = 0; str[i] != '\0'; i++)
	if (asc[str[i]] == 1)
		return str[i];
	system("pause");
	return 0;
}
