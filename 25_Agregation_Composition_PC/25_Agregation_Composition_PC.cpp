#include <iostream>
using namespace std;
class Administrator
{
	string name;
	string password;
public:
	Administrator() :name("none"), password("none") {}
	Administrator(string name, string password) :name(name), password(password) {}
	void Info()const
	{
		cout << "________ADMINISTRATOR______" << endl;
		cout << " Name: " << name << endl;
		cout << " Password: " << password << endl;
		cout << " I can change security settings,\n install software and hardware,\n work with all the files on my computer,\n and change other users' accounts." << endl;
	}
};
class Guest
{
	string name;
	string password;
public:
	Guest() :name("none"), password("none") {}
	Guest(string name, string password) :name(name), password(password) {}
	void Info()const
	{
		cout << "________GUEST______" << endl;
		cout << " Name: " << name << endl;
		cout << " Password: " << password << endl;
	}
};
class Display
{
private:
	string name;
	string type;
	float size;
public:
	Display() :name("none"), type("none"), size(0) {}
	Display(string name, string type, float size) :name(name), type(type), size(size) {}
	void Info()const
	{
		cout << "__________DISPLAY__________" << endl;
		cout << " Name: " << name << endl;
		cout << " Type: " << type << endl;
		cout << " Size: " << size << "''" << endl;
	}
};
class  CPU
{
private:
	string model;
	int core;
public:
	CPU() :model("none"), core(0) {}
	CPU(string model, int core) :model(model), core(core) {}
	void Info()const
	{
		cout << "__________CPU__________" << endl;
		cout << " Model: " << model << endl;
		cout << " " << core << " core" << endl;
	}
};
class RAM
{
private:
	string model;
	int value;
public:
	RAM() :value(0), model("none") {}
	RAM(int value, string model) :value(value), model(model) {}
	void Info()const
	{
		cout << "__________RAM__________" << endl;
		cout << " Model: " << model << endl;
		cout << " Value: " << value << " GB" << endl;
	}

};
class SSD
{
private:
	string model;
	int value;
public:
	SSD() :model("none", 0) {}
	SSD(string model, int value) :model(model), value(value) {}
	void Info()const
	{
		cout << "__________SSD__________" << endl;
		cout << " Model: " << model << endl;
		cout << " Value: " << value << " GB" << endl;
	}
};
class Motherboard
{
private:
	string model;
	string socket;
	string form_factor;
public:
	Motherboard() :model("none"), socket("none"), form_factor("none") {}
	Motherboard(string model, string socket, string form_factor) :model(model), socket(socket), form_factor(form_factor) {}
	void Info()const
	{
		cout << "________MOTHERBOARD____" << endl;
		cout << " Model: " << model << endl;
		cout << " Socket: " << socket << endl;
		cout << " Form_factor: " << form_factor << endl;
	}
};
class Videocard
{
private:
	string model;
	string graphics_chip;
	int memory;
public:
	Videocard() :model("none"), graphics_chip("none"), memory(0) {}
	Videocard(string model, string graphics_chip, int memory) :model(model), graphics_chip(graphics_chip), memory(memory) {}
	void Info()const
	{
		cout << "_________VIDEOCARD_____" << endl;
		cout << " Model: " << model << endl;
		cout << " Graphics chip: " << graphics_chip << endl;
		cout << " Memory: " << memory << " GB" << endl;
	}
};
class Power_supply
{
private:
	string model;
	int power;
public:
	Power_supply() :model("none"), power(0) {}
	Power_supply(string model, int power) :model(model), power(power) {}
	void Info()const
	{
		cout << "______POWER_SUPPLY_____" << endl;
		cout << " Model: " << model << endl;
		cout << " Power: " << power << " Vt" << endl;
	}
};
class  Keyboard
{
private:
	string type;
	int size;
	string model;
public:
	Keyboard() :type("none"), size(0), model("none") {}
	Keyboard(string type, int size, string model) :type(type), size(size), model(model) {}
	void Info()const
	{
		cout << "________KEYBOARD_______" << endl;
		cout << " Model: " << model << endl;
		cout << " Type: " << type << endl;
		cout << " Size: " << size << endl;
	}
};
class Mouse
{
private:
	string model;
	string sensor;
	string connection;
public:
	Mouse() :model("none"), sensor("none"), connection("none") {}
	Mouse(string model, string sensor, string connection) :model(model), sensor(sensor), connection(connection) {}
	void Info()const
	{
		cout << "__________MOUSE________" << endl;
		cout << " Model: " << model << endl;
		cout << " Sensor: " << sensor << endl;
		cout << " Connection: " << connection << endl;
	}
};

class PC
{
private:
	const Administrator* admin;
	const Guest* guest;
	string name;
	Display display;
	CPU cpu;
	RAM ram;
	SSD ssd;
	Motherboard motherboard;
	Videocard videocard;
	Power_supply power_supply;
	Keyboard keyboard;
	Mouse mouse;
public:
	PC(string name) :name(name)
	{
		display = Display("Samsung Odyssey G5", "frameless", 27);
		cpu = CPU("Intel Core i9", 16);
		ram = RAM(64, "SK Hynix");
		ssd = SSD("Western Digital ", 512);
		motherboard = Motherboard("Asus Prime H510M-K", "1200", "MicroATX");
		videocard = Videocard("MSI GEFORCE RTX3060", "GeForce RTX 3060", 16);
		power_supply = Power_supply("Asus / Chicony Electronics", 500);
		keyboard = Keyboard("wireless", 101, "Samsung Smart Keyboard Trio 500");
		mouse = Mouse("Samsung Smart Keyboard Trio 500", "optical", "bluetooth");
	}
	void Addduser(Administrator& user)
	{
		admin = &user;
	}
	void Addduser(Guest& user)
	{
		guest = &user;
	}
	void Info()const
	{
		if (admin == nullptr && guest == nullptr)
		{
			cout << " There is no user!!!" << endl;
		}
		if (admin != nullptr || guest != nullptr)
		{
			cout << "++++++++++ACCOUNTS++++++++++" << endl;
			if (admin != nullptr)
			{
				admin->Info();
			}
			if (guest != nullptr)
			{
				guest->Info();
			}
			cout << "++++++++++PC_" << name << "++++++++++++++" << endl;
			display.Info();
			cpu.Info();
			ram.Info();
			ssd.Info();
			motherboard.Info();
			videocard.Info();
			power_supply.Info();
			keyboard.Info();
			mouse.Info();
		}
	}
};

void main()
{
	Administrator adm("Vova", "12345678");
	Guest gue1("Dasha", "87654321");
	Guest gue2("Sasha", "74839468");
	Guest gue3("Masha", "57384843");
	PC pc1("1");
	pc1.Addduser(adm);
	pc1.Addduser(gue1);
	pc1.Info();
	PC pc2("2");
	pc2.Addduser(adm);
	pc2.Addduser(gue2);
	pc2.Info();
	PC pc3("3");
	pc3.Addduser(adm);
	pc3.Addduser(gue3);
	pc3.Info();
}