#include <iostream>
#include <string>
using namespace std;
class Vehicles
{
public:
    int gear;
    double mileage;
    string fuelType;
    Vehicles(int gear, double mileage, string fuelType) : gear(gear), mileage(mileage), fuelType(fuelType) {}
};
class Car : public Vehicles
{
public:
    string sunroof;
    Car(int gear, double mileage, string fuelType, string sunroof) : Vehicles(gear, mileage, fuelType), sunroof(sunroof) {}
};
class Bike : public Vehicles
{
public:
    int seat;
    Bike(int gear, double mileage, string fuelType, int seat) : Vehicles(gear, mileage, fuelType), seat(seat) {}
};
int main()
{
    int g, s;
    double m;
    string f;
    cin >> g >> m >> f >> s;
    Bike b1(g, m, f, s);
    cout << b1.seat << endl;
    return 0;
}