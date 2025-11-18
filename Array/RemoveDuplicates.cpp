#include <bits/stdc++.h>
using namespace std;
#define ll long long
int remove_duplicates(vector<int> &arr)
{
    int st = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != arr[st])
        {
            st++;
            arr[st] = arr[i];
        }
    }
    return st + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << remove_duplicates(arr) << '\n';
    return 0;
}