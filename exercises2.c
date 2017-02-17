#include<stdio.h>

void main()
{
	union
	{
		short k;
		char i[2];
	}*s, a;
	s = &a;
	s->i[0] = 0x39;
	s->i[1] = 0x38;
	int q = a.k;
	printf("%x\n", q);

	//int i = 0x12345678;
	//printf("%0x\n",i);
	system("pause");
}
