#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("***************************\n");
	printf("*******    1.play    ******\n");
	printf("*******    0.exit    ******\n");
	printf("***************************\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("please select>:");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			{
				int num = rand()%100+1;
				int guess = 0;
				while(1)
				{
					printf("please guess the number:>");
					scanf("%d", &guess);
					if(guess > num)
					{
						printf("big\n");
					}
					else if(guess < num)
					{
						printf("small\n");
					}
					else
					{
						printf("congratulations£¡£¡£¡\n");
						break;
					}
				}
			}
			break;
		case 0:
			break;
		default:
			printf("The wrong choice\n");
			break;
		}
	} while (input);
	return 0;
}
