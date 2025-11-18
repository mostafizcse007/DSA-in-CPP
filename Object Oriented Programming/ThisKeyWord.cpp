#include <iostream>
using namespace std;
class Footballer
{
public:
    string name, foot;
    Footballer()
    {
    }
    Footballer(string name, string foot)
    {
        this->name = name;
        this->foot = foot;
    }
};
int main()
{
    Footballer f1("Neymar", "Right Foot");
    Footballer f2("Messi", "Left Foot");
    cout << f1.name << " " << f1.foot << endl;
    cout << f2.name << " " << f2.foot << endl;
    return 0;
}