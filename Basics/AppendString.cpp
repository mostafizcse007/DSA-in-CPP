#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    getline(cin, a);
    string b;
    getline(cin, b);
    a.append(b);
    cout << a << endl;
    return 0;
}