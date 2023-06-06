#include <iostream>
using namespace std;
template <typename T_arr>
class Array
{
private:
	int size;
	T_arr* arr;
public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	Array(int size)
	{
		this->size = size;
		arr = new T_arr[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	Array(const initializer_list<T_arr>& list)
	{
		this->size = list.size();
		arr = new T_arr[size];
		int i = 0;
		for (T_arr element : list)
		{
			arr[i++] = element;
		}
	}
	void fill(const initializer_list<int>& list)
	{
		if (arr != nullptr)delete[]arr;
		this->size = list.size();
		arr = new T_arr[size];
		int i = 0;
		for (T_arr element : list)
		{
			arr[i++] = element;
		}
	}
	void print()const
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void bubblesort();
	T_arr min();
	T_arr max();
	void bisearch(T_arr elem);
	void setelement(T_arr a, int index);
	~Array()
	{
		if (arr != nullptr)
			delete[]arr;
	}
};
template<typename T_arr>
void Array<T_arr>::bubblesort()
{
	T_arr temp;
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
template<typename T_arr>
T_arr Array<T_arr>::min()
{
	T_arr min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
template<typename T_arr>
T_arr Array<T_arr>::max()
{
	T_arr max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
template<typename T_arr>
void Array<T_arr>::setelement(T_arr a, int index)
{
	arr[index] = a;
}
template<typename T_arr>
void Array<T_arr>::bisearch(T_arr elem)
{
	int l = 0;
	int r = size - 1;
	int m;
	do
	{
		m = r - ((r - l) / 2);

		if (arr[m] < elem)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	} while ((l <= r) && (arr[m] != elem));
	cout << " This is an element with an index " << m << endl;
	cout << " The place of the element is " << m + 1 << endl;
	cout << " Your element is " << arr[m] << endl;
}

void main()
{
	Array<int> arr({ 1,2,3,4,5 });
	arr.print();
	arr.fill({ 5,4,3,2,1 });
	arr.print();
	arr.bubblesort();
	arr.print();
	cout << " Min: " << arr.min() << endl;
	cout << " Max: " << arr.max() << endl;
	arr.setelement(6, 0);
	arr.print();
	arr.bubblesort();
	arr.print();
	arr.bisearch(5);
}

