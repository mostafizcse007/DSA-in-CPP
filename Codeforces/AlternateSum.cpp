#include <bits/stdc++.h>
using namespace std;
int alternateSum(vector<int> &arr)
{
    int sum = 0;
    if (arr.size() == 1)
        return arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
            sum += arr[i];
        else
            sum -= arr[i];
    }
    return sum;
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
        cout << alternateSum(arr) << endl;
    }
    return 0;
}