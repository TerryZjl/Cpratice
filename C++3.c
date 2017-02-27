#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

class dog
{
private: 
	int _age;
	char _name[10];
public:
	void setdata(int age , char name[]="dog" )
	{
		_age = age;
		strcpy(_name, name);
	}
	void print()
	{
		cout <<"age: "<< _age << endl;
		cout << "name: " << _name << endl;
	}
};
int main()
{
	dog s;
	dog s1;
	s1.setdata(1);
	s.setdata(5, "wangcai");
	s1.print();
	s.print();
	system("pause");
	return 0;
}

class a
{
	int _i;
private:
	void fun()
	{
		cout << "fun()" << endl;
	}
public:
	void set(int i)
	{
		fun();
		_i = i;
	}
	void print()
	{
		cout << _i << endl;
	}
};

int main()
{
	a a;
	a *pa = &a;
	a.set(10);
	a.print();
	pa->set(20);
	pa->print();
	a.set(10);
	a.print();
	pa->print();
	system("pause");
	return 0;
}

class A
{
private:
	int _a = 1;
	int _b = 2;
	const int &_c = _b;
	double d1 = 6.9;
	const int &d2 = d1;
public:
	void print()
	{
		//cout << _c << endl;
		//cout << _b << endl;
		//_b = 3;
		//cout << _b << endl;
		cout << d1 << " " << d2 << endl;
	}

};

int main()
{
	A s;
	s.print();
	system("pause");
	return 0;
}
