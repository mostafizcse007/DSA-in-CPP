#include <bits/stdc++.h>
using namespace std;
#define ll long long

int find_first_occurrence(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result != -1 ? result + 1 : -1;
}

int lower_bound(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low + 1;
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

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int ind = find_first_occurrence(arr, x);
        if (ind != -1)
        {
            cout << "Yes " << ind << '\n';
        }
        else
        {
            cout << "No " << lower_bound(arr, x) << '\n';
        }
    }
    return 0;
}