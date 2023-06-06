#include <iostream>
#include <vector>
#include<fstream>
#include<string>
using namespace std;
struct Time
{
	short h;
	short m;
	short s;

};
class Train
{
private:
	int number;
	Time departure_time;
	string destination;
public:
	Train() :number(0), departure_time({ 0, 0, 0 }), destination("none") {}
	Train(int number, Time time, string destination) :number(number), departure_time(time), destination(destination) {}
	void Show()const
	{
		cout << " Number: " << number << endl;
		cout << " Departure time: " << departure_time.h << " hours " << departure_time.m << " minutes " << departure_time.s << " seconds " << endl;
		cout << " Destination: " << destination << endl;
	}
	int Getnumber()
	{
		return number;
	}
	void Settime(Time time)
	{
		this->departure_time = time;
	}
	string Getdestination()
	{
		return destination;
	}
	Time Gettime()
	{
		return departure_time;
	}
	friend bool operator >(const Time& t1, const Time& t2);
	friend ostream& operator << (ostream& out, const Train& d);
};
bool operator >(const Time& t1, const Time& t2)
{
	if (t1.s + t1.m * 60 + t1.h * 60 * 60 > t2.s + t2.m * 60 + t2.h * 60 * 60)
	{
		return true;
	}
	else
	{
		return false;
	}
}
class Railway
{
private:
	vector<Train>trains;
public:
	void Add(Train train)
	{
		trains.push_back(train);
	}
	void Show()
	{
		cout << "__________SHOW__________" << endl;
		for (int i = 0; i < trains.size(); i++)
		{
			trains[i].Show();
			cout << endl;
		}
	}
	void Show(int numb)
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].Getnumber() == numb)
			{
				trains[i].Show();
				cout << endl;
			}
		}
	}
	void Edittime(int numb, Time time)
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].Getnumber() == numb)
			{
				trains[i].Settime(time);
			}
		}
	}
	void Sortbytime()
	{
		Train temp;
		for (int i = 0; i < trains.size(); i++)
		{
			for (int j = trains.size() - 1; j > i; j--)
			{
				if (trains[j - 1].Gettime() > trains[j].Gettime())
				{
					temp = trains[j - 1];
					trains[j - 1] = trains[j];
					trains[j] = temp;
				}
			}
		}
	}
	void Show(string destination)
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].Getdestination() == destination)
			{
				trains[i].Show();
				cout << endl;
			}
		}
	}
	void Save()
	{
		ofstream fileOut("vector.txt");
		for (int i = 0; i < trains.size(); i++)
		{
			fileOut << trains[i];
		}
		fileOut.close();
	}
	friend istream& operator >> (istream& in, Railway& train);
};
ostream& operator << (ostream& out, const Train& train)
{
	out << train.number << endl;
	out << train.departure_time.h << endl;
	out << train.departure_time.m << endl;
	out << train.departure_time.s << endl;
	out << train.destination << endl;
	return out;
}
istream& operator >> (istream& in, Railway& train)
{
	while (!in.eof())
	{
		int number = 0;
		Time time;
		string destination;
		in >> number;
		if (number == 0)break;
		in >> time.h;
		in >> time.m;
		in >> time.s;
		in >> destination;
		train.trains.push_back(Train(number, time, destination));
	}
	return in;
}

void main()
{
	Railway t;
	t.Add(Train(6, { 11,30,20 }, "Rivne"));
	t.Add(Train(6, { 13,00,00 }, "Rivne"));
	t.Add(Train(8, { 11,30,50 }, "Rivne"));
	t.Add(Train(4, { 12,10,10 }, "Rivne"));
	t.Show();
	t.Show(3);
	t.Edittime(2, { 13,20,20 });
	t.Show("Rivne");
	t.Show();
	t.Sortbytime();
	t.Show();
	t.Save();
	t.Show();
	Railway t0;
	ifstream fileIn("vector.txt");
	fileIn >> t0;
	fileIn.close();
	t0.Show();
}