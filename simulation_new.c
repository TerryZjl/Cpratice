#include<iostream>
using namespace std;

class A
{
public:
	A(int a)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

int main()
{
	/*

	A* pa = (A*)operator new(sizeof(A));    
	new(pa)A(10);                 
	
	// delete
	pa->~A();                     
	operator delete(pa);         
	*/


	int sum = 10;
	A* pb = (A*)operator new(sizeof(A)* sum+4);  
	*(int*)pb = sum;                            
	                                            
	pb = (A*)((int *)pb + 1);                
	int i = 0;
	for (i = 0; i < *((int*)pb - 1); i++)       
	{
		new(pb+i)A(5);
	}
	// deletep[]
	int j = 0;
	for (j = 0; j < *((int*)pb-1); j++)  
	{
		pb[j].~A();
	}
	operator delete((int*)pb-1);   
	return 0;
}

