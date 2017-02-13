#include<stdio.h>
#include<string.h>
#include<windows.h>

void my_swap(char *buf1,char *buf2,int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		char temp = buf1[i];
		buf1[i] = buf2[i];
		buf2[i] = temp;
	}
}
void bubble_sort(void *base, int num, int width, int (*cmp)(const void *elem1, const void *elem2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if (cmp((char *)base+width*j,(char *)base+width*(j+1))>0)
			{
				my_swap((char*)base + width*j, (char*)base + width*(j + 1),width);
			}
		}
	}
}

typedef struct Stu{
	char name[20];
	int age;
	char sex[5];
}Stu;

int cmp_int(const void *elem1, const void *elem2)
{
	int a = *(int *)elem1;
	int b = *(int *)elem2;
	return a - b;

}

int cmp_struct(const void *elem1, const void *elem2)
{
	return (*(Stu*)elem1).age - (*(Stu *)elem2).age;
	/*return strcmp((*(Stu*)elem1).name,(*(Stu *)elem2).name);*/
}

int cmp_char(const void *elem1, const void *elem2)    //elem1和elem2存放的是元素的地址，元素是一个个指针
{                                                     //所以elem1和elem2存放的是一级指针的地址，即elem1和elem2是二级指针
	return strcmp(*(char **)elem1, *(char **)elem2);
}

int cmpere_double(const void *e1, const void *e2)
{
	double a = *(double *)e1;
	double b = *(double *)e2;
	return a > b ? 1 : a == b ? 0 : -1;
}

int main()
{
	int i = 0;

	//int arr[] = { 1, 2, 56, 3, 879, 5, 23, 6, 22, 68 };                            ////整形的排序                     
	//bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), &cmp_int);

	//for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");

	//Stu arr[] = { { "zhangsan", 24, "nan" }, { "lisi", 80, "nan" }, { "wangmazi", 32, "nv" } };  ////结构体的排序
	//bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), &cmp_struct);

	//for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	printf("%s ", arr[i].name);
	//}

	//char *arr[] = {"zzzz","bbbb","ddde","eeee", "aaaa"};                      ////字符型的排序
	//bubble_sort(arr, sizeof(arr) / sizeof(arr[0]), strlen(arr[0]), &cmp_char);

	//for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	//{
	//	printf("%s ", arr[i]);
	//}

	double a[] = { 1.23, 3.14, 54.1, 3.123, 6.25, 8.78 };               //浮点型的排序
	int len = sizeof(a) / sizeof(a[0]);

	bubble_sort(a, len, sizeof(double), cmpere_double);

	for (; i < len; i++)
	{
		printf("%lf ", a[i]);
	}
	printf("\n");
	printf("\n");
	system("pause");
	return 0;
}
