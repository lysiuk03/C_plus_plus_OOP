#include <iostream>
#include <string>
using namespace std;

struct Document
{
	string doc;
	int priority;
};

class Queue
{
	Document* docs;
	int size;
public:
	Queue() :docs(nullptr), size(0) {}
	void enqueue(Document doc)
	{
		int index = 0;
		while (index < size && docs[index].priority >= doc.priority) { index++; }
		Document* temp = new Document[size + 1];
		for (int i = 0; i < index; i++)
		{
			temp[i] = docs[i];
		}
		temp[index] = doc;
		for (int i = index; i < size; i++)
		{
			temp[i + 1] = docs[i];
		}
		if (docs != nullptr)
			delete[]docs;
		docs = temp;
		size++;
	}
	bool isempty()
	{
		return size == 0;
	}
	Document dequeue()
	{
		if (!isempty())
		{
			Document first = docs[0];
			for (int i = 0; i < size - 1; i++)
			{
				docs[i] = docs[i + 1];
			}
			size--;
			return first;
		}
		return	Document();
	}
	void show()
	{
		cout << "- - - - - - -Queue- - -  - - - - - " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << docs[i].doc << "  :  ";
			if (docs[i].priority == 1)cout << "Guest" << " ";
			if (docs[i].priority == 2)cout << "Administrator" << " ";
			if (docs[i].priority == 3)cout << "Manager" << " ";
			if (docs[i].priority == 4)cout << "Director" << " ";
		}
		cout << endl;
		cout << "__________________________________" << endl;
	}
	void oneshow()
	{
		cout << docs[0].doc << endl;
	}
	~Queue()
	{
		if (docs != nullptr)
			delete[]docs;
	}
};

int main()
{
	Queue print;
	string name;
	bool k = true;
	while (true)
	{
		cout << "~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~" << endl;
		cout << " Add a document to the queue   [1]" << endl;
		cout << " Print a document              [2]" << endl;
		cout << " Your choice: ";
		int key;
		cin >> key;
		switch (key)
		{
		case 1:
			system("cls");
			int p;
			cout << "Who are you?" << endl;
			cout << " 4-Director" << endl;
			cout << " 3-Manager" << endl;
			cout << " 2-Administrator" << endl;
			cout << " 1-Guest" << endl;
			cout << " Your choice: ";
			cin >> p;
			cout << "Enter name doc : ";
			cin >> name;
			print.enqueue({ name,p });
			print.show();
			break;
		case 2:
			system("cls");
			cout << " Document to be printed: ";
			print.oneshow();
			print.dequeue();
			print.show();
			break;
		default:
			break;
		}
	}
}