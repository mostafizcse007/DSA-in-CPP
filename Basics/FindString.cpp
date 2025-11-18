#include <iostream>
#include <string>
using namespace std;
int main()
{
    string fullName;
    getline(cin, fullName);
    string subName;
    getline(cin, subName);
    int pos1 = fullName.find(subName);
    int pos2 = fullName.rfind(subName);
    string sub = fullName.substr(pos1, (pos2 - pos1) + subName.size());
    cout << sub << endl;
    return 0;
}