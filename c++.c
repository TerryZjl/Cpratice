#include<windows.h>
struct bigdata
{
	int arr[1000];
};
void delebigdata1(bigdata& a)
{
	a.arr[0] = 0;
	a.arr[1] = 1;
	a.arr[2] = 2;
}
void delebigdata2(bigdata a)
{
	a.arr[0] = 0;
	a.arr[1] = 1;
	a.arr[2] = 2;
}

int main()
{
	bigdata d;
	int i = 0;
	int end = 0;
	int state = 0;
	state = GetTickCount();

	for (i = 0; i < 1000000; i++)
	{
		delebigdata1(d);
	}
	end = GetTickCount();
	cout << end-state << endl;

	state = GetTickCount();

	for (i = 0; i < 1000000; i++)
	{
		delebigdata2(d);
	}
	end = GetTickCount();
	cout << end - state << endl;
	system("pause");
	return 0;
}
