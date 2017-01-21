#include<stdio.h>
#include<windows.h>
int main(int argc, char* argv[])
{
	int l = 0;	int s = 0;
	printf("%s\n",argv[0]);
	if(argv[1]=='-a')	
	{		
		l = atoi(argv[2]);		
		s = atoi(argv[3]);		
		printf("%d + %d = %d\n",l,s,l+s);	}	
	if(argv[1]=='-s')	
	{		
		l = atoi(argv[2]);		
		s = atoi(argv[3]);		
		printf("%d - %d = %d\n",l,s,l-s);	
	}	
	if(argv[1]=='-m')	
	{		
		l = atoi(argv[2]);		
		s = atoi(argv[3]);		
		printf("%d * %d = %d\n",l,s,l*s);	
	}	
	if(argv[1]=='-d')	
	{		
	    l = atoi(argv[2]);			
	    s = atoi(argv[3]);		
		printf("%d / %d = %d\n",l,s,l/s);	
	}	
	system("pause");	
	return 0;
}
