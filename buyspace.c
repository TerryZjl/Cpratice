#include<iostream>
using namespace std;

void test()
{
	int *p1 = (int*)malloc(sizeof(int)*4);
	free(p1);

	int  *p2 = (int*)calloc(4, sizeof(int));
	int *p3 = (int *)realloc(p2, sizeof(int)* 6);

	free(p3);
}
int main()
{
	test();
	return 0;
}

