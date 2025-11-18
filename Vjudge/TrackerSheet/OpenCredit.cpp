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
        int maxi = INT_MIN;
        int curr = arr[0];
        for (int i = 1; i < n; i++)
        {
            int temp = curr - arr[i];
            if (temp > maxi)
                maxi = temp;
            if (arr[i] > curr)
                curr = arr[i];
        }
        cout << maxi << endl;
    }
    return 0;
}