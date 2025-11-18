#include <bits/stdc++.h>
using namespace std;
int goodArray(int left, int right)
{
    if (left == right)
        return 1;
    int cnt = 0;
    int diff = 1;
    while (left <= right)
    {

        left += diff;
        diff++;
        cnt++;
    }
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int left, right;
        cin >> left >> right;
        cout << goodArray(left, right) << endl;
    }
    return 0;
}