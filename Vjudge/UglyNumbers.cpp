#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e18;
int main()
{
    vector<ll> arr;
    ll p2 = 1;
    for (int i = 0; p2 <= MAX; i++, p2 *= 2)
    {
        ll p3 = 1;
        for (int j = 0; p2 * p3 <= MAX; j++, p3 *= 3)
        {
            ll p5 = 1;
            for (int k = 0; p2 * p3 * p5 <= MAX; k++, p5 *= 5)
                arr.push_back(p2 * p3 * p5);
        }
    }
    sort(arr.begin(), arr.end());
    cout << "The 1500'th ugly number is " << arr[1499] << "." << endl;
    return 0;
}