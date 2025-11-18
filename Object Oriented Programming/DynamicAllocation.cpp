#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int *x = new int(a);
    cout << *x << endl;
}