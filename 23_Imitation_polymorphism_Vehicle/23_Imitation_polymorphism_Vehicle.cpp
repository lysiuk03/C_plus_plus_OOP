#include <iostream>
using namespace std;

class Vehicle
{
protected:
	string name;
	float time;
	float cost;
	float distance;
	float speed;
	float price;
public:
	Vehicle() :name("none"), time(0), cost(0), distance(0), speed(0), price(0) {}
	Vehicle(string name, float distance, float speed, int price) :name(name), distance(distance), speed(speed), price(price), time(0), cost(0) {}
	void Info()const
	{
		cout << " Name: " << name << endl;
		cout << " Distance: " << distance << " km." << endl;
		cout << " Speed: " << speed << " km/h." << endl;
		cout << " Price: " << price << "grn/h" << endl;
	}
	void Cost_and_Time()
	{
		time = distance / speed;
		cost = time * price;
		cout << " The price of your trip: " << cost << " grn." << endl;
		cout << " The time of your trip: " << time << " h." << endl;
	}
};

class Ñar :public Vehicle
{
public:
	Ñar(float distance) :Vehicle("Car", distance, 70, 300) {}
	void Info()
	{
		cout << "_______________CAR_______________" << endl;
		Vehicle::Info();
	}
};
class Bike :public Vehicle
{
public:
	Bike(float distance) :Vehicle("Bike", distance, 30, 100) {}
	void Info()
	{
		cout << "_______________BIKE_______________" << endl;
		Vehicle::Info();
	}
};
class Cart :public Vehicle
{
public:
	Cart(float distance) :Vehicle("Cart", distance, 50, 250) {}
	void Info()
	{
		cout << "_______________Cart_______________" << endl;
		Vehicle::Info();
	}
};

int main()
{
	Vehicle vehicle("Motorbike", 90, 60, 270);
	vehicle.Info();
	vehicle.Cost_and_Time();
	Ñar car(70);
	car.Info();
	car.Cost_and_Time();
	Bike bike(120);
	bike.Info();
	bike.Cost_and_Time();
	Cart cart(40);
	cart.Info();
	cart.Cost_and_Time();
}