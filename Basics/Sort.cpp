#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        vector<int> arr(a);
        vector<int> brr(b);
        for (int i = 0; i < a; i++)
            cin >> arr[i];
        for (int i = 0; i < b; i++)
            cin >> brr[i];
        vector<int> ans;
        ans.insert(ans.end(), arr.begin(), arr.end());
        ans.insert(ans.end(), brr.begin(), brr.end());
        sort(ans.rbegin(), ans.rend());
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}