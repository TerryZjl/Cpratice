#include"alloc.h"

int main()
{
	int *new_mem = NULL;

	new_mem = MALLOC(25, int);
	system("pause");
	return 0;
}