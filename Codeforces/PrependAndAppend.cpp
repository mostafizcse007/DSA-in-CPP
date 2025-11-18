#include <bits/stdc++.h>
using namespace std;
#define ll long long
int min_length(vector<char> &arr)
{
    int size = arr.size();
    if (arr[0] == arr[size - 1])
        return size;
    int i = 0, j = size - 1;
    while (arr[i] != arr[j] && i <= j)
    {
        size -= 2;
        i++;
        j--;
    }
    return size;
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
        vector<char> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << min_length(arr) << '\n';
    }
    return 0;
}