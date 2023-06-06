#include <iostream>
using namespace std;

class Date
{
private:
	int days;
	int months;
	int years;
	int alldays;
public:
	Date() :days(0), months(0), years(0) {}
	Date(int days, int months, int years)
	{
		this->days = days;
		this->months = months;
		this->years = years;
		datetodays();
	}
	void show()const
	{
		cout << "::::::::::SCHOW::::::::::" << endl;
		cout << days << "." << months << "." << years << endl;
	}
	void adddays()
	{
		datetodays();
		this->alldays = alldays + 1;
		daystodate();
	}
	void datetodays()
	{
		this->alldays = years * 360 + months * 30 + days;
	}
	void daystodate()
	{
		this->years = alldays / 360;
		this->months = (alldays - years * 360) / 30;
		this->days = alldays - years * 360 - months * 30;

	}
	Date operator++()
	{
		datetodays();
		++this->alldays;
		daystodate();
		return *this;
	}
	Date operator--()
	{
		datetodays();
		--this->alldays;
		daystodate();
		return *this;
	}
	Date operator++(int)
	{
		datetodays();
		this->alldays++;
		daystodate();
		return *this;
	}
	Date operator--(int)
	{
		datetodays();
		this->alldays--;
		daystodate();
		return *this;
	}
	Date operator+=(int numb)
	{
		datetodays();
		this->alldays += numb;
		daystodate();
		return *this;
	}
	Date operator-=(int numb)
	{
		datetodays();
		this->alldays -= numb;
		daystodate();
		return *this;
	}
	Date operator() (int days)
	{
		datetodays();
		this->alldays = alldays + days;
		daystodate();
		return *this;
	}
	Date operator() (int days, int months)
	{
		int sum = months * 30 + days;
		datetodays();
		this->alldays = alldays + sum;
		daystodate();
		return *this;
	}
	Date operator() (int days, int months, int years)
	{
		int sum = years * 360 + months * 30 + days;
		datetodays();
		this->alldays = alldays + sum;
		daystodate();
		return *this;
	}

	friend bool operator !=(const Date& left, const Date& right);
	friend bool operator ==(const Date& left, const Date& right);
	friend bool operator >(const Date& left, const Date& right);
	friend bool operator <(const Date& left, const Date& right);
};
bool operator !=(const Date& left, const Date& right)
{
	return !(left.alldays == right.alldays);
}
bool operator ==(const Date& left, const Date& right)
{
	return left.alldays == right.alldays;
}

bool operator >(const Date& left, const Date& right)
{
	return left.alldays > right.alldays;
}

bool operator <(const Date& left, const Date& right)
{
	return left.alldays < right.alldays;
}
void main()
{
	Date d1(10, 7, 2003);
	d1.show();
	d1.adddays();
	d1.show();
	++d1;
	d1++;
	d1.show();
	--d1;
	d1--;
	d1.show();
	d1 += 5;
	d1.show();
	d1 -= 6;
	d1.show();
	d1(7);
	d1.show();
	d1(10, 2);
	d1.show();
	d1(5, 1, 2);
	d1.show();
	Date d2(10, 7, 2003);
	if (d1 != d2)
	{
		cout << " The dates are not the same" << endl;
	}
	else
	{
		cout << " The dates are the same" << endl;
	}
	if (d1 == d2)
	{
		cout << " The dates are the same" << endl;
	}
	else
	{
		cout << " The dates are not the same" << endl;
	}
	if (d1 > d2)
	{
		cout << " The first date is bigger" << endl;
	}
	else
	{
		cout << " The second date is bigger" << endl;
	}
	if (d1 < d2)
	{
		cout << " The first date is smaller" << endl;
	}
	else
	{
		cout << " The second date is smaller" << endl;
	}
}