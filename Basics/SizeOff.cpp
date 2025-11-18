#include <iostream>
using namespace std;
int main()
{
    long long int a = 5;
    float b = 10.1354357;
    char c = 'V';
    double d = 124.64354;
    bool e = true;
    int w = sizeof(a), x = sizeof(b), y = sizeof(c), z = sizeof(d), r = sizeof(e);
    cout << "Size of integer = " << w << endl;
    cout << "Size of float = " << x << endl;
    cout << "Size of character = " << y << endl;
    cout << "Size of double = " << z << endl;
    cout << "Size of boolean = " << r << endl;
}