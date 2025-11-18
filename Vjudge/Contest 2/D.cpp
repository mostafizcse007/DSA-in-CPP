#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int maxi = INT_MIN;
        for (auto it : arr)
            maxi = max(it, maxi);
        cout << "Case " << i << ": " << maxi << endl;
        i++;
    }
    return 0;
}