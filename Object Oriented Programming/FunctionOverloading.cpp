#include <iostream>
#include <string>
using namespace std;
class Overload
{
public:
    void sum(int a, int b)
    {
        cout << a + b << endl;
    }
    void sum(int a, int b, int c)
    {
        cout << a + b + c << endl;
    }
    void sum(string a, string b, string c)
    {
        cout << a + b + c << endl;
    }
};
int main()
{
    Overload a1;
    a1.sum(3, 3);
    a1.sum(3, 3, 23);
    a1.sum("Mostafizur", " ", "Rahman");
    return 0;
}