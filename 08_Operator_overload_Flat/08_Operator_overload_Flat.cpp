#include <iostream>
using namespace std;

class Flat
{
private:
	int area;
	int price;
public:
	Flat() :area(0), price(0) {}
	Flat(int area, int price)
	{
		this->area = area;
		this->price = price;
	}
	void show()const
	{
		cout << ":::::::::::SHOW:::::::::::" << endl;
		cout << " Area: " << area << " m^2" << endl;
		cout << " Price: " << price << " $" << endl;
	}
	Flat operator = (const Flat& other)
	{
		this->area = other.area;
		this->price = other.price;
		return *this;
	}
	friend bool operator ==(const Flat& left, const Flat& right);
	friend bool operator >(const Flat& left, const Flat& right);
};

bool operator ==(const Flat& left, const Flat& right)
{
	return left.area == right.area;
}
bool operator >(const Flat& left, const Flat& right)
{
	return left.price > right.price;
}
void main()
{
	Flat f1(35, 30000);
	f1.show();
	Flat f2(45, 50000);
	f2.show();
	Flat f3 = f1;
	f3.show();
	cout << "____________________________________________" << endl;
	if (f1 == f2)
	{
		cout << " The area of the apartments is the same" << endl;
	}
	else
	{
		cout << " The area of the apartaments is the different" << endl;
	}
	if (f1 > f2)
	{
		cout << " The first apartment is more expensive" << endl;
	}
	else
	{
		cout << " The second apartment is more expensive" << endl;
	}
}