#include <iostream>
using namespace std;
class Scientists
{
public:
    string name, theory;
    Scientists(string name, string theory)
    {
        this->name = name;
        this->theory = theory;
    }
    void print()
    {
        cout << this->name << " " << this->theory << endl;
    }
};
int main()
{
    Scientists s1("Albert Einstein", "Theory of Relativity");
    Scientists s2("Issac Newton", "Principle of Mathematecia");
    s1.print();
    s2.print();
    return 0;
}