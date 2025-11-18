#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cntSwaps(vector<int> &arr)
{
    int cnt = 0, n = arr.size();
    bool flag = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                cnt++;
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            return cnt;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Optimal train swapping takes " << cntSwaps(arr) << " swaps." << endl;
    }
    return 0;
}