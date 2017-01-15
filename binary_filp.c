#include<stdio.h>
#include<math.h>
#include<windows.h>

unsigned int  reverse_bit(unsigned int value)
{
	int j = 0;
	unsigned int num = 0;
	for (j = 31; j >= 0; value /= 2,j--)
	{
		num = num + ((value%2) * (pow(2, j)));
	}
	return num;
}

int main()
{
	int i = 0;
	int set = 0;
	scanf_s("%d", &i);
	set = reverse_bit(i);
	printf("%u", set);
	system("pause");
	return 0;
}
