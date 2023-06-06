#include <iostream>
using namespace std;

class Stack
{
	enum { EMPTY = -1 };
	int size;
	char* data;
	int topIndex;
public:
	Stack() = delete;
	Stack(int size) :size(size)
	{
		data = new char[size];
		topIndex = EMPTY;
	}
	~Stack()
	{
		delete[]data;
	}
	bool IsFull()const
	{
		return topIndex == size - 1;
	}
	bool Push(char element)
	{
		if (!IsFull())
		{
			data[++topIndex] = element;
			return true;
		}
		else
		{
			char* temp = new char[size];
			int top = EMPTY;
			for (int i = 0; i < size; i++)
			{
				temp[++top] = data[topIndex--];
			}
			delete[]data;
			data = new char[++size];
			topIndex = EMPTY;
			for (int i = 0; i < size - 1; i++)
			{
				data[++topIndex] = temp[top--];
			}
			data[++topIndex] = element;
			delete[]temp;
			return true;
		}

	}
	bool IsEmpty()const
	{
		return topIndex == EMPTY;
	}
	char Pop()
	{
		if (!IsEmpty())
			return data[topIndex--];
		return 0;
	}
	char Peek()
	{
		if (!IsEmpty())
			return data[topIndex];
		return 0;
	}
	int GetCount()const
	{
		return topIndex + 1;
	}
	void Clear()
	{
		topIndex = EMPTY;
	}
};
int main()
{
	Stack st(10);
	st.Push('a');
	st.Push('b');
	st.Push('c');
	st.Push('d');
	st.Push('e');
	st.Push('f');
	st.Push('g');
	st.Push('j');
	st.Push('k');
	st.Push('l');
	st.Push('m');
	st.Push('n');
	cout << "Count : " << st.GetCount() << endl;
	cout << "Element : " << st.Pop() << endl;
	cout << "Count : " << st.GetCount() << endl;
	cout << st.Peek() << endl;
	st.Clear();
	cout << "Count : " << st.GetCount() << endl;
}