#include <iostream>

using namespace std;

struct Vagon
{
	int number;
	int mist;
	int pasangers;
	Vagon() :number(0), mist(0), pasangers(0) {};
	Vagon(int n, int p) :number(n), mist(p), pasangers(0) {};
};

class Train
{
	string model;
	int count;
	Vagon* vagon;

public:
	Train()
	{
		model = " ";
		count = 0;
		vagon = nullptr;
	}
	Train(string model)
	{
		this->model = model;
		count = 0;
		vagon = nullptr;
	}
	void AddVagon(int number, int mist)
	{
		count++;
		Vagon* temp = new Vagon[count];
		for (int i = 0; i < count - 1; i++)
		{
			temp[i] = vagon[i];
		}
		temp[count - 1] = Vagon(number, mist);
		delete[] vagon;
		vagon = temp;
	}
	void print()
	{
		cout << "----------train [" << model << "]----------" << endl;
		cout << " Count vagons: " << count << endl;
		for (int i = 0; i < count; i++)
		{
			cout << " Number vagon: " << vagon[i].number << endl;
			cout << " Count places: " << vagon[i].mist << endl;
			cout << " Count passangers:" << vagon[i].pasangers << endl;
		}
	}
	void addpass(int number)
	{
		for (int i = 0; i < count; i++)
		{
			this->vagon[i].pasangers++;
		}
	}
	~Train()
	{
		delete[]vagon;
	}
	Train(const Train& other)
	{
		this->model = other.model;
		this->count = other.count;
		this->vagon = new Vagon[other.count];
		for (int i = 0; i < other.count; i++)
		{
			vagon[i] = other.vagon[i];
		}
	}
};

int main()
{
	Train train("Tomas");
	train.AddVagon(1, 30);
	train.AddVagon(2, 20);
	train.AddVagon(3, 10);
	train.print();
	train.addpass(1);
	train.addpass(1);
	train.addpass(1);
	train.addpass(1);
	train.addpass(1);
	train.addpass(2);
	train.addpass(3);
	train.addpass(3);
	train.addpass(3);
	train.print();
	Train newTrain = train;
	newTrain.addpass(1);
	newTrain.addpass(1);
	newTrain.addpass(1);
	newTrain.addpass(2);
	newTrain.addpass(2);
	newTrain.addpass(3);
	newTrain.print();
}