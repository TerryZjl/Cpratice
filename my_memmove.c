#pragma warning (disable:4996)
#include<windows.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>

void *my_memmove(char *dest, const char *src, size_t count)
{
	assert(dest);
	assert(src);

	void *d = dest;
	if (dest < src && (char *)src < (char *)dest + count)
	{
		while (count--)
		{
			//Ë³Ðò
			*(char*)d = *(char*)src;
			d = (char*)d + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		d = (char*)d + count - 1;
		src = (char*)src + count - 1;
		// ÄæÐò
		while (count--)
		{
			*(char*)d = *(char*)src;
			d = (char*)d - 1;
			src = (char*)src - 1;
		}
	}
	return dest;
}

int main()
{
	char a[256] = "Do not spit grape skins while eating grapes";
	my_memmove(a + 1, a, strlen(a) + 1);
	printf("%s\n", a);
	system("pause");
	return 0;
}
