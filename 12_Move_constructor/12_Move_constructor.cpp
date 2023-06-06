#include <iostream>
#include<windows.h>
using namespace std;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Point
{
private:
	int x;
	int y;
public:
	Point()
	{
		x = y = 0;
	}
	Point(int value)
	{
		x = y = value;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	Point operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
	void Show()const
	{
		cout << " X : " << x << " Y : " << y << endl;
	}
	Point operator !()
	{
		return Point(-x, -y);
	}
	Point operator++()
	{
		++this->x;
		++this->y;
		return *this;
	}
	Point operator--()
	{
		--this->x;
		--this->y;
		return *this;
	}
	Point operator++(int)
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator--(int)
	{
		this->x--;
		this->y--;
		return *this;
	}
	int getX()const
	{
		return x;
	}
	int getY()const
	{
		return y;
	}
	friend bool operator < (const Point& left, const Point& other);
	friend bool operator > (const Point& left, const Point& other);
	friend ostream& operator <<(ostream& out, const Point& point);
	friend istream& operator >>(istream& in, Point& point);
};
bool operator < (const Point& left, const Point& right)
{
	return(left.x * left.x + left.y * left.y) < (right.x * right.x + right.y * right.y);
}
bool operator > (const Point& left, const Point& right)
{
	return(left.x * left.x + left.y * left.y) > (right.x * right.x + right.y * right.y);
}
ostream& operator <<(ostream& out, const Point& point)
{
	out << " X : " << point.x << " Y : " << point.y << endl;
	return out;
}
istream& operator >>(istream& in, Point& point)
{
	in >> point.x;
	in.ignore(1);
	in >> point.y;
	return in;
}

class Vector
{
private:
	Point* points;
	int size;
public:
	Vector() :size(0), points(nullptr) {}
	Vector(const Vector& other)
	{
		this->size = other.size;
		this->points = new Point[other.size];
		for (int i = 0; i < other.size; i++)
		{
			points[i] = other.points[i];
		}
	}
	Vector(Vector&& other)
	{
		this->size = other.size;
		this->points = other.points;
		other.points = nullptr;
	}
	Vector operator = (const Vector& other)
	{
		this->size = other.size;
		if (points != nullptr)
			delete[]points;
		this->points = new Point[other.size];
		for (int i = 0; i < size; i++)
		{
			this->points[i] = other.points[i];
		}
		return *this;
	}
	void addpoint(Point p)
	{
		size++;
		Point* temp = new Point[size];
		for (int i = 0; i < size - 1; i++)
		{
			temp[i] = points[i];
		}
		temp[size - 1] = p;
		if (points != nullptr)
			delete[]points;
		points = temp;
	}
	void print()
	{
		cout << "::::::::::::::::::::::::::::::::::::" << endl;
		cout << "Count of point : " << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "_______________________" << endl;
			cout << " Number: " << i + 1 << endl;
			points[i].Show();
		}
	}
	void show()
	{
		cout << " Want to see dots on the screen? (1-y/2-n)" << endl;
		cout << " Your choise: ";
		int key;
		int k = 0;
		cin >> key;
		switch (key)
		{
		case 1:
			system("cls");

			for (int i = 0; i < 20; i++)
			{
				gotoxy(20, k);
				cout << (char)179;
				k++;
			}
			k = 0;
			for (int i = 0; i < 40; i++)
			{
				gotoxy(k, 10);
				cout << (char)196;
				k++;
			}
			gotoxy(20, 10);
			cout << (char)197;
			for (int i = 0; i < size; i++)
			{
				gotoxy(points[i].getX() + 20, 10 - points[i].getY());
				cout << (char)43;
			}
			break;
		case 2:
			cout << "ok";
			break;
		default:
			break;
		}
	}
	~Vector()
	{
		if (points != nullptr)
			delete[]points;
	}
};

int main()
{
	Point p1(8, 4);
	Point p2(3, 2);
	cout << " p1 : "; p1.Show();
	cout << " p2 : "; p2.Show();
	++p1;
	cout << " p1 : "; p1.Show();
	--p2;
	cout << " p2 : "; p2.Show();
	p1++;
	cout << " p1 : "; p1.Show();
	p2--;
	cout << " p2 : "; p2.Show();
	p1 = !p1;
	cout << " p1 : "; p1.Show();
	p2 = !p2;
	cout << " p2 : "; p2.Show();
	p1 = !p1;
	cout << " p1 : "; p1.Show();
	p2 = !p2;
	cout << " p2 : "; p2.Show();
	if (p1 > p2)
	{
		cout << " Point P1 further (0;0)!" << endl;
	}
	else
	{
		cout << " Point P2 further (0;0)!" << endl;
	}
	if (p1 < p2)
	{
		cout << " Point P1 neighbor (0;0)!" << endl;
	}
	else
	{
		cout << " Point P2 neighbor (0;0)!" << endl;
	}

	Point P1(4, -4);
	Point P2(-4, 4);
	Point P3(-4, -4);
	Point P4(4, 4);
	Vector v1;
	v1.addpoint(P1);
	v1.addpoint(P2);
	v1.addpoint(P3);
	v1.addpoint(P4);
	v1.print();
	v1.show();
	Vector v2 = v1;
	gotoxy(0, 30);
}
