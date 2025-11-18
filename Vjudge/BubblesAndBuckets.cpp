#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cntMoves(vector<int> &arr)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (cntMoves(arr) & 1)
            cout << "Marcelo" << endl;
        else
            cout << "Carlos" << endl;
    }
    return 0;
}