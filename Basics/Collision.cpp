#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        vector<int> arr(10);
        for (int i = 0; i < 10; i++)
            cin >> arr[i];
        if ((arr[8] >= arr[0] && arr[8] <= arr[4]) && (arr[9] >= arr[1] && arr[9] <= arr[7]))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}