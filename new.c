#include<iostream>
using namespace std;

class Array
{
public:
	Array(size_t size = 10)
		:_a(0)
		, _size(size)
	{
		cout << "Array()" << endl;
		if (_size > 0)
		{
			_a = new int[size];
		}
	}
	~Array()
	{
		cout << "~cout()" << endl;
		delete[] _a;
		_a = 0;
		_size = 0;
	}
private:
	int* _a;
	size_t _size;
};

int main()
{
	//Array* p1 = (Array*)malloc(sizeof(Array));
	//Array* p2 = new Array;
	//Array* p3 = new Array(20);
	Array* p4 = new Array;
/*	*((int*)p4 - 1) = 5; */     //��10�ĳ�5

	//free(p1);
	//delete p2;
	//delete p3;
	delete p4;

	//int* p1 = new int[10];   //new[]�ڸ��������Ϳ��ٿռ�ʱ�����ٵĿռ䲻���4���ֽ�
	//delete[] p1;             //��new[]�ڸ��Զ������Ϳ��ٿռ�ʱ�����һ����Ƿ����Զ�������������������������������Ż�࿪���ĸ��ֽ�
	                           //�����ж�����Ҫ���ö��ٴ��������������û���Զ��������������Ͳ�����
	return 0;
}
