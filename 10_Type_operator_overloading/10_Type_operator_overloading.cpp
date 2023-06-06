#include <iostream>
using namespace std;

class Airplane
{
private:
	string model;
	string type;
	int passengers;
	const int maxpassengers = 30;
public:
	Airplane() :model(" "), type(" "), passengers(0), maxpassengers(30) {}
	Airplane(int maxpass) : model(" "), type(" "), passengers(0), maxpassengers(maxpass) {}
	void setairplane(string model, string type, int passengers)
	{
		this->model = model;
		this->type = type;
		this->passengers = passengers;
	}
	int getpassengers()const
	{
		return passengers;
	}
	Airplane operator++()
	{
		if (passengers < maxpassengers)
		{
			++this->passengers;
		}
		else
		{
			cout << " The number of passengers is maximum!";
		}
		return *this;
	}
	Airplane operator--()
	{
		if (passengers > 0)
		{
			--this->passengers;
		}
		else
		{
			cout << " The number of passengers is zero!";
		}
		return *this;
	}
	int operator() (int pluspass)
	{
		if (passengers + pluspass < maxpassengers)
		{
			this->passengers = passengers + pluspass;
		}
		else
		{
			cout << " The number of passengers will be greater than the maximum!" << endl;
		}
		return passengers;
	}
	void show()const
	{
		cout << "::::::::::::::::SHOW::::::::::::::::" << endl;
		cout << " Model: " << model << endl;
		cout << " Type: " << type << endl;
		cout << " Passengers: " << passengers << endl;
		cout << " Max passengers: " << maxpassengers << endl;
	}
	operator string()
	{
		return model;
	}
	friend bool operator ==(const Airplane& left, const Airplane& right);
	friend bool operator >(const Airplane& left, const Airplane& right);
	friend ostream& operator <<(ostream& out, const Airplane& airplane);
	friend istream& operator >>(istream& in, Airplane& airplane);
};
ostream& operator <<(ostream& out, const Airplane& airplane)
{
	out << "::::::::::::::::SHOW::::::::::::::::" << endl;
	out << " Model: " << airplane.model << endl;
	out << " Type: " << airplane.type << endl;
	out << " Passengers: " << airplane.passengers << endl;
	out << " Max passengers: " << airplane.maxpassengers << endl;
	return out;
}
istream& operator >>(istream& in, Airplane& airplane)
{
	cout << "***********************************" << endl;
	cout << " Enter model: ";
	in >> airplane.model;
	cout << " Enter type: ";
	in >> airplane.type;
	cout << " Enter passengers: ";
	in >> airplane.passengers;
	return in;
}

bool operator ==(const Airplane& left, const Airplane& right)
{
	return left.type == right.type;
}

bool operator >(const Airplane& left, const Airplane& right)
{
	return left.maxpassengers > right.maxpassengers;
}

void main()
{
	Airplane a1(15);
	a1.setairplane("A202", "destroyer", 10);
	a1.show();
	Airplane a2(15);
	a2.setairplane("B204", "scout", 12);
	a2.show();
	cout << "___________________________________" << endl;
	if (a1 == a2)
	{
		cout << " Type A1 and A2 are equal" << endl;
	}
	else
	{
		cout << " Type A1 and A2 are not equal" << endl;
	}
	++a1;
	cout << " ++A1 pass: " << a1.getpassengers() << endl;
	--a2;
	cout << " --A2 pass: " << a2.getpassengers() << endl;
	if (a1 > a2)
	{
		cout << " Max passengers A1 is bigger than A2 " << endl;
	}
	else
	{
		cout << " Max passengers A2 is bigger than A1 " << endl;
	}
	a1(5);
	cout << a1;
	cin >> a1;
	cout << a1;
	string mod;
	mod = (string)a2;
}