#include"alloc.h"
#undef malloc


void *alloc(size_t size)
{
	void *new_mem = NULL;
	new_mem = malloc(size);
	if (new_mem != NULL)
	{
		perror("malloc :");
		system("pause");
		exit(1);
	}

	return new_mem;
}