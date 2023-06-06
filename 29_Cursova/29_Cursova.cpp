#include <iostream>
#include<windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include<fstream>
#include <exception>
using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct Date
{
	short d;
	short m;
	short y;
};
struct Literatur
{
	int ID;
	string type;
	string author;
	string title;
	Date date;
	string genre;
	int amount;
	Literatur() :ID(0), type("none"), author("none"), title("none"), date({ 0, 0, 0 }), genre("none"), amount(0) {}
	Literatur(int ID, string type, string author, string title, Date date, string genre, int amount) :ID(ID), type(type), author(author), title(title), date(date), genre(genre), amount(amount) {}
	void Print()
	{
		cout << "\t\t\t\t| ID: " << ID << endl;
		cout << "\t\t\t\t| Type: " << type << endl;
		cout << "\t\t\t\t| Author: " << author << endl;
		cout << "\t\t\t\t| Title: " << title << endl;
		cout << "\t\t\t\t| Year: " << date.d << "." << date.m << "." << date.y << endl;
		cout << "\t\t\t\t| Genre: " << genre << endl;
		cout << "\t\t\t\t| Amount: " << amount << endl;
		cout << endl;
	}
	friend ostream& operator << (ostream& out, const Literatur& l);
};

class Library
{
private:

	vector<Literatur> lit;

	void Deleteall()
	{
		lit.erase(lit.begin(), lit.end());
	}
	void Table()
	{
		cout << "\n\n\n";
		cout << "\t\t\t##################################################" << endl;
		cout << "\t\t\t#----------------------MENU----------------------#" << endl;
		cout << "\t\t\t##################################################" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t#                                                #" << endl;
		cout << "\t\t\t##################################################" << endl;
	}
	void Addlit(Literatur l)
	{
		lit.push_back(l);
	}
	int generateID()
	{
		static int ID = lit.size() + 1;
		return ID++;
	}
	void Addmenu()
	{
		while (true)
		{
			int x = 29;
			int y = 8;
			string author, title, genre;
			int amount, k;
			Date date;
			system("cls");
			Table();
			gotoxy(x, y++); cout << "Add a book:                          [1]";
			gotoxy(x, y++); cout << "Add a magazine:                      [2]";
			gotoxy(x, y++); cout << "Add a newspaper:                     [3]";
			gotoxy(x, y++); cout << "Exit:                                [4]";
			gotoxy(x + 10, y + 6); cout << "Your choise:";
			gotoxy(x + 23, y + 6); cin >> k;
			if (k < 1 || k>4)
			{
				throw invalid_argument("Invalid key!");
			}
			switch (k)
			{
			case 1:
				system("cls");
				gotoxy(35, 2); cout << "--------Adding a book---------" << endl;
				gotoxy(35, 3); cout << "Enter the author: ";
				cin.get(); getline(cin, author);
				gotoxy(35, 4); cout << "Enter the title: ";
				getline(cin, title);
				gotoxy(35, 5); cout << "Enter the date: ";
				cin >> date.d >> date.m >> date.y;
				gotoxy(35, 6); cout << "Enter the genre: ";
				cin.get(); getline(cin, genre);
				gotoxy(35, 7); cout << "Enter the amount: ";
				cin >> amount;
				Addlit(Literatur(generateID(), "book", author, title, date, genre, amount));
				gotoxy(35, 9); cout << " The book is added)" << endl;
				gotoxy(35, 11); system("pause");
				break;
			case 2:
				system("cls");
				gotoxy(35, 2); cout << "--------Adding a magazine---------" << endl;
				gotoxy(35, 3); cout << "Enter the author: ";
				cin.get(); getline(cin, author);
				gotoxy(35, 4); cout << "Enter the title: ";
				getline(cin, title);
				gotoxy(35, 5); cout << "Enter the date: ";
				cin >> date.d >> date.m >> date.y;
				gotoxy(35, 6); cout << "Enter the genre: ";
				cin.get(); getline(cin, genre);
				gotoxy(35, 7); cout << "Enter the amount: ";
				cin >> amount;
				Addlit(Literatur(generateID(), "magazine", author, title, date, genre, amount));
				gotoxy(35, 9); cout << " The magazine is added)" << endl;
				gotoxy(35, 11); system("pause");
				break;
			case 3:
				system("cls");
				gotoxy(35, 2); cout << "--------Adding a magazine---------" << endl;
				gotoxy(35, 3); cout << "Enter the author: ";
				cin.get(); getline(cin, author);
				gotoxy(35, 4); cout << "Enter the title: ";
				getline(cin, title);
				gotoxy(35, 5); cout << "Enter the date: ";
				cin >> date.d >> date.m >> date.y;
				gotoxy(35, 6); cout << "Enter the genre: ";
				cin.get(); getline(cin, genre);
				gotoxy(35, 7); cout << "Enter the amount: ";
				cin >> amount;
				Addlit(Literatur(generateID(), "newspaper", author, title, date, genre, amount));
				gotoxy(35, 9); cout << " The newspaper is added)" << endl;
				gotoxy(35, 11); system("pause");
				break;
			case 4:
				Mainmenu();
				break;
			}
		}
	}
	void Delete(int ID)
	{
		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].ID == ID)
			{
				lit.erase(lit.begin() + i);
			}
		}
	}
	void Deletetype(string type)
	{
		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].type == type)
			{
				lit.erase(lit.begin() + i);
				i--;
			}
		}
	}
	void Deleteauthor(string author)
	{

		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].author == author)
			{

				lit.erase(lit.begin() + i);
				i--;
			}

		}
	}
	void Deletenewspapers(Date date)
	{

		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].date.y == date.y && lit[i].type == "newspaper")
			{

				lit.erase(lit.begin() + i);
				i--;
			}
		}
	}
	void Deletemenu()
	{
		while (true)
		{
			int x = 29;
			int y = 8;
			int  ID, k;
			Date date({ 0,0,0 });
			string type, author;
			system("cls");
			Table();
			gotoxy(x, y++); cout << "Delete by ID:                        [1]";
			gotoxy(x, y++); cout << "Delete all by author:                [2]";
			gotoxy(x, y++); cout << "Delete all by type:                  [3]";
			gotoxy(x, y++); cout << "Delete newspapers by year:           [4]";
			gotoxy(x, y++); cout << "Exit:                                [5]";
			gotoxy(x + 10, y + 5); cout << "Your choise:";
			gotoxy(x + 23, y + 5); cin >> k;
			if (k < 1 || k>5)
				throw invalid_argument("Invalid key!");
			switch (k)
			{
			case 1:
				system("cls");
				gotoxy(35, 2); cout << "------Delete by ID------";
				gotoxy(35, 3); cout << "Enter ID: ";
				cin >> ID;
				Delete(ID);
				gotoxy(35, 9); cout << "The literatur is delete)" << endl;
				gotoxy(35, 11); system("pause");
				break;
			case 2:
				system("cls");
				gotoxy(35, 2); cout << "------Delete by author------";
				gotoxy(35, 3); cout << "Enter author: ";
				cin.get(); getline(cin, author);
				Deleteauthor(author);
				gotoxy(35, 9); cout << "The literatur is delete)" << endl;
				gotoxy(35, 11); system("pause");
				break;
			case 3:
				system("cls");
				gotoxy(35, 2); cout << "------Delete by type------";
				gotoxy(35, 3); cout << "Enter type: ";
				cin.get(); getline(cin, type);
				Deletetype(type);
				gotoxy(35, 9); cout << "The literatur is delete)" << endl;
				gotoxy(35, 11); system("pause");
				break;
			case 4:
				system("cls");
				cout << endl;
				gotoxy(35, 2); cout << "------Delete newspapers by year------";
				gotoxy(35, 3); cout << "Enter year: ";
				cin >> date.y;
				Deletenewspapers(date);
				gotoxy(35, 9); cout << "The literatur is delete)" << endl;
				gotoxy(35, 11); system("pause");
				break;
			case 5:
				Mainmenu();
				break;
			}
		}
	}
	void Print(int ID)
	{
		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].ID == ID)
			{
				lit[i].Print();
			}
		}
	}
	void AllPrint()
	{
		for (int i = 0; i < lit.size(); i++)
		{
			lit[i].Print();
			cout << endl;
		}
	}
	void Selectiontype(string type)
	{
		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].type == type)
			{

				lit[i].Print();
			}
		}
	}
	void Selectionbooktype(string genre)
	{
		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].type == "book" && lit[i].genre == genre)
			{
				lit[i].Print();
			}
		}
	}
	void Selectionmagazine(string title, Date date)
	{
		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].type == "magazine" && lit[i].title == title && lit[i].date.y == date.y)
			{
				lit[i].Print();
			}
		}
	}
	void Selectioncentury(int st)
	{
		int end = st * 100;
		int begin = end - 99;
		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].date.y < end && lit[i].date.y > begin && lit[i].type == "book")
			{
				lit[i].Print();
			}
		}
	}
	void Showmenu()
	{
		while (true)
		{
			system("cls");
			int x = 29;
			int y = 8;
			string genre, title;
			int ID, st, k;
			Date date = { 0,0,0 };
			Table();
			gotoxy(x, y++); cout << "Show by ID:                          [1]";
			gotoxy(x, y++); cout << "Show All:                            [2]";
			gotoxy(x, y++); cout << "Book selection:                      [3]";
			gotoxy(x, y++); cout << "Magazine selection:                  [4]";
			gotoxy(x, y++); cout << "Newspapper selection:                [5]";
			gotoxy(x, y++); cout << "Books by century:                    [6]";
			gotoxy(x, y++); cout << "Books by genre:                      [7]";
			gotoxy(x, y++); cout << "Magazines for the year:              [8]";
			gotoxy(x, y++); cout << "Exit:                                [9]";
			gotoxy(x + 10, y + 1); cout << "Your choise:";
			gotoxy(x + 23, y + 1); cin >> k;
			if (k < 1 || k>9)
				throw invalid_argument("Invalid key!");
			switch (k)
			{
			case 1:
				system("cls");
				gotoxy(32, 2); cout << "------Show by ID------" << endl;
				gotoxy(32, 3); cout << "Enter ID: ";
				cin >> ID;
				cout << endl;
				Print(ID);
				system("pause");
				break;
			case 2:
				system("cls");
				cout << "\n\n";
				AllPrint();
				system("pause");
				break;
			case 3:
				system("cls");
				gotoxy(32, 2); cout << "----------Book selection-----------\n" << endl;
				Selectiontype("book");
				system("pause");
				break;
			case 4:
				system("cls");
				gotoxy(32, 2); cout << "-------Magazine selection-----------\n" << endl;
				Selectiontype("magazine");
				system("pause");
				break;
			case 5:
				system("cls");
				gotoxy(32, 2); cout << "-------Newspapper selection--------\n" << endl;
				Selectiontype("newspaper");
				system("pause");
				break;
			case 6:
				system("cls");
				gotoxy(32, 2); cout << "------Books by century------" << endl;
				gotoxy(32, 3); cout << "Enter century: ";
				cin >> st;
				cout << endl;
				Selectioncentury(st);
				system("pause");
				break;
			case 7:
				system("cls");
				gotoxy(32, 2); cout << "------Books by genre------" << endl;
				gotoxy(32, 3); cout << "Enter genre: ";
				cin.get(); getline(cin, genre);
				cout << endl;
				Selectionbooktype(genre);
				system("pause");
				break;
			case 8:
				system("cls");
				gotoxy(32, 2); cout << "------Magazines by year------" << endl;
				gotoxy(32, 3); cout << "Enter title: ";
				cin.get(); getline(cin, title);
				gotoxy(32, 4); cout << "Enter year : ";
				cin >> date.y;
				cout << endl;
				Selectionmagazine(title, date);
				system("pause");
				break;
			case 9:
				Mainmenu();
				break;
			}
		}
	}
	void Sorttype()
	{
		sort(lit.begin(), lit.end(), [](Literatur& l1, Literatur& l2) {return l1.type < l2.type; });
	}
	void Sortauthor()
	{
		sort(lit.begin(), lit.end(), [](Literatur& l1, Literatur& l2) {return l1.author < l2.author; });
	}
	void Sorttitle()
	{
		sort(lit.begin(), lit.end(), [](Literatur& l1, Literatur& l2) {return l1.title < l2.title; });
	}
	void Sortmenu()
	{
		while (true)
		{
			int x = 29;
			int y = 8;
			int  k;
			system("cls");
			Table();
			gotoxy(x, y++); cout << "Sort by type:                        [1]";
			gotoxy(x, y++); cout << "Sort by title:                       [2]";
			gotoxy(x, y++); cout << "Sort by author:                      [3]";
			gotoxy(x, y++); cout << "Exit:                                [4]";
			gotoxy(x + 10, y + 6); cout << "Your choise:";
			gotoxy(x + 23, y + 6); cin >> k;
			if (k < 1 || k>4)
				throw invalid_argument("Invalid key!");
			switch (k)
			{
			case 1:
				Sorttype();
				system("cls");
				gotoxy(32, 3); cout << "The Library is sorted!!!";
				gotoxy(32, 5); system("pause");
				break;
			case 2:
				Sorttitle();
				system("cls");
				gotoxy(32, 3); cout << "The Library is sorted!!!";
				gotoxy(32, 5); system("pause");
				break;
			case 3:
				Sortauthor();
				system("cls");
				gotoxy(32, 3); cout << "The Library is sorted!!!";
				gotoxy(32, 5); system("pause");
				break;
			case 4:
				Mainmenu();
				break;
			}
		}
	}
	void Availability(string type, string author, string title)
	{
		int j = 0;
		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].type == type && lit[i].author == author && lit[i].title == title)
			{
				cout << "\t\t\t (Date " << lit[i].date.d << "." << lit[i].date.m << "." << lit[i].date.y << ")" << " This " << type << " is available in quantity " << lit[i].amount << " :)" << endl;
				j++;
			}
		}
		if (j == 0)
		{
			cout << " This " << type << " is not available  :(" << endl;
		}
	}
	void Seachmenu()
	{
		while (true)
		{
			int x = 29;
			int y = 8;
			string author, title;
			int  k;
			system("cls");
			Table();
			gotoxy(x, y++); cout << "Availability og the book:            [1]";
			gotoxy(x, y++); cout << "Availability og the magazine:        [2]";
			gotoxy(x, y++); cout << "Availability og the newspaper:       [3]";
			gotoxy(x, y++); cout << "Exit:                                [4]";
			gotoxy(x + 10, y + 5); cout << "Your choise:";
			gotoxy(x + 23, y + 5); cin >> k;
			if (k < 1 || k>4)
				throw invalid_argument("Invalid key!");
			switch (k)
			{
			case 1:
				system("cls");
				gotoxy(35, 2); cout << "----------Availability----------" << endl;
				gotoxy(35, 3); cout << " Enter author: ";
				cin.get(); getline(cin, author);
				gotoxy(35, 4); cout << " Enter title: ";
				getline(cin, title);
				Availability("book", author, title);
				cout << "\t\t\t\t"; system("pause");
				break;
			case 2:
				system("cls");
				gotoxy(35, 2); cout << "----------Availability----------" << endl;
				gotoxy(35, 3); cout << " Enter author: ";
				cin.get(); getline(cin, author);
				gotoxy(35, 4); cout << " Enter title: ";
				getline(cin, title);
				Availability("magazine", author, title);
				cout << "\t\t\t\t"; system("pause");
				break;
			case 3:
				system("cls");
				gotoxy(35, 2); cout << "----------Availability----------" << endl;
				gotoxy(35, 3); cout << " Enter author: ";
				cin.get(); getline(cin, author);
				gotoxy(35, 4); cout << " Enter title: ";
				getline(cin, title);
				Availability("newspaper", author, title);
				cout << "\t\t\t\t"; system("pause");
				break;
			case 4:
				Mainmenu();
				break;
			}
		}
	}
	int Info(string type)
	{
		int count = 0;
		for (int i = 0; i < lit.size(); i++)
		{
			if (lit[i].type == type)
				count++;
		}
		return count;
	}
	void Save()
	{
		ofstream fileOut("library.txt");
		for (int i = 0; i < lit.size(); i++)
		{
			fileOut << lit[i];
		}
		fileOut.close();
	}
	void Mainmenu()
	{

		while (true)
		{
			system("cls");
			int x = 29;
			int y = 8;
			int key;
			Library lit;
			Table();
			gotoxy(x, y++); cout << "Delete all:                          [1]";
			gotoxy(x, y++); cout << "Add:                                 [2]";
			gotoxy(x, y++); cout << "Delete:                              [3]";
			gotoxy(x, y++); cout << "Show and selections:                 [4]";
			gotoxy(x, y++); cout << "Sort:                                [5]";
			gotoxy(x, y++); cout << "Seach:                               [6]";
			gotoxy(x, y++); cout << "Info:                                [7]";
			gotoxy(x, y++); cout << "Save:                                [8]";
			gotoxy(x + 10, y + 2); cout << "Your choise:";
			gotoxy(x + 23, y + 2); cin >> key;
			if (key < 1 || key>8)
			{
				throw invalid_argument("Invalid key!");
			}
			switch (key)
			{
			case 1:
				system("cls");
				Deleteall();
				gotoxy(32, 3); cout << "All information deleted!!!";
				gotoxy(32, 5); system("pause");
				break;
			case 2:
				try
				{
					Addmenu();
				}
				catch (invalid_argument& ex)
				{
					system("cls");
					gotoxy(32, 2); cout << ex.what();
					gotoxy(32, 3); cout << "The key must be [1-4]!!! Please try again)";
					gotoxy(32, 5); system("pause");
				}
				break;
			case 3:
				try
				{
					Deletemenu();
				}
				catch (invalid_argument& ex)
				{
					system("cls");
					gotoxy(32, 2); cout << ex.what();
					gotoxy(32, 3); cout << "The key must be [1-5]!!! Please try again)";
					gotoxy(32, 5); system("pause");
				}
				break;
			case 4:
				try
				{
					Showmenu();
				}
				catch (invalid_argument& ex)
				{
					system("cls");
					gotoxy(32, 2); cout << ex.what();
					gotoxy(32, 3); cout << "The key must be [1-9]!!! Please try again)";
					gotoxy(32, 5); system("pause");
				}
				break;
			case 5:
				try
				{
					Sortmenu();
				}
				catch (invalid_argument& ex)
				{
					system("cls");
					gotoxy(32, 2); cout << ex.what();
					gotoxy(32, 3); cout << "The key must be [1-4]!!! Please try again)";
					gotoxy(32, 5); system("pause");
				}
				break;
			case 6:
				try
				{
					Seachmenu();
				}
				catch (invalid_argument& ex)
				{
					system("cls");
					gotoxy(32, 2); cout << ex.what();
					gotoxy(32, 3); cout << "The key must be [1-4]!!! Please try again)";
					gotoxy(32, 5); system("pause");
				}
				break;
			case 7:
				system("cls");
				gotoxy(32, 2); cout << "----------Info----------";
				gotoxy(32, 3); cout << " Amount of literature: " << Info("book") + Info("magazine") + Info("newspaper");
				gotoxy(32, 4); cout << " Amount of books: " << Info("book");
				gotoxy(32, 5); cout << " Amount of magazines: " << Info("magazine");
				gotoxy(32, 6); cout << " Amount of newspapers: " << Info("newspaper");
				cout << endl;
				system("pause");
				break;
			case 8:
				system("cls");
				Save();
				gotoxy(32, 3); cout << "All information save!!!";
				gotoxy(32, 5); system("pause");
				break;
			}
		}
	}
public:
	void Start()
	{
		try
		{
			Mainmenu();
		}
		catch (invalid_argument& ex)
		{
			system("cls");
			gotoxy(32, 2); cout << ex.what();
			gotoxy(32, 3); cout << "The key must be [1-8]!!! Please try again)";
			gotoxy(32, 5); system("pause");
			Start();
		}
	}
	friend istream& operator >> (istream& in, Library& l);
};
ostream& operator << (ostream& out, const Literatur& l)
{
	out << l.type << endl;;
	out << l.author << endl;
	out << l.title << endl;
	out << l.date.d << endl;
	out << l.date.m << endl;
	out << l.date.y << endl;
	out << l.genre << endl;
	out << l.amount << endl;
	return out;
}
istream& operator >> (istream& in, Library& l)
{
	while (!in.eof())
	{
		static int ID = 1;
		string type = "";
		string author;
		string title;
		Date date;
		string genre;
		int amount;
		if (ID > 1)
		{
			in.get();
		}
		getline(in, type);
		if (type == "")break;
		getline(in, author);
		getline(in, title);
		in >> date.d;
		in >> date.m;
		in >> date.y;
		in.get(); getline(in, genre);
		in >> amount;
		l.lit.push_back(Literatur(ID++, type, author, title, date, genre, amount));
	}
	return in;
}

int main()
{
	Library lib;
	ifstream fileIn("library.txt");
	fileIn >> lib;
	fileIn.close();
	lib.Start();
}
