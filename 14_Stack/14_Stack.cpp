#include <iostream>
#include<string>
using namespace std;
template <typename T_arr>
class Stack
{
	enum { EMPTY = -1 };
	int size;
	T_arr* arr;
	int top;
public:
	Stack() = delete;
	Stack(int size) :size(size)
	{
		arr = new T_arr[size];
		top = EMPTY;
	}
	bool IsFull()const
	{
		return top == size - 1;
	}
	bool Push(T_arr elem)
	{
		if (!IsFull())
		{
			arr[++top] = elem;
			return true;
		}
		return false;
	}
	bool IsEmpty()const
	{
		return top == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty())
			return  arr[top--];
		return 0;
	}
	void Clear()
	{
		top = EMPTY;
	}
	int Peek()const
	{
		if (!IsEmpty())
			return arr[top];
		return 0;
	}
	int GetCount()const
	{
		return top + 1;
	}
	void Print()const
	{
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	~Stack()
	{
		if (arr != nullptr)
			delete[]arr;
	}
};

bool isValid(string code)
{
	Stack<char>st1(10);
	Stack<char>st2(10);
	Stack<char>st3(10);
	for (char symbol : code)
	{
		if (symbol == '{')
		{
			st1.Push(symbol);
		}
		if (symbol == '}')
		{
			if (st1.IsEmpty())return false;
			st1.Pop();
		}
		if (symbol == '[')
		{
			st2.Push(symbol);
		}
		if (symbol == ']')
		{
			if (st2.IsEmpty())return false;
			st2.Pop();
		}
		if (symbol == '(')
		{
			st3.Push(symbol);
		}
		if (symbol == ')')
		{
			if (st3.IsEmpty())return false;
			st3.Pop();
		}
	}
	if (st1.IsEmpty() == true && st2.IsEmpty() == true && st3.IsEmpty() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void showinvalid(string code)
{
	Stack<char>st1(10);
	Stack<char>st2(10);
	Stack<char>st3(10);
	for (char symbol : code)
	{
		if (symbol == '{')
		{
			st1.Push(symbol);
			cout << symbol;
		}
		if (symbol == '}')
		{
			if (st1.IsEmpty())break;
			st1.Pop();
		}
		if (symbol == '[')
		{
			st2.Push(symbol);
			cout << symbol;
		}
		if (symbol == ']')
		{
			if (st2.IsEmpty())break;
			st2.Pop();
		}
		if (symbol == '(')
		{
			st3.Push(symbol);
			cout << symbol;
		}
		if (symbol == ')')
		{
			if (st3.IsEmpty())break;
			st3.Pop();
		}
		if (symbol != '{' && symbol != '}' && symbol != '(' && symbol != ')' && symbol != '[' && symbol != ']')
		{
			cout << symbol;
		}
	}
}

int main()
{
	Stack<int>stack(10);
	for (int i = 0; i < 10; i++)
	{
		stack.Push(i);
	}
	stack.Print();

	string code = "([x-y-z} * [x + 2y) - {z + 4x)]";
	if (isValid(code))
	{
		cout << "Code is valid" << endl;
	}
	else
	{
		cout << "Code is invalid" << endl;
		showinvalid(code);
		cout << endl;
	}
}
