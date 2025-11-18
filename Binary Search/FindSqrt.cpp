#include <iostream>
using namespace std;
int findSqrt(int n)
{
    if (n == 0)
        return 0;
    int low = 1, high = n, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << findSqrt(n) << endl;
    return 0;
}