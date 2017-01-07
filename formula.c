#include<stdio.h>
#include<stdio.h>
int main()
{
	double m = 0;
	int  n = 1;
	while (n <= 100)
	{
		if (n % 2 == 1)
			m += 1.0 / n;
		else
		    m -= 1.0 / n;
		n++;
	}
	printf("%lf", m);
	system("pause");
	return 0;
}
