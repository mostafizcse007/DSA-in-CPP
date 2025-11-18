#include <iostream>
using namespace std;
bool isLucky(int n)
{
    while (n)
    {
        int temp = n % 10;
        if (temp != 4 && temp != 7)
            return 0;
        n /= 10;
    }
    return 1;
}
void almostLucky(int n)
{
    if (isLucky(n))
    {
        cout << "YES" << endl;
        return;
    }
    if (n % 4 == 0 || n % 7 == 0 || n % 47 == 0 || n % 74 == 0 || n % 77 == 0)
    {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}
int main()
{
    int n;
    cin >> n;
    almostLucky(n);
    return 0;
}