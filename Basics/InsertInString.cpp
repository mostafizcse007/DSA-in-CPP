#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name;
    getline(cin, name);
    name.insert(0, "Mostafizur Rahman ");
    cout << name << endl;
    return 0;
}