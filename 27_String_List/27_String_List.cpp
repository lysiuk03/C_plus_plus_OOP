#include <iostream>
#include<Windows.h>
#include<string>
#include <list>
#include<fstream>
using namespace std;
struct Date
{
	short day;
	short month;
	short year;
};
class Application
{
private:
	string destination;
	int number;
	string name;
	string surname;
	Date date;
public:
	Application() :destination("none"), number(0), name("none"), surname("none"), date({ 0,0,0 }) {}
	Application(string destination, int number, string name, string surname, Date date) :destination(destination), number(number), name(name), surname(surname), date(date) {}
	void Print()const
	{
		cout << " Destination: " << destination << endl;
		cout << " Number: " << number << endl;
		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Date: " << date.day << "." << date.month << "." << date.year << endl;
	}

	string Getdestination()const
	{
		return destination;
	}
	int Getnumber()const
	{
		return number;
	}
	string Getname()const
	{
		return name;
	}
	string Getsurname()const
	{
		return surname;
	}
	Date Getdate()const
	{
		return date;
	}

	friend bool Comparatorbydestination(const Application& app1, const Application& app2);
	friend bool Comparatorbydate(const Application& app1, const Application& app2);
};
bool Comparatorbydestination(const Application& app1, const Application& app2)
{
	return app1.destination < app2.destination;
}
bool Comparatorbydate(const Application& app1, const Application& app2)
{
	if (app1.date.year != app2.date.year)
	{
		return app1.date.year > app2.date.year;
	}
	else if (app1.date.month != app2.date.month)
	{
		return app1.date.month > app2.date.month;
	}
	else if (app1.date.day != app2.date.day)
	{
		app1.date.day > app2.date.day;
	}
	else
	{
		return app1.destination < app2.destination;
	}
}
bool operator ==(const Date& d1, const Date& d2)
{
	if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day)
	{
		return true;
	}
	else
	{
		return false;
	}
}
class Airport
{
private:
	list<Application> app;
public:
	void Addapp(string destination, int number, string name, string surname, Date date)
	{
		app.push_back(Application(destination, number, name, surname, date));
	}
	void Delete(int number)
	{
		int ia = 0;
		for (auto i : app)
		{
			ia++;
			if (i.Getnumber() == number)
			{
				int ii = 0;
				while (ii != ia - 1)
				{
					app.splice(app.end(), app, app.begin());
					ii++;
				}
			}
		}
		app.erase(app.begin());
	}
	void Sortbydestination()
	{
		app.sort(Comparatorbydestination);
	}
	void Sortbydate()
	{
		app.sort(Comparatorbydate);
	}
	void Print(int number)
	{
		for (auto i = app.begin(); i != app.end(); i++)
		{
			if (number == i->Getnumber())
			{
				i->Print();
			}
		}
	}
	void Print(Date date)
	{
		for (auto i = app.begin(); i != app.end(); i++)
		{
			if (date == i->Getdate())
			{
				i->Print();
			}
		}
	}
	void Show()
	{
		cout << "_________SHOW__________" << endl;
		for (auto i = app.begin(); i != app.end(); i++)
		{
			i->Print();
		}
	}

	friend ostream& operator << (ostream& out, const Airport& app);
	friend istream& operator >> (istream& in, Airport& app);
};
ostream& operator << (ostream& out, const Airport& app)
{

	for (auto i = app.app.begin(); i != app.app.end(); i++)
	{
		out << "#" << endl;
		out << i->Getdestination() << endl;
		out << i->Getnumber() << endl;
		out << i->Getname() << endl;
		out << i->Getsurname() << endl;
		out << i->Getdate().day << endl;
		out << i->Getdate().month << endl;
		out << i->Getdate().year << endl;
	}

	return out;
}
istream& operator >> (istream& in, Airport& app)
{
	while (!in.eof())
	{
		string mark = "#";
		do
		{


			getline(in, mark);
			if (mark != "#")break;
			else
			{
				string destination = "";
				int numbers = 0;
				string name = "";
				string surname = "";
				Date dates = { 0,0,0 };
				getline(in, destination);
				in >> numbers;
				in >> name;
				in >> surname;
				in >> dates.day;
				in >> dates.month;
				in >> dates.year;
				app.app.push_back(Application(destination, numbers, name, surname, { dates.day,dates.month,dates.year }));
			}
		} while (mark != "#");
	}
	return in;
}

void Save(const Airport& app)
{
	ofstream fileOut("app.txt");
	fileOut << app;
	fileOut.close();
}
void Download(Airport& app)
{
	system("cls");
	ifstream fileIn("app.txt");
	fileIn >> app;
	fileIn.close();
}
void main()
{
	Airport a;
	int key;
	string destination;
	int number;
	string name;
	string surname;
	Date date;
	while (true)
	{
		cout << " _______________________MENU________________________" << endl;
		cout << endl;
		cout << "\tAdd an application to the list:   [1]" << endl;
		cout << "\tDelete applications by number:    [2]" << endl;
		cout << "\tPrint application by number:      [3]" << endl;
		cout << "\tPrint applications by date:       [4]" << endl;
		cout << "\tShow all:                         [5]" << endl;
		cout << "\tSort by date:                     [6]" << endl;
		cout << "\tSort by destination:              [7]" << endl;
		cout << "\tSave to file:                     [8]" << endl;
		cout << "\tDownload from file:               [9]" << endl;
		cin >> key;
		switch (key)
		{
		case 1:
			system("cls");
			cout << " Enter destination: ";
			cin >> destination;
			cout << " Enter number: ";
			cin >> number;
			cout << " Enter name: ";
			cin >> name;
			cout << " Enter surname: ";
			cin >> surname;
			cout << " Enter date: ";
			cin >> date.day >> date.month >> date.year;
			a.Addapp(destination, number, name, surname, date);
			break;
		case 2:
			system("cls");
			cout << " Enter number to delete: ";
			cin >> number;
			a.Delete(number);
			break;
		case 3:
			system("cls");
			cout << " Enter number to print: ";
			cin >> number;
			a.Print(number);
			break;
		case 4:
			system("cls");
			cout << " Enter date to print: ";
			cin >> date.day >> date.month >> date.year;
			a.Print(date);
			break;
		case 5:
			system("cls");
			a.Show();
			break;
		case 6:
			system("cls");
			a.Sortbydate();
			break;
		case 7:
			system("cls");
			a.Sortbydestination();
			break;
		case 8:
			system("cls");
			Save(a);
			break;
		case 9:
			system("cls");
			Download(a);
			break;
		}
	}
}