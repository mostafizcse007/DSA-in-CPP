#include <bits/stdc++.h>
using namespace std;
int getMin(vector<int> &arr)
{
    int size = arr.size();
    int mini = INT_MAX;
    if (size == 1)
        return arr[0];
    for (int i = 0; i < size; i++)
    {
        int modVal = abs(0 - arr[i]);
        mini = min(mini, modVal);
    }
    return mini;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int val = getMin(arr);
    if (val <= 0)
        cout << val * -1 << endl;
    else
        cout << val << endl;
    return 0;
}