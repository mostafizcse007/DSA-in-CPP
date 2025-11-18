#include <iostream>
using namespace std;
class Bazar
{
public:
    string name;
    int price;
    Bazar(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
};
int main()
{
    Bazar list1("Alu", 50);
    Bazar list2("Begun", 60);
    Bazar *ptr1 = &list1;
    Bazar *ptr2 = &list2;
    cout << (*ptr1).name << endl;
    return 0;
}