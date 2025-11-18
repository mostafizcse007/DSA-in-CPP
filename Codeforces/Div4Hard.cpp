#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> arr(4);
        for (int i = 0; i < 4; i++)
            cin >> arr[i];
        long long sum = 0;
        int space = arr[0] * 2;
        if (arr[1] >= arr[0])
        {
            sum += arr[0];
            space -= arr[0];
        }
        if (arr[1] < arr[0])
        {
            sum += arr[1];
            space -= arr[1];
        }
        if (arr[2] >= arr[0])
        {
            sum += arr[0];
            space -= arr[0];
        }
        if (arr[2] < arr[0])
        {
            sum += arr[2];
            space -= arr[2];
        }
        if (arr[3] >= space)
        {
            sum += space;
        }
        if (arr[3] < space)
            sum += arr[3];
        cout << sum << endl;
    }
    return 0;
}