#include <bits/stdc++.h>
using namespace std;
string checkSum(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    if (arr[0] + arr[1] == arr[2])
        return "YES";
    return "NO";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> arr(3);
        for (int i = 0; i < 3; i++)
            cin >> arr[i];
        cout << checkSum(arr) << endl;
    }
    return 0;
}