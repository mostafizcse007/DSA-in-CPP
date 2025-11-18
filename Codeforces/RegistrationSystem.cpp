#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++)
        cin >> str[i];
    unordered_map<string, int> mpp;
    for (int i = 0; i < n; i++)
    {
        if (mpp.find(str[i]) == mpp.end())
        {
            cout << "OK" << '\n';
        }
        else
            cout << str[i] << mpp[str[i]] << '\n';
        mpp[str[i]]++;
    }
    return 0;
}