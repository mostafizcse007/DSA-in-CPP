#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> Opt_sort(vector<int> &arr)
{
    int left = 0, right = arr.size() - 1, i = 0;
    while (i <= right)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[left]);
            i++;
            left++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[right]);
            right--;
        }
        else
            i++;
    }
    return arr;
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
    vector<int> res = Opt_sort(arr);
    for (auto x : res)
        cout << x << ' ';
    return 0;
}