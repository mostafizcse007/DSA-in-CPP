#include <iostream>
#include <string>
using namespace std;
class Scooty // Parent
{
public:
    int price;
    double mileage;
    Scooty(int price, double mileage, string dikki) : price(price), mileage(mileage), dikki(dikki) {}
    void display()
    {
        cout << dikki << endl;
    }

private:
    string dikki;
};
class Bike : public Scooty // Child
{
public:
    int gears;
    Bike(int price, double mileage, string dikki, int gears) : Scooty(price, mileage, dikki), gears(gears) {}
};
int main()
{
    Scooty s1(23372, 232.3, "Yes");
    s1.display();
    Bike b1(3233, 344.6, "no", 6);
    cout << b1.gears << endl;
}