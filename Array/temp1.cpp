#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] >= 'A' and arr[i] <= 'Z')
            arr[i] += 32;
    }
    set<char> st(arr.begin(), arr.end());
    if (st.size() >= 26)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}