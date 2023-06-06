#include <iostream>
using namespace std;

class Employer
{
protected:
	string name;
	string surname;
	string phone;
public:
	Employer() :name("none"), surname("none"), phone("none") {}
	Employer(string name, string surname, string phone) :name(name), surname(surname), phone(phone) {}
	virtual void Print()const = 0;
};
class President :public Employer
{
private:
	string status;
	string transport;
public:
	President() : status("none"), transport("none"), Employer() {}
	President(string status, string transport, string name, string surname, string phone) :status(status), transport(transport), Employer(name, surname, phone) {}
	void  Print()const override
	{
		cout << "__________PRESIDENT__________" << endl;
		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Phone number: " << phone << endl;
		cout << " Status: " << status << endl;
		cout << " Transport: " << transport << endl;
	}
};

class Manager :public Employer
{
private:
	string hours;
public:
	Manager() : hours("none"), Employer() {}
	Manager(string hours, string name, string surname, string phone) :hours(hours), Employer(name, surname, phone) {}
	void  Print()const override
	{
		cout << "__________MANAGER__________" << endl;
		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Phone number: " << phone << endl;
		cout << " Working hours per day: " << hours << endl;
	}
};

class Worker :public Employer
{
private:
	string hours;
public:
	Worker() : hours("none"), Employer() {}
	Worker(string hours, string name, string surname, string phone) :hours(hours), Employer(name, surname, phone) {}
	void  Print()const override
	{
		cout << "__________WORKER__________" << endl;
		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Phone number: " << phone << endl;
		cout << " Working hours per day: " << hours << endl;
	}
};

int main()
{
	President p("special", "personal car", "Volodymyr", "Zelenskyi", "0685075342");
	p.Print();
	Manager m("10", "Ivan", "Vidish", "0685055332");
	m.Print();
	Worker w("8", "Maxim", "Grechka", "0685565344");
	w.Print();
}