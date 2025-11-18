#include <iostream>
using namespace std;
class Cricketer
{
public:
    string name;
    int runs;
    double avg;
    Cricketer(string name, int runs, double avg)
    {
        this->name = name;
        this->runs = runs;
        this->avg = avg;
    }
    void print(Cricketer *c2)
    {
        cout << c2->name << " " << (*c2).runs << " " << c2->avg << endl;
    }
};
int main()
{
    Cricketer *c1 = new Cricketer("Babar Azam", 732739, 383.34);
    c1->print(c1);
}