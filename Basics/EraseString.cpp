#include <iostream>
#include <string>
using namespace std;
int main()
{
    string ph_num;
    getline(cin, ph_num);
    ph_num.erase(0, 4);
    cout << ph_num << endl;
    return 0;
}