#include <iostream>
#include <ctime>
using namespace std;

class Array
{
private:
	int size;
	int* arr;
public:
	Array()
	{
		size = 5;
		arr = new int[size];
		int k = 0;
		for (int i = 0; i < size; i++)
		{
			arr[i] = ++k;
		}
	}
	Array(int size)
	{
		if (size > 0)
		{
			this->size = size;
			this->arr = new int[size];
			for (int i = 0; i < size; i++)
			{
				arr[i] = 0;
			}
		}
	}
	Array(const Array& other)
	{
		this->size = other.size;
		this->arr = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	int getsize()const
	{
		return size;
	}
	int getvalue(int index)const
	{
		return arr[index];
	}
	void setvalue(int num, int index)
	{
		arr[index] = num;
	}
	void display(int index)const
	{
		cout << arr[index] << " ";
	}
	void randinit()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 80 + 10;
		}
	}
	void keyboardinit()
	{
		for (int i = 0; i < size; i++)
		{
			cout << " Enter number " << i + 1 << ": ";
			cin >> arr[i];
		}
	}
	void definit()
	{
		int k = 0;
		for (int i = 0; i < size; i++)
		{
			arr[i] = ++k;
		}
	}
	void show()const
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void addnumber(int num)
	{
		size++;
		int* temp = new int[size];
		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = arr[i];
		}
		temp[size - 1] = num;
		arr = temp;
	}
	void deletenumber(int index)
	{
		if (index > 0 && index <= size)
		{
			size--;
			int* temp = new int[size];
			for (int i = 0; i < index - 1; i++)
			{
				temp[i] = arr[i];
			}
			for (int i = index; i < size + 1; i++)
			{
				temp[i - 1] = arr[i];
			}
			arr = temp;
		}
	}
	void bubblesortzrost()
	{
		int temp;
		for (int i = 0; i < size; i++)
		{
			for (int j = size - 1; j > i; j--)
			{
				if (arr[j - 1] > arr[j])
				{
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	void bubblesortzspad()
	{
		int temp;
		for (int i = 0; i < size; i++)
		{
			for (int j = size - 1; j > i; j--)
			{
				if (arr[j - 1] < arr[j]) {
					temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	int min()const
	{
		int min = arr[0];
		for (int i = 0; i < size; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		return min;
	}
	int max()const
	{
		int max = arr[0];
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
	}
	double mean()
	{
		double sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum = sum + arr[i];
		}
		return sum / size;

	}
	~Array()

	{
		if (arr != nullptr)
		{
			delete[]arr;
		}
	}
};
void main()
{
	Array Arr;
	Arr.definit();
	Arr.show();
	Arr.randinit();
	Arr.show();
	Arr.addnumber(13);
	Arr.show();
	Arr.deletenumber(3);
	Arr.show();
	Arr.bubblesortzrost();
	Arr.show();
	Arr.bubblesortzspad();
	Arr.show();
	cout << " Min: " << Arr.min() << endl;
	cout << " Max: " << Arr.max() << endl;
	cout << " Arifmetic mean: " << Arr.mean() << endl;
	Array ARR(Arr);
	ARR.show();
}
