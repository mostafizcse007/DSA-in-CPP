#include <bits/stdc++.h>
using namespace std;
bool Order(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
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
        if (Order(arr))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}