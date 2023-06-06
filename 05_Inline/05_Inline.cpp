# include <iostream>
#include<fstream>
using namespace std;

struct person
{
	string surname;
	string name;
	string patronymic;
};
class Phonebook
{
private:
	person fullname;
	string homephone;
	string workphone;
	string mobilephone;
	string information;
public:
	Phonebook()
	{
		fullname.name = "no name";
		fullname.patronymic = "no patronymic";
		fullname.surname = "no surname";
		homephone = " - ";
		workphone = " - ";
		mobilephone = " - ";
		information = " - ";
	}
	Phonebook(person fullname, string homephone, string workphone, string mobilephone, string information)
	{
		this->fullname.name = fullname.name;
		this->fullname.patronymic = fullname.patronymic;
		this->fullname.surname = fullname.surname;
		this->homephone = homephone;
		this->workphone = workphone;
		this->mobilephone = mobilephone;
		this->information = information;
	}
	void setsubscriber(person fullname, string homephone, string workphone, string mobilephone, string information)
	{
		this->fullname = fullname;
		this->homephone = homephone;
		this->workphone = workphone;
		this->mobilephone = mobilephone;
		this->information = information;
	}
	string getsurname();
	void setsurname(string surname);
	string getname();
	void setname(string name);
	string getpatronymic();
	void setpatronymic(string patronymic);
	string gethomephone();
	void sethomephone(string homephone);
	string getworkphone();
	void setworkphone(string workphone);
	string getmobilephone();
	void setmobilephone(string mobilephone);
	string getinformation();
	void setinformation(string information);
	void setperson(person fullname);
};
inline string Phonebook::getsurname()
{
	return fullname.surname;
}
inline void Phonebook::setsurname(string surname)
{
	fullname.surname = surname;
}
inline string Phonebook::getname()
{
	return fullname.name;
}
inline void Phonebook::setname(string name)
{
	fullname.name = name;
}
inline string Phonebook::getpatronymic()
{
	return fullname.patronymic;
}
inline void Phonebook::setpatronymic(string patronymic)
{
	fullname.patronymic = patronymic;
}
inline string Phonebook::gethomephone()
{
	return homephone;
}
inline void Phonebook::sethomephone(string homephone)
{
	this->homephone = homephone;
}
inline string Phonebook::getworkphone()
{
	return workphone;
}
inline void Phonebook::setworkphone(string workphone)
{
	this->workphone = workphone;
}
inline string Phonebook::getmobilephone()
{
	return mobilephone;
}
inline void Phonebook::setmobilephone(string mobilephone)
{
	this->mobilephone = mobilephone;
}
inline string Phonebook::getinformation()
{
	return information;
}
inline void Phonebook::setinformation(string information)
{
	this->information = information;
}
inline void Phonebook::setperson(person fullname)
{
	this->fullname = fullname;
}

void feelarr(Phonebook* arr, int size)
{
	string homephone, workphone, mobilephone, information;
	person fullname;
	cout << "------------FEEL-------------" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << " Person " << i + 1 << ": " << endl;
		cout << " Enter fullname: ";
		cin >> fullname.surname >> fullname.name >> fullname.patronymic;
		cout << " Enter homephone: ";
		cin >> homephone;
		cout << " Enter workphone: ";
		cin >> workphone;
		cout << " Enter mobilephone: ";
		cin >> mobilephone;
		cout << " Enter information: ";
		cin >> information;
		arr[i].setsubscriber(fullname, homephone, workphone, mobilephone, information);
	}
}
void show(Phonebook* arr, int size)
{
	cout << "------------SHOW-------------" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << " Person " << i + 1 << ": " << endl;
		cout << " Fullname: " << arr[i].getsurname() << " " << arr[i].getname() << " " << arr[i].getpatronymic() << endl;
		cout << " Homephone: " << arr[i].gethomephone() << endl;
		cout << " Workphone: " << arr[i].getworkphone() << endl;
		cout << " Mobilephone: " << arr[i].getmobilephone() << endl;
		cout << " Information: " << arr[i].getinformation() << endl;
	}
}
void addperson(Phonebook*& arr, int& size)
{
	cout << "------------ADD------------- " << endl;
	size++;
	Phonebook* temp = new Phonebook[size];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	string homephone, workphone, mobilephone, information;
	person fullname;
	cout << " Person " << size << ": " << endl;
	cout << " Enter fullname: ";
	cin >> fullname.surname >> fullname.name >> fullname.patronymic;
	cout << " Enter homephone: ";
	cin >> homephone;
	cout << " Enter workphone: ";
	cin >> workphone;
	cout << " Enter mobilephone: ";
	cin >> mobilephone;
	cout << " Enter information: ";
	cin >> information;
	temp[size - 1].setsubscriber(fullname, homephone, workphone, mobilephone, information);
	delete[]arr;
	arr = temp;
}
void deleteperson(Phonebook*& arr, int& size)
{
	cout << "------------DELETE------------- " << endl;
	size--;
	int num;
	cout << " Enter the number of the person you want to delete: ";
	cin >> num;
	Phonebook* temp = new Phonebook[size];
	for (int i = 0; i < num - 1; i++)
	{
		temp[i] = arr[i];
	}
	for (int i = num - 1; i < size; i++)
	{
		temp[i] = arr[i + 1];
	}
	delete[]arr;
	arr = temp;
}
void oneshow(Phonebook* arr, int s)
{
	cout << "------------SHOW-------------" << endl;
	cout << " Person " << s + 1 << ": " << endl;
	cout << " Fullname: " << arr[s].getsurname() << " " << arr[s].getname() << " " << arr[s].getpatronymic() << endl;
	cout << " Homephone: " << arr[s].gethomephone() << endl;
	cout << " Workphone: " << arr[s].getworkphone() << endl;
	cout << " Mobilephone: " << arr[s].getmobilephone() << endl;
	cout << " Information: " << arr[s].getinformation() << endl;
}
void seach(Phonebook* arr, int size)
{
	cout << "------------SEACH------------- " << endl;
	static int s;
	cout << " Enter the full name you want to find: ";
	person Fullname;
	cin >> Fullname.surname >> Fullname.name >> Fullname.patronymic;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].getsurname() == Fullname.surname && arr[i].getname() == Fullname.name && arr[i].getpatronymic() == Fullname.patronymic)
		{
			s = i;
		}
	}
	oneshow(arr, s);
}
void savetofile(Phonebook* arr, int size)
{
	ofstream out("Phonebook.txt");
	for (int i = 0; i < size; i++)
	{
		out << arr[i].getsurname();
		out << ':';
		out << arr[i].getname();
		out << ':';
		out << arr[i].getpatronymic();
		out << ':';
		out << arr[i].gethomephone();
		out << ':';
		out << arr[i].getworkphone();
		out << ':';
		out << arr[i].getmobilephone();
		out << ':';
		out << arr[i].getinformation();
		out << '|';
	}
	out.close();
}
void readfromfile(Phonebook* arr, int size)
{
	ifstream in("Phonebook.txt");
	char buffsurname[50], buffname[50], buffpatronymic[50], buffhomephone[50], buffworkphone[50], buffmobilephone[50], buffinformation[50];
	for (size_t i = 0; i < size; i++)
	{
		in.getline(buffsurname, 50, ':');
		in.getline(buffname, 50, ':');
		in.getline(buffpatronymic, 50, ':');
		in.getline(buffhomephone, 50, ':');
		in.getline(buffworkphone, 50, ':');
		in.getline(buffmobilephone, 50, ':');
		in.getline(buffinformation, 50, '|');
		arr[i].setsurname(string(buffsurname));
		arr[i].setname(string(buffsurname));
		arr[i].setpatronymic(string(buffpatronymic));
		arr[i].sethomephone(string(buffhomephone));
		arr[i].setworkphone(string(buffworkphone));
		arr[i].setmobilephone(string(buffmobilephone));
		arr[i].setinformation(string(buffinformation));
	}
	in.close();
}
void menu(Phonebook* arr, int size)
{
	int key;
	bool k = true;
	while (true)
	{
		cout << " _______________________MENU________________________" << endl;
		cout << "\n\tFill in the first subscribers   [1]" << endl;
		cout << "\tShow all subscribers:           [2]" << endl;
		cout << "\tAdd new  subscribers:           [3]" << endl;
		cout << "\tDelete the subscribers:         [4]" << endl;
		cout << "\tFind a subscriber by fullname:  [5]" << endl;
		cout << "\tSave to file:                   [6]" << endl;
		cout << "\tDownload from file              [7]" << endl;
		cin >> key;
		switch (key)
		{
		case 1:
			system("cls");
			feelarr(arr, size);
			break;
		case 2:
			system("cls");
			show(arr, size);
			break;
		case 3:
			system("cls");
			addperson(arr, size);
			break;
		case 4:
			system("cls");
			deleteperson(arr, size);
			break;
		case 5:
			system("cls");
			seach(arr, size);
			break;
		case 6:
			system("cls");
			savetofile(arr, size);
			break;
		case 7:
			readfromfile(arr, size);
			break;
		default:
			break;
		}
	}

}
void main()
{
	int size = 3;
	Phonebook* arr = new Phonebook[size];
	bool k = true;
	menu(arr, size);
	delete[]arr;
}