#include <iostream>
using namespace std;

struct Vagoon
{
    int number;
    int places;
    int passanges;
    Vagoon() :number(0), places(0), passanges(0) {}
    Vagoon(int number, int places) :number(number), places(places), passanges(0) {}
    void Show()
    {
        cout << " Number of vagoon : " << number << endl;
        cout << "Count all places : " << places << endl;
        cout << "Count of passanger : " << passanges << endl;
    }
};
class Train
{
private:
    string model;
    int countVagoon;
    Vagoon* v;
    static int count;
public:
    Train() :model("no name"), countVagoon(0), v(nullptr)
    {
        cout << "Counstructor" << endl; count++;
    }
    Train(string model) :model(model), countVagoon(0), v(nullptr) { count++; }
    Train(const Train& other)
    {
        this->model = other.model;
        this->countVagoon = other.countVagoon;
        this->v = new Vagoon[other.countVagoon];
        for (int i = 0; i < other.countVagoon; i++)
        {
            v[i] = other.v[i];
        }
        count++;
    }
    Train(Train&& other)
    {
        this->model = other.model;
        this->countVagoon = other.countVagoon;
        this->v = other.v;
        this->count = other.count;
        other.v = nullptr;
    }
    void Show()
    {
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "- - - - - - Train " << model << "- - - - - - " << endl;
        cout << "Count of vagoon : " << countVagoon << endl;
        for (int i = 0; i < countVagoon; i++)
        {
            cout << " Number of vagoon : " << v[i].number << endl;
            cout << "Count all places : " << v[i].places << endl;
            cout << "Count of passanger : " << v[i].passanges << endl;
        }
    }
    void AddVagoon(int number, int places)
    {
        countVagoon++;
        Vagoon* temp = new Vagoon[countVagoon];
        for (int i = 0; i < countVagoon - 1; i++)
        {
            temp[i] = v[i];
        }
        temp[countVagoon - 1] = Vagoon(number, places);
        if (v != nullptr)
            delete[]v;
        v = temp;
    }
    void AddVagoon(const Vagoon& vagoon)
    {
        countVagoon++;
        Vagoon* temp = new Vagoon[countVagoon];
        for (int i = 0; i < countVagoon - 1; i++)
        {
            temp[i] = v[i];
        }
        temp[countVagoon - 1] = vagoon;
        if (v != nullptr)
            delete[]v;
        v = temp;
    }
    void AddPassanger(int number)
    {
        for (int i = 0; i < countVagoon; i++)
        {
            if (v[i].number == number)
            {
                v[i].passanges++;
            }
        }
    }
    void operator++()
    {
        for (int i = 0; i < countVagoon; i++)
        {
            v[i].passanges++;
        }
    }
    void changePassanger(int count)
    {
        for (int i = 0; i < countVagoon; i++)
        {
            v[i].passanges += count;
        }
    }
    void operator()(int count)
    {
        for (int i = 0; i < countVagoon; i++)
        {
            v[i].passanges += count;
        }
    }
    static int getCount()
    {
        return count;
    }
    Train operator+(const Train& other)
    {
        Train res(*this);
        for (int i = 0; i < other.countVagoon; i++)
        {
            res.AddVagoon(other.v[i]);
        }
        return res;
    }
    Vagoon getVagon(int ind)
    {
        if (ind < 0 || ind >= countVagoon)return Vagoon();
        return v[ind];
    }
    Vagoon operator[](int ind)
    {
        if (ind < 0 || ind >= countVagoon)return Vagoon();
        return v[ind];
    }
    Train operator = (const Train& other)
    {
        this->model = other.model;
        this->countVagoon = other.countVagoon;
        if (v != nullptr)
            delete[]v;
        this->v = new Vagoon[other.countVagoon];
        for (int i = 0; i < countVagoon; i++)
        {
            this->v[i] = other.v[i];
        }
        this->count = other.count;
        return *this;
    }
    ~Train()
    {
        if (v != nullptr)
            delete[]v;
        count--;
    }
};
int Train::count = 0;
int main()
{
    Train t1("W232");
    t1.AddVagoon(1, 15);
    t1.AddVagoon(2, 10);
    t1.AddVagoon(3, 8);
    t1.changePassanger(5);
    t1.Show();
    Train t2("E456");
    t2.AddVagoon(1, 30);
    t2.AddVagoon(2, 25);
    t2.AddVagoon(3, 20);
    t2.changePassanger(12);
    t2.Show();
    Train t3("R523");
    t3.AddVagoon(1, 20);
    t3.AddVagoon(2, 25);
    t3.AddVagoon(3, 30);
    t3.changePassanger(10);
    t3.Show();
    Train t4("T777");
    t4.AddVagoon(1, 35);
    t4.AddVagoon(2, 35);
    t4.AddVagoon(3, 35);
    t4.changePassanger(13);
    t4.Show();
    t1 = t2 = t3 = t4;
    t1.Show();
    t2.Show();
    t3.Show();
    t4.Show();
}