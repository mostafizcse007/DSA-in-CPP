#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int ans = INT_MIN;
    int temp = 0;
    while (t--)
    {
        int enter, exit;
        cin >> exit >> enter;
        temp += (enter - exit);
        ans = max(ans, temp);
    }
    cout << ans << endl;
    return 0;
}