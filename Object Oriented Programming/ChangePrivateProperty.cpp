#include <bits/stdc++.h>
using namespace std;
class Change
{
public:
    string name;
    int roln;
    Change()
    {
    }
    Change(string name, int roln, double marks) : name(name), roln(roln), marks(marks) {}
    double display() // Getter
    {
        return marks;
    }
    void setter(double m) // Setter
    {
        marks = m;
    }

private:
    double marks;
};
int main()
{
    Change c1("Antu", 100, 281.243);
    c1.setter(94.2); // Private property has changed
    cout << c1.display() << endl;
    return 0;
}