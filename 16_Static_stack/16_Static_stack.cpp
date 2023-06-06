#include <iostream>
using namespace std;

class Stack
{
	enum { EMPTY = -1, FULL = 9 };
	char data[FULL + 1];
	int topIndex;
public:
	Stack()
	{
		topIndex = EMPTY;
	}
	~Stack() = default;
	bool IsFull()const
	{
		return topIndex == FULL;
	}
	bool Push(char element)
	{
		if (!IsFull())
		{
			data[++topIndex] = element;
			return true;
		}
		return false;
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
	Stack st;
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
	cout << "Count : " << st.GetCount() << endl;
	cout << "Element : " << st.Pop() << endl;
	cout << "Count : " << st.GetCount() << endl;
	cout << st.Peek() << endl;
	st.Clear();
	cout << "Count : " << st.GetCount() << endl;
}