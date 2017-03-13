#include<iostream>
#include<string>

using namespace std;
#pragma warning (disable:4996)

class String
{
    friend ostream& operator<<(ostream& out, const String& s);
public:
	String(char *str = "")                       //默认参数是一个空字符串，是一个随机地址
		:_str(new char[(strlen(str)+1)])         //为str开辟一段空间，进行初始化
	{

		strcpy(_str, str);
		cout << "String(const char* s)" << endl;
	}

	////传统深拷贝
	//String(const String& s)
	//	:_str(new char[strlen(s._str) + 1])    //深拷贝构造函数
	//{
	//	strcpy(_str, s._str);
	//	cout << "String(const String& s)" << endl;
	//}

	//交换的方式拷贝构造
	String(const String& s)     
		:_str(NULL)              //若是 String str3; str3 = str1; 这种情况，交换赋值时需要调用拷贝构造，
	{                            //str3._str是创建好的一个空字符串，地址是一个随机的地址，不为NULL，
		String tmp(s._str);      // 交换内容后，下面析构tmp时就会调用delete，但是并没有动态开辟空间；所以需要在这里把_str置空
		std::swap(_str, tmp._str);
		cout<<"String(const String& s)"<<endl;
	}
	//传统赋值
	String& operator=(const String& s2)                   //想要str1 = str2，不能直接让str1指向str2那段空间，必须从新开辟一段，否则会在析构时出问题
	{
		delete[] _str;                                     //先把this指针指向的_str的空间释放了,再给_str开辟新的空间
		if (_str != s2._str)
		{
			_str = new char[strlen(s2._str) + 1];
			strcpy(_str, s2._str);
		}
		return *this;
	}
	//交换赋值方法
	/*String& operator=(String s2)     //这里调用拷贝构造函数开辟一段空间复制s2，然后交换s2和*this的字符串
	{
		std::swap(_str, s2._str);
		return *this;
	}*/

	//String& operator+=(char* s)
	//{
	//	int tmp = strlen(_str)+1;
	//	while (*s != NULL)
	//	{
	//		_str[tmp] = *s;
	//		s++;
	//		tmp++;
	//	}
	//	_str[tmp] = '\0';
	//	return *this;
	//}

	~String()
	{
		cout << "~String() " << endl;
		if (_str != NULL)
		{ 
			delete[] _str;
			_str = NULL;
		}
	}

	//void CheckCapacity(int count)
	//{
	//	if (_size + count >= _capacity)
	//	{
	//		int _count = (2 * _capacity)>(_capacity + count) ? (2 * _capacity) : (_capacity + count);
	//		char *tmp = new char[_count];
	//		strcpy(tmp, _pstr);
	//		delete[]_pstr;
	//		_pstr = tmp;
	//		_capacity = _count;
	//	}
	//}
private:
	char *_str;
	int _capacity;
	int _size;
};


ostream& operator<<(ostream& out, const String& s)
{
	out << s._str;
	return out;
}


int main()
{  
	String str1 = "pppppppp";
	String str2(str1);
	String str3;
	str3 = str1;
	cout << str1 << endl;
	cout << str2 << endl;
	str3 +="aaaaaaaa";
	cout << str3 << endl;

	return 0;
}



















