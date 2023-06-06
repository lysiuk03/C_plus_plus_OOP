#include <iostream>
using namespace std;

template<typename T_data>
class List
{
	struct Node
	{
		T_data value;
		Node* prev;
		Node* next;
		Node(T_data value, Node* prev, Node* next) :value(value), prev(prev), next(next) {	}
	};
	Node* head;
	Node* tail;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	bool IsEmpty()const
	{
		return head == nullptr;
	}
	void AddToHead(T_data value)
	{
		Node* newNode = new Node(value, nullptr, head);
		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			head = newNode;
		}

	}
	void DeleteFromHead()
	{
		if (IsEmpty())return;
		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
			return;
		}
		Node* temp = head;
		head = head->next;
		delete[]temp;
	}
	void AddToTail(T_data value)
	{

		Node* newNode = new Node(value, tail, nullptr);
		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}
	void DeleteFromTail()
	{
		if (IsEmpty())return;
		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
			return;
		}
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}
	void DeletePoss(int pos, int count)
	{
		if (pos == 1 || pos == count)
		{
			if (pos == 1)
			{
				DeleteFromHead();
			}
			else
			{
				DeleteFromTail();
			}
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
	void AddPoss(int pos, T_data value, int count)
	{

		if (pos == 1 || pos == count + 1)
		{
			if (pos == 1)
			{
				AddToHead(value);
			}
			else
			{
				AddToTail(value);
			}
		}
		else
		{
			Node* current = head;
			for (int i = 1; i < pos - 1; i++)
			{
				current = current->next;
			}
			Node* newNode = new Node(value, current->prev, current->next);
			current->next = newNode;
		}
	}
	void PrintList()const
	{
		for (Node* current = head; current != nullptr; current = current->next)
		{
			cout << current->value << " ";
			cout << endl;
		}
		cout << endl;
	}
	List(const List& other)
	{
		for (Node* current = other.head; current != nullptr; current = current->next)
		{
			this->AddToTail(current->value);
		}
	}
	void Clear()
	{
		while (head != nullptr)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	List& operator =(const List& other)
	{
		Clear();
		for (Node* current = other.head; current != nullptr; current = current->next)
		{
			this->AddToTail(current->value);
		}
		return *this;
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
struct Vagon
{
	int number;
	int mist;
	int pasangers;
	Vagon() :number(0), mist(0), pasangers(0) {};
	Vagon(int n, int p) :number(n), mist(p), pasangers(0) {};
	void Show()const
	{
		cout << "Number vagon : " << number << endl;
		cout << "Count places : " << mist << endl;
		cout << "Count passangers : " << pasangers << endl;
	}
};
ostream& operator <<(ostream& out, const Vagon& v)
{
	out << "Number vagon : " << v.number << endl;
	out << "Count places : " << v.mist << endl;
	out << "Count passangers : " << v.pasangers << endl;
	return out;
}
class Train
{
	string model;
	int count;
	List<Vagon> vagon;
public:
	Train()
	{
		model = " ";
		count = 0;
	}
	Train(string model)
	{
		this->model = model;
		count = 0;
	}
	Train(const Train& other) :vagon(other.vagon)
	{
		this->model = other.model;
		this->count = other.count;
		this->vagon = other.vagon;
	}
	void AddVagonToTail(Vagon v)
	{
		vagon.AddToTail(v);
		count++;
	}
	void AddVagonToHead(Vagon v)
	{
		vagon.AddToHead(v);
		count++;
	}
	void DeleteVagonFromTail()
	{
		vagon.DeleteFromTail();
		count--;
	}
	void DeleteVagonFromHead()
	{
		vagon.DeleteFromHead();
		count--;
	}
	void DeleteVagonPoss(int pos)
	{
		vagon.DeletePoss(pos, count);
		count--;
	}
	void AddVagonPoss(int pos, Vagon v)
	{
		vagon.AddPoss(pos, v, count);
		count++;
	}
	void Print()
	{
		cout << "- - - - - - Train [ " << model << " ]- - - -" << endl;
		cout << " Count vagons : " << count << endl;
		vagon.PrintList();
	}
};
int main()
{
	Train train("Tomas");
	train.AddVagonToTail(Vagon(5, 5));
	train.AddVagonToTail(Vagon(6, 40));
	train.AddVagonToTail(Vagon(7, 15));
	train.AddVagonToTail(Vagon(8, 10));
	train.AddVagonToHead(Vagon(4, 30));
	train.AddVagonToHead(Vagon(3, 40));
	train.AddVagonToHead(Vagon(2, 10));
	train.AddVagonToHead(Vagon(1, 35));
	train.Print();
	cout << "_______________________________" << endl;
	cout << "*******************************" << endl;
	train.DeleteVagonFromTail();
	train.DeleteVagonFromTail();
	train.DeleteVagonFromTail();
	train.Print();
	cout << "_______________________________" << endl;
	cout << "*******************************" << endl;
	train.DeleteVagonFromHead();
	train.DeleteVagonFromHead();
	train.DeleteVagonFromHead();
	train.DeleteVagonFromHead();
	train.Print();
	cout << "_______________________________" << endl;
	cout << "*******************************" << endl;
	train.DeleteVagonFromHead();
	train.Print();
	cout << "_______________________________" << endl;
	cout << "*******************************" << endl;
	train.AddVagonToTail(Vagon(5, 5));
	train.AddVagonToTail(Vagon(6, 40));
	train.AddVagonToTail(Vagon(7, 15));
	train.AddVagonToTail(Vagon(8, 10));
	train.AddVagonToHead(Vagon(4, 30));
	train.AddVagonToHead(Vagon(3, 40));
	train.AddVagonToHead(Vagon(2, 10));
	train.AddVagonToHead(Vagon(1, 35));
	train.Print();
	cout << "_______________________________" << endl;
	cout << "*******************************" << endl;
	train.DeleteVagonPoss(8);
	train.DeleteVagonPoss(5);
	train.DeleteVagonPoss(1);
	train.Print();
	cout << "_______________________________" << endl;
	cout << "*******************************" << endl;
	train.AddVagonPoss(1, { 1 ,20 });
	train.AddVagonPoss(5, { 5 ,20 });
	train.AddVagonPoss(8, { 8 ,20 });
	train.Print();
}