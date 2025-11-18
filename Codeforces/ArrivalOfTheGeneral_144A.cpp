#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int minPos = -1, mini = 200;
    for (int i = 0; i < n; i++)
    {
        if (mini >= arr[i])
        {
            mini = arr[i];
            minPos = i;
        }
    }
    int cnt = n - 1 - minPos;
    for (int i = minPos; i < n - 1; i++)
        swap(arr[i], arr[i + 1]);
    int maxPos = -1, maxi = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            maxPos = i;
        }
    }
    cnt += maxPos;
    cout << cnt << endl;
    return 0;
}