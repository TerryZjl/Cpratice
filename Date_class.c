#include<iostream>
using namespace std;
#include<assert.h>

class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 1996, int month = 2, int day = 29)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		assert(TestDate());
	}
	bool TestDate()
	{
		if (_year > 0 && _month > 0 && _month<13 && _day>0 && _day <= GetMonthDay(_year, _month))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int GetMonthDay(int year, int month)
	{
		int Monthbuf[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (year > 0)
		{
			if (month != 2)
			{
				return Monthbuf[month];
			}
			else
			{
				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
				{
					return 29;
				}
				else
				{
					return Monthbuf[month];
				}
			}
		}
	}


	Date operator+(int day)
	{
		if (day < 0)
		{
			return *this - (-day);
		}
		Date tmp = *this;
		tmp._day += day;
		while (tmp.TestDate() == false)
		{
			tmp._day -= tmp.GetMonthDay(tmp._year, tmp._month);    
			if (tmp._month == 12)
			{
				tmp._year++;
				tmp._month = 1;
			}
			else
			{
				tmp._month++;
			}
		}
		return tmp;
	}
	inline Date& operator+=(int day)
	{
		return  *this = *this + day;
	}

	inline Date& operator-=(int day)
	{
		return  *this = *this - day;
	}

    Date& operator++()
	{
		*this+=1;
		return *this;
	}
	Date operator++(int)  //后置
	{
		Date tmp(*this);
		*this+=1;
		return tmp;
	}
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	Date operator--(int)  //后置
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	bool operator>(const Date& d)
	{
		if ((_year > d._year) || ((_year == d._year&&_month > d._month) || (_month == d._month&&_day > d._day)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(const Date& d)
	{
		if (*this > d&&*this == d)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<(const Date& d)
	{
		if (*this > d&&*this == d)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool operator<=(const Date& d)
	{
		if (*this > d)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool operator==(const Date& d)
	{
		if (_year == d._year&&_year == d._year&&_day == d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}



	Date operator-(int day)
	{
		if (day < 0)
		{
			return *this + (-day);
		}
		Date tmp(*this);

		tmp._day -= day;
		while (tmp.TestDate() == false)
		{
			if (tmp._month == 1)
			{
				tmp._year--;
				tmp._month = 12;
			}
			else
			{
				tmp._month--;
			}
			day = tmp.GetMonthDay(tmp._year, tmp._month);   //向高位的月结位
			tmp._day += day;                                //直到借得合法了位置
		}
		return tmp;
	}

	int operator-(const Date &d)
	{
		Date tmp = d;
		int YearDay = 0;              
		int Day = this->_day - d._day;    
		int MonthDay = 0;
		while (this->_month != tmp._month)    //都向被减数靠
		{
			if (this->_month > tmp._month)  
			{
				MonthDay += GetMonthDay(tmp._year, tmp._month);    
				tmp._month++;
			}
			else
			{
				tmp._month--;
				MonthDay -= GetMonthDay(tmp._year, tmp._month);
			}
		}
	    while (this->_year != tmp._year)    
		{
		   if (_year > tmp._year)
		   {
			   if ((tmp._year % 4 == 0 && tmp._year % 100 != 0) || tmp._year % 400 == 0)
			   {
				   YearDay += 366;
			   }
			   else
			   {
				   YearDay += 365;
			   }
			   tmp._year++;
		   }
		   else
		   {
			   tmp._year--;
			   if ((tmp._year % 4 == 0 && tmp._year % 100 != 0) || tmp._year % 400 == 0)
			   {
				   YearDay -= 366;
			   }
			   else
			   {
				   YearDay -= 365;
			   }
		   }
		}
		return -(YearDay + Day + MonthDay);
	}

	void Display()
	{
		assert(TestDate());
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
	}
};

int main()
{
	Date d1(2017, 2, 28);
	Date d2(1896, 6, 22);//  2   28    365  -28     3
	//bool = tmp;
	//tmp = d2 > d1;
	//cout << tmp << endl;
	/*d1 += 1000;
	d1.Display();
	Date d3;
	d1 -= 1000;*/
	/*d2 = d1++;
	d1.Display();*/
	int d3 = d1-d2;
	cout << d3 << endl;

	return 0;
}




















