#include<iostream>
#include<string>

using namespace std;
#pragma warning (disable:4996)

class String
{
    friend ostream& operator<<(ostream& out, const String& s);
public:
	String(char *str = "")                      
		:_str(new char[(strlen(str)+1)])        
	{

		strcpy(_str, str);
		cout << "String(const char* s)" << endl;
	}

	////
	//String(const String& s)
	//	:_str(new char[strlen(s._str) + 1])   
	//{
	//	strcpy(_str, s._str);
	//	cout << "String(const String& s)" << endl;
	//}

	
	String(const String& s)     
		:_str(NULL)              
	{                        
		String tmp(s._str);      
		std::swap(_str, tmp._str);
		cout<<"String(const String& s)"<<endl;
	}

	String& operator=(const String& s2)            
	{
		delete[] _str;                                   
		if (_str != s2._str)
		{
			_str = new char[strlen(s2._str) + 1];
			strcpy(_str, s2._str);
		}
		return *this;
	}

	/*String& operator=(String s2)     
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



















