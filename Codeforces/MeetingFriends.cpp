#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr(3);
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int res = 0;
    cout << arr[2] - arr[0] << endl;
    return 0;
}