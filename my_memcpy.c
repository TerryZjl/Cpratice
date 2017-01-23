#pragma warning (disable:4996)
#include<stdio.h>
#include<windows.h>
#include<assert.h>

void *my_memcpy(void* dst, const void * src, size_t n)
{
	assert(dst);
	assert(src);

	char* _dst = (char*)dst;
	const char* _src = (const char*)src;
	while (n--)
		*_dst++ = *_src++;
	return dst;
}

int main()
{
	char *s = "hello world";
	char d[20];
	my_memcpy(d, s, strlen(s));
	d[strlen(s)] = '\0';
	printf("%s", d);
	system("pause");
	return 0;
}
