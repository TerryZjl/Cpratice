#include<stdio.h>
#include<math.h>
#include<windows.h>
int main()
{
	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, exp = 0;
	printf("please enter a b c\n");
	scanf_s("%lf%lf%lf", &a, &b, &c);
	exp = b * b - 4 * a * c;
	if (fabs(a) <= 1e-6)
	{
		printf("Not a yuan quandratic equation\n");
	}
	else
	{
		if (fabs(exp) > 1e-6)
		{
	printf("x1 = %lf x2 = %lf\n", (-b + sqrt(exp)) / (2 * a), (-b - sqrt(exp)) / (2 * a));
		}
		else
			if (fabs(exp) <= 1e-6)
			{
				printf("x1 = x2 = %lf\n", -b / (2 * a));
			}
			else
			{
				printf("are two conjugate complex\n");
			}
	}
	system("pause");
	return 0;
}
