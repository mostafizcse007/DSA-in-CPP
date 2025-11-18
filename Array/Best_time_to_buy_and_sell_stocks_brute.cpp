#include <bits/stdc++.h>
using namespace std;
int main()
{
    int day;
    cin >> day;
    vector<int> arr(day);
    for (int i = 0; i < day; i++)
        cin >> arr[i];
    int maxi = INT_MIN, diff;
    for (int i = 0; i < day - 1; i++)
    {
        for (int j = i + 1; j < day; j++)
        {
            diff = arr[j] - arr[i];
            maxi = max(maxi, diff);
        }
    }
    cout << maxi << endl;
}