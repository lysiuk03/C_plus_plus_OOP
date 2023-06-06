#include <iostream>
using namespace std;

template<typename T_data>
class List
{
	struct Node
	{
		T_data value;
		Node* next;
		Node(T_data value, Node* next) :value(value), next(next) {	}
	};
	Node* head;
public:
	List()
	{
		head = nullptr;
	}
	List(const List& other)
	{
		for (Node* current = other.head; current != nullptr; current = current->next)
		{
			this->AddToTail(current->value);
		}
	}
	List& operator =(const List& other)
	{
		DeleteAll();
		for (Node* current = other.head; current != nullptr; current = current->next)
		{
			this->AddToTail(current->value);
		}
		return *this;
	}
	void AddToHead(T_data value)
	{
		Node* newNode = new Node(value, head);
		head = newNode;
	}
	void DeleteFromHead()
	{
		if (head == nullptr)return;
		else
		{
			Node* temp = head;
			head = head->next;
			delete[]temp;
		}
	}
	void AddToTail(T_data value)
	{
		Node* newNode = new Node(value, nullptr);
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void DeleteFromTail()
	{
		if (head == nullptr)return;
		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}

	}
	void Show()const
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}
	T_data Find(int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i)return current->value;
			current = current->next;
			i++;
		}
		return 0;
	}
	void DelPoss(int pos)
	{
		if (pos == 1)
		{
			DeleteFromHead();
		}
		else
		{
			Node* current = head;
			for (int i = 1; i < pos - 1; i++)
			{
				current = current->next;
			}
			Node* del = current->next;
			current->next = del->next;
			delete del;
		}
	}
	void AddPos(T_data value, int pos)
	{
		if (pos == 1)
		{
			AddToHead(value);
		}
		else
		{
			Node* current = head;
			for (int i = 1; i < pos - 1; i++)
			{
				current = current->next;
			}
			Node* newNode = new Node(value, current->next);
			current->next = newNode;
		}
	}
	void DeleteAll()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	~List()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};


int main()
{
	List<int> list;
	int key;
	int n;
	int p;
	bool k = true;
	while (true)
	{
		cout << "\t_________MENU__________" << endl;
		cout << "\tAdd to head:        [1]" << endl;
		cout << "\tDelete from head:   [2]" << endl;
		cout << "\tAdd to tail:        [3]" << endl;
		cout << "\tDelete from tail:   [4]" << endl;
		cout << "\tDelete all:         [5]" << endl;
		cout << "\tShow:               [6]" << endl;
		cout << "\tFind                [7]" << endl;
		cout << "\tAdd by position:    [8]" << endl;
		cout << "\tDelete by position: [9]" << endl;
		cin >> key;
		switch (key)
		{
		case 1:
			system("cls");
			cout << " Enter number: ";
			cin >> n;
			list.AddToHead(n);
			list.Show();
			break;
		case 2:
			system("cls");
			list.DeleteFromHead();
			list.Show();
			break;
		case 3:
			system("cls");
			cout << " Enter number: ";
			cin >> n;
			list.AddToTail(n);
			list.Show();
			break;
		case 4:
			system("cls");
			list.DeleteFromTail();
			list.Show();
			break;
		case 5:
			list.DeleteAll();
			break;
		case 6:
			system("cls");
			list.Show();
			break;
		case 7:
			system("cls");
			cout << " Enter possition: ";
			cin >> p;
			cout << " On possition " << p << " : " << list.Find(p) << endl;
			break;
		case 8:
			system("cls");
			cout << " Enter number: ";
			cin >> n;
			cout << " Enter possition: ";
			cin >> p;
			list.AddPos(n, p);
			list.Show();
			break;
		case 9:
			system("cls");
			cout << " Enter possition: ";
			cin >> p;
			list.DelPoss(p);
			list.Show();
			break;
		default:
			break;
		}
	}

}

