#include <iostream>
using namespace std;
int removeLSB(int n)
{
    return (n & (n - 1));
}
int main()
{
    int n;
    cin >> n;
    cout << removeLSB(n) << endl;
    return 0;
}