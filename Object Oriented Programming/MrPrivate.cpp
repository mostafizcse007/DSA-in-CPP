#include <bits/stdc++.h>
using namespace std;
class Access
{
public:
    string name;
    int roln;
    Access()
    {
    }
    Access(string n, int r, double m) : name(n), roln(r), marks(m) {}
    double display()
    {
        return marks;
    }

private:
    double marks;
};
int main()
{
    Access a1("Antu", 631, 93.7);
    a1.roln = 14.3;
    cout << a1.display();
}