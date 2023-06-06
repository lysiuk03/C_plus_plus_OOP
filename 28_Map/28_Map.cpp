#include <iostream>
#include<map>
#include<list>
#include<string>
#include<Windows.h>
#include<fstream>
using namespace std;

class Dictionary
{
	string name;
	map<string, list<string>> dic;

public:
	Dictionary(string name) :name(name) { }
	void Addword(string word, list<string> translate)
	{
		dic.insert(make_pair(word, translate));
	}
	void Print()const
	{
		cout << "Dictionary : " << name << endl;
		for (auto pair : dic)
		{
			cout << pair.first << " - ";
			for (string t : pair.second)
			{
				cout << t << " ; ";
			}
			cout << endl;
		}
	}
	bool IsExist(string word)
	{
		return dic.find(word) != dic.end();
	}
	void AddTranslate(string word, string translate)
	{
		dic[word].push_back(translate);
	}
	void DeleteWord(string word)
	{
		map<string, list<string>>::iterator it;
		it = dic.find(word);
		if (it != dic.end())
			dic.erase(it);
	}
	void Find(string word)
	{
		cout << " Means: ";
		for (string elem : dic[word])
			cout << elem << " ; ";
	}
	friend ostream& operator << (ostream& out, const Dictionary& d);
	friend istream& operator >> (istream& in, Dictionary& d);
};
ostream& operator << (ostream& out, const Dictionary& d)
{
	out << d.name << endl;
	for (auto pair : d.dic)
	{
		out << pair.first << endl;
		for (string t : pair.second)
		{
			out << t << endl;
		}
		out << ":" << endl;
	}
	return out;
}
istream& operator >> (istream& in, Dictionary& d)
{
	getline(in, d.name);
	while (!in.eof())
	{
		string w;
		getline(in, w);
		if (w.empty())break;
		list<string> l;
		string translate = ":";
		do
		{
			getline(in, translate);
			if (translate != ":")	l.push_back(translate);
		} while (translate != ":");
		d.dic.insert(make_pair(w, l));
	}
	return in;
}
void Save(Dictionary dic)
{
	ofstream fileOut("dictionary.txt");
	fileOut << dic;
	fileOut.close();
}
void Download()
{
	ifstream fileIn("dictionary.txt");
	Dictionary voc("");
	fileIn >> voc;
	fileIn.close();
	voc.Print();
}
void main()
{
	setlocale(LC_CTYPE, "ukr");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Dictionary voc("English-Ukrainian");
	int key;
	string word;
	list<string>w;
	string translate;
	while (true)
	{
		cout << endl;
		cout << " _______________________MENU________________________" << endl;
		cout << endl;
		cout << "\tAdd a word with translations:   [1]" << endl;
		cout << "\tFind word translations:         [2]" << endl;
		cout << "\tAdd a translation to word:      [3]" << endl;
		cout << "\tDelete the word:                [4]" << endl;
		cout << "\tShow all:                       [5]" << endl;
		cout << "\tSave to file:                   [6]" << endl;
		cout << "\tDownload from file:             [7]" << endl;
		cin >> key;
		switch (key)
		{
		case 1:
			system("cls");
			cout << "Enter word : ";
			cin.get();
			getline(cin, word);
			cout << "Enter translate: ";
			getline(cin, translate);
			voc.Addword(word, { translate });
			do
			{
				cout << "Enter translate: ";
				getline(cin, translate);
				if (!translate.empty())
					voc.AddTranslate(word, translate);
			} while (!translate.empty());
			break;
		case 2:
			system("cls");
			cout << "Enter word to translate: ";
			cin.get();
			getline(cin, word);
			if (!voc.IsExist(word))
				cout << "Word not found!\n";
			else
			{
				voc.Find(word);
			}
			break;
		case 3:
			system("cls");
			cout << "Enter word to add translatins: ";
			cin.get();
			getline(cin, word);
			if (!voc.IsExist(word))
				cout << "Word not found!\n";
			else
			{
				do
				{
					cout << "Enter translate: ";
					getline(cin, translate);
					if (!translate.empty())
						voc.AddTranslate(word, translate);

				} while (!translate.empty());
			}

			break;
		case 4:
			system("cls");
			cout << " Enter word: ";
			cin.get();
			getline(cin, word);
			voc.DeleteWord(word);
			break;
		case 5:
			system("cls");
			voc.Print();
			break;
		case 6:
			system("cls");
			Save(voc);
			break;
		case 7:
			system("cls");
			Download();
			break;
		default:
			break;
		}
	}
}
