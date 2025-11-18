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
        string arr, brr;
        cin >> arr >> brr;
        unordered_map<char, int> mpp;
        for (auto x : brr)
            mpp[x]++;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (mpp[arr[i]] > 0)
                mpp[arr[i]]--;
            else
                arr[i] = '.';
        }
        string str = "";
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] != '.')
                str.push_back(arr[i]);
        }
        if (str == brr)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        // cout<<str<<'\n';
    }
    return 0;
}