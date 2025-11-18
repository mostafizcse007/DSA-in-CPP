#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        unordered_map<int, int> mpp;
        for (auto it : arr)
            mpp[it]++;
        int y = mpp.size();
        int x = n - y;
        if (x & 1)
            cout << y - 1 << endl;
        else
            cout << y << endl;
    }
    return 0;
}