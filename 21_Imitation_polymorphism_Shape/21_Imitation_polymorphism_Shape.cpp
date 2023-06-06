#include <iostream>
using namespace std;

class Shape
{
protected:
    string name;
    string type;
    double S;
public:
    Shape() :name("none"), type("none"), S(0) {}
    Shape(string name, string type) :name(name), type(type), S(0) {}
    virtual void Show()const
    {
        cout << "_______________Shape_______________" << endl;
        cout << " Name: " << name << endl;
        cout << " Type: " << type << endl;
    }
    virtual void GetArea() = 0;
};
class Rectangle :public Shape
{
private:
    double a;
    double b;
public:
    Rectangle() :a(0), b(0), Shape() {}
    Rectangle(double a, double b) :a(a), b(b), Shape("Rectangle", "quadrangle") {}
    void Show()const override
    {
        Shape::Show();
        cout << " Length: " << a << " sm" << endl;
        cout << " Width: " << b << " sm" << endl;
    }
    void GetArea() override
    {
        S = a * b;
        cout << " The area of the rectangle: " << S << " sm.kv." << endl;
    }
};
class Circle :public Shape
{
private:
    double r;
public:
    Circle() :r(0), Shape() {}
    Circle(double r) :r(r), Shape("Circle", "circle") {}
    void Show()const override
    {
        Shape::Show();
        cout << " Radius: " << r << " sm" << endl;
    }
    void GetArea() override
    {
        S = r * r * 3.14;
        cout << " The area of the circle: " << S << " sm.kv." << endl;
    }
};
class RightTriangle :public Shape
{
private:
    double a;
    double b;
public:
    RightTriangle() :a(0), b(0), Shape() {}
    RightTriangle(double a, double b) :a(a), b(b), Shape("Right triangle", "triangle") {}
    void Show()const override
    {
        Shape::Show();
        cout << " First leg: " << a << " sm" << endl;
        cout << " Second leg: " << b << " sm" << endl;
    }
    void GetArea() override
    {
        S = a * b / 2;
        cout << " The area of the right triangle: " << S << " sm.kv." << endl;
    }
};
class Triangle :public Shape
{
private:
    double a;
    double h;

public:
    Triangle() :a(0), h(0), Shape() {}
    Triangle(double a, double h) :a(a), h(h), Shape("Triangle", "triangle") {}
    void Show()const override
    {
        Shape::Show();
        cout << " Side: " << a << " sm" << endl;
        cout << " Height to side: " << h << " sm" << endl;
    }
    void GetArea() override
    {
        S = a * h / 2;
        cout << " The area of the triangle: " << S << " sm.kv." << endl;
    }
};
class Trapeze :public Shape
{
private:
    double a;
    double b;
    double h;
public:
    Trapeze() :a(0), b(0), h(0), Shape() {}
    Trapeze(double a, double b, double h) :a(a), b(b), h(h), Shape("Trapeze", "quadrangle") {}
    void Show()const override
    {
        Shape::Show();
        cout << " Larger base: " << a << " sm" << endl;
        cout << " Smaller base: " << b << " sm" << endl;
        cout << " Height: " << h << " sm" << endl;
    }
    void GetArea() override
    {
        S = (a + b) / 2 * h;
        cout << " The area of the rectangle: " << S << " sm.kv." << endl;
    }
};
void TestShape(Shape& shape)
{
    shape.Show();
    shape.GetArea();
}

int main()
{
    Rectangle rec(2, 4);
    rec.Show();
    rec.GetArea();
    Circle col(5);
    col.Show();
    col.GetArea();
    RightTriangle rig(5, 4);
    rig.Show();
    rig.GetArea();
    Triangle tri(5, 6);
    tri.Show();
    tri.GetArea();
    Trapeze tra(10, 5, 7);
    tra.Show();
    tra.GetArea();
    cout << "+++++++++++++++++TEST+++++++++++++++++" << endl;
    TestShape(rec);
    TestShape(col);
    TestShape(rig);
    TestShape(tri);
    TestShape(tra);
}
