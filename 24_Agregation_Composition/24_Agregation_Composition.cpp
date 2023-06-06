#include <iostream>
using namespace std;
class Driver
{
private:
	string name;
	string surname;
	int age;
	int experience;
public:
	Driver() :name("none"), surname("none"), age(0), experience(0) {}
	Driver(string name, string surname, int age, int experience) :name(name), surname(surname), age(age), experience(experience) {}
	void Info()const
	{
		cout << "_________DRIVER_________" << endl;
		cout << " Name: " << name << endl;
		cout << " Surname: " << surname << endl;
		cout << " Age: " << age << endl;
		cout << " Experience age: " << experience << endl;
	}
};
class Body
{
private:
	string type;
	string color;
public:
	Body() :type("none"), color("none") {}
	Body(string type, string color) :type(type), color(color) {}
	void Info()const
	{
		cout << "_________BODY___________" << endl;
		cout << " Type: " << type << endl;
		cout << " Color: " << color << endl;
	}
};
class Wheel
{
private:
	string size;
	string type;
public:
	Wheel() :size("none"), type("none") {}
	Wheel(string size, string type) :size(size), type(type) {}
	void Info()const
	{
		cout << "_________WHEEL__________" << endl;
		cout << " Size: " << size << endl;
		cout << " Type: " << type << endl;;
	}
};
class Engine
{
private:
	string type;
	float value;
public:
	Engine() :type("none"), value(0) {}
	Engine(string type, float value) :type(type), value(value) {}
	void Info()const
	{
		cout << "_________ENGINE_________" << endl;
		cout << " Type: " << type << endl;
		cout << " Volue: " << value << endl;
	}

};
class Door
{
private:
	string color;
	string type;
public:
	Door() :color("none"), type("none") {}
	Door(string color, string type) :color(color), type(type) {}
	void Info()const
	{
		cout << "_________DOOR___________" << endl;
		cout << " Color: " << color << endl;
		cout << " Type: " << type << endl;
	}
};
class Headlight
{
private:
	string type;
	string color;
public:
	Headlight() :type("none"), color("none") {}
	Headlight(string type, string color) :type(type), color(color) {}
	void Info()const
	{
		cout << "_________HEAD_LIGHT_____" << endl;
		cout << " Type: " << type << endl;
		cout << " Color: " << color << endl;
	}
};

class Car
{
private:
	string model;
	Body body;
	int countwheel;
	Wheel* wheel;
	Engine engine;
	int countdoor;
	Door* door;
	int countlight;
	Headlight* headlight;
	const Driver* tdriver;
public:
	Car(string model)
	{
		this->model = model;
		body = Body("univergal", "black");
		countwheel = 4;
		wheel = new Wheel[countwheel];
		wheel[0] = Wheel("18", "summer");
		wheel[1] = Wheel("18", "summer");
		wheel[2] = Wheel("18", "summer");
		wheel[3] = Wheel("18", "summer");
		engine = Engine("turbo", 110);
		countdoor = 4;
		door = new Door[countdoor];
		door[0] = Door("black", "vertical");
		door[1] = Door("black", "vertical");
		door[2] = Door("black", "vertical");
		door[3] = Door("black", "vertical");
		countlight = 2;
		headlight = new Headlight[countlight];
		headlight[0] = Headlight("round", "white");
		headlight[1] = Headlight("round", "white");
	}
	void Adddriber(Driver& driver)
	{
		tdriver = &driver;
	}
	void Info()
	{
		if (tdriver == nullptr)
		{
			cout << "No driver present!" << endl;
		}
		else
		{
			cout << "++++++++++++++++++++++++" << endl;
			cout << "+++++++++" << model << "+++++++" << endl;
			cout << "++++++++++++++++++++++++" << endl;
			tdriver->Info();
			body.Info();
			engine.Info();
			for (int i = 0; i < countwheel; i++)
			{
				wheel[i].Info();
			}
			for (int i = 0; i < countdoor; i++)
			{
				door[i].Info();
			}
			for (int i = 0; i < countlight; i++)
			{
				headlight[i].Info();
			}
		}
	}
	~Car()
	{
		if (wheel != nullptr)
			delete[]wheel;
		if (door != nullptr)
			delete[]door;
		if (headlight != nullptr)
			delete[]headlight;
	}
};


int main()
{
	Driver driver("Tatas", "Shevchuck", 28, 3);
	Car car("Mazarati");
	car.Adddriber(driver);
	car.Info();
}