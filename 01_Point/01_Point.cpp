# include <iostream>
#include<fstream>
using namespace std;

class point
{
private:
	int x;
	int y;
	int z;
public:

	void init()
	{
		cout << " X: ";
		cin >> x;
		cout << " Y: ";
		cin >> y;
		cout << " Z: ";
		cin >> z;
	}

	void show()
	{
		cout << " X: " << x << endl;
		cout << " Y: " << y << endl;
		cout << " Z: " << z << endl;
	}

	void setx(int X)
	{
		x = X;
	}
	void sety(int Y)
	{
		y = Y;
	}
	void setz(int Z)
	{
		z = Z;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	int getz()
	{
		return z;
	}
	void savetofile()
	{
		ofstream out("point.txt");
		out << x;
		out << ':';
		out << y;
		out << ':';
		out << z;
		out << '|';
		out.close();
	}
	void readfromfile()
	{
		ifstream in("point.txt");
		char buffx[10], buffy[10], buffz[10];
		in.getline(buffx, 10, ':');
		in.getline(buffy, 10, ':');
		in.getline(buffz, 10, '|');
		this->x = atoi(buffx);
		this->y = atoi(buffy);
		this->z = atoi(buffz);
		in.close();
	}

};

void main()
{
	point dot;
	dot.init();
	dot.savetofile();
	cout << "--------" << endl;
	dot.readfromfile();
	dot.show();
}
