#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<windows.h>
#include<string.h>
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
