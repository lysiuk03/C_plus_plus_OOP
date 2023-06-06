#include<windows.h>
#include <iomanip>
#include <iostream>
using namespace std;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct coords
{
	int x;
	int y;
};
class Rectangles
{
private:
	int width;
	int height;
	char symbol;
	coords coordinates;
public:
	Rectangles()
	{
		width = 0;
		height = 0;
		symbol = ' ';
		coordinates = { 0,0 };
	}
	Rectangles(int size)
	{
		width = size;
		height = size;
		symbol = ' ';
		coordinates = { 0,0 };
	}
	Rectangles(int width, int height)
	{
		this->width = width;
		this->height = height;
		symbol = ' ';
		coordinates = { 0,0 };
	}
	void show(int width, int heigt, char symbol, coords coordinates)
	{
		if (width > 0 && heigt > 0 && symbol != ' ' && coordinates.x > 0 && coordinates.y > 0)
		{
			for (int i = 0; i < heigt; i++)
			{
				gotoxy(coordinates.x, coordinates.y);
				for (int i = 0; i < width; i++)
				{
					cout<< symbol <<  " ";
				}
				coordinates.y++;
			}
		}
	}

	void setedit(int width, int height)
	{
		if (width > 0 && height > 0)
		{
			this->width = width;
			this->height = height;
		}
	}
	int getwidth()
	{
		return width;
	}
	int getheight()
	{
		return height;
	}
	void setmoving(int x, int y)
	{
		if (x > 0 && y > 0)
		{
			coordinates.x = x;
			coordinates.y = y;
		}

	}
	int getx()
	{
		return coordinates.x;
	}
	int gety()
	{
		return coordinates.y;
	}

};
void main()
{
	Rectangles quadrangle;
	quadrangle.show(10, 5, '*', { -3,5 });
	quadrangle.setedit(6, 4);
	quadrangle.show(quadrangle.getwidth(), quadrangle.getheight(), '*', { 25,5 });
	quadrangle.setmoving(40, 5);
	quadrangle.show(quadrangle.getwidth(), quadrangle.getheight(), '*', { quadrangle.getx(),quadrangle.gety() });

}