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
/*	*((int*)p4 - 1) = 5; */     //把10改成5

	//free(p1);
	//delete p2;
	//delete p3;
	delete p4;

	//int* p1 = new int[10];   //new[]在给内置类型开辟空间时，开辟的空间不会多4个字节
	//delete[] p1;             //而new[]在给自定义类型开辟空间时，而且还看是否有自定义析构函数，如果定义了析构函数才会多开辟四个字节
	                           //用来判断这里要调用多少次析构函数；如果没有自定义析构函数，就不会了
	return 0;
}
