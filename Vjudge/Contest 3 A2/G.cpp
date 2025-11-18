#include <bits/stdc++.h>
using namespace std;
int secLarge(vector<int> &v)
{
    int large = v[0], sec = INT_MIN;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > large)
        {
            sec = large;
            large = v[i];
        }
        else if (v[i] < large && sec < v[i])
            sec = v[i];
    }
    if (sec == INT_MIN)
        return -1;
    return sec;
}
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
        int maxi = *max_element(arr.begin(), arr.end());
        int sec = secLarge(arr);
        cout << maxi + sec << endl;
    }
    return 0;
}