#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> arr(n);
    cin.ignore();
    for (int i = 0; i < n; i++)
        getline(cin, arr[i]);
    unordered_set<string> st(arr.begin(), arr.end());
    cout << st.size() << '\n';
    return 0;
}