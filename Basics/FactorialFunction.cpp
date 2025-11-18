#include <iostream>
using namespace std;
findFactorial(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans *= i;
    }
    return ans;
}
int main()
{
    int num;
    cin >> num;
    cout << findFactorial(num) << endl;
    return 0;
}