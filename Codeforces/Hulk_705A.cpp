#include <iostream>
#include <string>
using namespace std;
void printHulk(int n)
{
    if (n == 1)
    {
        cout << "I hate it" << endl;
        return;
    }
    else if (n & 1)
    {
        for (int i = 1; i < n; i++)
        {
            if (i & 1)
                cout << "I hate that ";
            else
                cout << "I love that ";
        }
        cout << "I hate it" << endl;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (i & 1)
                cout << "I hate that ";
            else
                cout << "I love that ";
        }
        cout << "I love it" << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    printHulk(n);
}