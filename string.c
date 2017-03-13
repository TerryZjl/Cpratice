#include<iostream>
#include<string>

using namespace std;
#pragma warning (disable:4996)

class String
{
    friend ostream& operator<<(ostream& out, const String& s);
public:
	String(char *str = "")                       //Ĭ�ϲ�����һ�����ַ�������һ�������ַ
		:_str(new char[(strlen(str)+1)])         //Ϊstr����һ�οռ䣬���г�ʼ��
	{

		strcpy(_str, str);
		cout << "String(const char* s)" << endl;
	}

	////��ͳ���
	//String(const String& s)
	//	:_str(new char[strlen(s._str) + 1])    //������캯��
	//{
	//	strcpy(_str, s._str);
	//	cout << "String(const String& s)" << endl;
	//}

	//�����ķ�ʽ��������
	String(const String& s)     
		:_str(NULL)              //���� String str3; str3 = str1; ���������������ֵʱ��Ҫ���ÿ������죬
	{                            //str3._str�Ǵ����õ�һ�����ַ�������ַ��һ������ĵ�ַ����ΪNULL��
		String tmp(s._str);      // �������ݺ���������tmpʱ�ͻ����delete�����ǲ�û�ж�̬���ٿռ䣻������Ҫ�������_str�ÿ�
		std::swap(_str, tmp._str);
		cout<<"String(const String& s)"<<endl;
	}
	//��ͳ��ֵ
	String& operator=(const String& s2)                   //��Ҫstr1 = str2������ֱ����str1ָ��str2�Ƕοռ䣬������¿���һ�Σ������������ʱ������
	{
		delete[] _str;                                     //�Ȱ�thisָ��ָ���_str�Ŀռ��ͷ���,�ٸ�_str�����µĿռ�
		if (_str != s2._str)
		{
			_str = new char[strlen(s2._str) + 1];
			strcpy(_str, s2._str);
		}
		return *this;
	}
	//������ֵ����
	/*String& operator=(String s2)     //������ÿ������캯������һ�οռ临��s2��Ȼ�󽻻�s2��*this���ַ���
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



















