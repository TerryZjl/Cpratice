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

	//�����ַ�����ͬʱ���ַ���ASCIIֵӳ�䵽�����±�ͳ�Ƴ��ִ�����
	for (i = 0; str[i] != '\0'; i++)
		asc[str[i]]++;

	//�ٴα������ҵ���һ������һ�ε��ַ���Ϊ����
	for (i = 0; str[i] != '\0'; i++)
	if (asc[str[i]] == 1)
		return str[i];
	system("pause");
	return 0;
}
