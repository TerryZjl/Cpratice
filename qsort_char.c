#include<stdio.h>
#include<string.h>
#include<windows.h>

int cmp_char(const void *e1, const void *e2)
{
	char **s1 = (char **)e1;
	char **s2 = (char **)e2;
	return strcmp(*s1,*s2);
}

int main()
{
	int i = 0;
	char *arr[] = {
		"ffff",
		"eeee",
		"cccc",
		"bbbb",
		"aaaa"
	};
	qsort(arr, 5, strlen(arr[0]), cmp_char);

	for (; i < 5; i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
