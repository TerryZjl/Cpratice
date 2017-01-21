#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<assert.h>
#include<stdlib.h>

int my_printf(const char* val, ...)
{
	assert(val);

	va_list arg;
	int count = 0;
	va_start(arg, val);
	const char* str = val;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			switch(*str)
			{
			case 'f':
			{
						double fl = va_arg(arg, double);
						char arr1[20];
						_gcvt(fl, 10, arr1);
						fputs(arr1, stdout);
						count += strlen(arr1);
			}
			case 'd':
			{
						int num = va_arg(arg, int);
						char arr2[20];
						_itoa(num, arr2, 10);
						fputs(arr2, stdout);
						count += strlen(arr2);
			}
				break;
			case 'c':
			{
						char ch = va_arg(arg, char);
						putchar(ch);
						count++;
			}
				break;
			case 's':
			{
						char *pi = va_arg(arg, char*);
						fputs(pi, stdout);
						count += strlen(pi);
			}
				break;
			default:
				break;
			}
			str++;
		}
		putchar(*str);
		str++;
		count++;
	}
	va_end(arg); 
	return count;
}

int main(int argc, char* argv[])
{
	char a = 'z';
	char b[] = "hello";
	int c = 2147483647;
	float d = 1.2345678;
	my_printf("num = %d\n", my_printf("char = %c \nstring = %s\nint = %d\nfloat = %f\n", a, b, c, d));
	system("pause");
	return 0;
}
