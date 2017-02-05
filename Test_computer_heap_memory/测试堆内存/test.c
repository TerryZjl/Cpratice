#include<stdio.h>
#include<windows.h>

int main()
{
	char *ptr = NULL;
	int size = 100 * 1024 * 1024;
    ptr = malloc(size);
	
	while (1)
	{
		size += 100*1024*1024;
		ptr = realloc(ptr, size);
		if (ptr == NULL)
		{
			break;
		}
	}
	printf("size : %d\n", size);
	system("pause");
	return 0;
}