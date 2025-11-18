#include <Bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int mini = arr[0], maxi = arr[0], cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            cnt++;
        }
        if (arr[i] < mini)
        {
            mini = arr[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}