#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name;
    getline(cin, name);
    string nickname = name.substr(5, 5);
    cout << nickname << endl;
}