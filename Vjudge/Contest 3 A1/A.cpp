#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &arr)
{
    int i = 0, j = arr.size() - 1;
    sort(arr.begin(), arr.end());
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == 2000)
            return 1;
        else if (sum < 2000)
            i++;
        else
            j--;
    }
    return 0;
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
        if (isPossible(arr))
            cout << "Accepted" << endl;
        else
            cout << "Rejected" << endl;
    }
    return 0;
}