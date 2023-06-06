#include <iostream>
using namespace std;
struct days
{
	int day;
	int month;
	int year;
};
class Student
{
private:
	string lastname;
	string name;
	string surname;
	days birthday;
	string phone;
	string city;
	string country;
	string educationalname;
	string educationalcountry;
	string groupnumber;
public:
	void init()
	{
		cout << " Enter the student's lastname: ";
		cin >> lastname;
		cout << " Enter the student's name: ";
		cin >> name;
		cout << " Enter the student's surname: ";
		cin >> surname;
		cout << " Enter the student's birthday: ";
		cin >> birthday.day >> birthday.month >> birthday.year;
		cout << " Enter the student's phone number: ";
		cin >> phone;
		cout << " Enter the student's city of origin: ";
		cin >> city;
		cout << " Enter the student's country of origin: ";
		cin >> country;
		cout << " Enter the name of the educational institution: ";
		cin >> educationalname;
		cout << " Enter the country of the educational institution: ";
		cin >> educationalcountry;
		cout << " Enter the group number in which the student is studying: ";
		cin >> groupnumber;
	}

	void show()
	{
		cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << " Lastname: " << lastname << endl;
		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Birthday: " << birthday.day << "." << birthday.month << "." << birthday.year << endl;
		cout << " Phone number: " << phone << endl;
		cout << " City of origin: " << city << endl;
		cout << " Country of origin: " << country << endl;
		cout << " Name of the educational institution: " << educationalname << endl;
		cout << " Country of the educational institution: " << educationalcountry << endl;
		cout << " Group number: " << groupnumber << endl;
	}
	void setlastname(string lastname)
	{
		this->lastname = lastname;
	}
	string getlastname()
	{
		return lastname;
	}
	void setname(string name)
	{
		this->name = name;
	}
	string getname()
	{
		return name;
	}
	void setsurname(string surname)
	{
		this->surname = surname;
	}
	string getsurname()
	{
		return surname;
	}
	void setbirthday(days birthday)
	{
		this->birthday = birthday;
	}
	int getbirthday()
	{
		return birthday.day;
	}
	int getbirthmonths()
	{
		return birthday.month;
	}
	int getbirthyear()
	{
		return birthday.year;
	}
	void setphone(string phone)
	{
		this->phone = phone;
	}
	string getphone()
	{
		return phone;
	}
	void setcity(string city)
	{
		this->city = city;
	}
	string getcity()
	{
		return city;
	}
	void setcountry(string country)
	{
		this->country = country;
	}
	string getcountry()
	{
		return country;
	}
	void seteducationalname(string educationalname)
	{
		this->educationalname = educationalname;
	}
	string geteducationalname()
	{
		return educationalname;
	}
	void seteducationalcountry(string educationalcountry)
	{
		this->educationalcountry = educationalcountry;
	}
	string geteducationalcountry()
	{
		return educationalcountry;
	}
	void setgroupnumber(string groupnumber)
	{
		this->groupnumber = groupnumber;
	}
	string getgroupnumber()
	{
		return groupnumber;
	}
};


void main()
{
	Student st1;
	st1.init();
	st1.show();
	Student st2;
	st2.setlastname("Lysyjuk");
	st2.setname("Viktoriia");
	st2.setsurname("Valerievna");
	st2.setbirthday({ 10,07,2003 });
	st2.setphone("0685062142");
	st2.setcity("Rivne");
	st2.setcountry("Ukraine");
	st2.seteducationalname("NUWGP");
	st2.seteducationalcountry("Ukraine");
	st2.setgroupnumber("ECO-21");
	cout << "+++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << " Lastname: " << st2.getlastname() << endl;
	cout << " Name: " << st2.getname() << endl;
	cout << " Surname: " << st2.getsurname() << endl;
	cout << " Birthday: " << st2.getbirthday() << "." << st2.getbirthmonths() << "." << st2.getbirthyear() << endl;
	cout << " Phone number: " << st2.getphone() << endl;
	cout << " City of origin: " << st2.getcity() << endl;
	cout << " Country of origin: " << st2.getcountry() << endl;
	cout << " Name of the educational institution: " << st2.geteducationalname() << endl;
	cout << " Country of the educational institution: " << st2.geteducationalcountry() << endl;
	cout << " Group number: " << st2.getgroupnumber() << endl;
}