#include <iostream>
using namespace std;
int main()
{
    int ans = 1;
    int num;
    cin >> num;
    for (int i = 2; i <= num; i++)
    {
        ans *= i;
    }
    cout << ans << endl;
    return 0;
}