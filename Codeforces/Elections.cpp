#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int maxi = max({a, b, c});
        vector<int> arr;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        sort(arr.begin(), arr.end());
        if (a == b && b == c)
            cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << '\n';
        else if (arr[1] == arr[2])
            cout << maxi + 1 << ' ' << maxi + 1 << ' ' << maxi + 1 << '\n';
        else
        {
            if (maxi == a)
                cout << 0 << ' ';
            else
                cout << maxi - a + 1 << ' ';
            if (maxi == b)
                cout << 0 << ' ';
            else
                cout << maxi - b + 1 << ' ';
            if (maxi == c)
                cout << 0 << '\n';
            else
                cout << maxi - c + 1 << '\n';
        }
    }
    return 0;
}