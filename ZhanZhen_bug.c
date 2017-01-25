#include<stdio.h>
#include<windows.h>

void *add = NULL;

void bug()
{
	int d = 0;
	int *p = &d;
	p += 4;
	*p =(int *)add; 
	printf("bug function\n");
}

int fun(int x, int y)
{
	int c = 0xffffffff;
	int *p = &x;
	p -= 1;
	add = *p;     
	*p = &bug;    
	printf("fun function\n");
	return c;
}
int main()
{
	int a = 0xaaaaaaaa;
	int b = 0xbbbbbbbb;
	int ret = fun(a, b);
	printf("You should runing here!\n");
	_asm{        
		sub esp,4         
	} 
	system("pause");   
	return 0;
}
