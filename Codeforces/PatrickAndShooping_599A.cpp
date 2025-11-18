#include <bits/stdc++.h>
using namespace std;
int minDistance(vector<int> &arr)
{
    if (arr[0] == arr[1] && arr[1] == arr[2])
        return arr[0] * 3;
    int dis1 = arr[0] + arr[1];
    dis1 *= 2;
    int dis2 = arr[0] + arr[1] + arr[2];
    return min(dis1, dis2);
}
int main()
{
    vector<int> arr(3);
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    cout << minDistance(arr) << endl;
    return 0;
}