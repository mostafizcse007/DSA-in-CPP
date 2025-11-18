#include <iostream>
#include <vector>
using namespace std;
int LowerBound(vector<int> &arr, int n, int x)
{
    int ans = n, low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int UpperBound(vector<int> &arr, int n, int x)
{
    int ans = n, low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
vector<int> Occurence(vector<int> &arr, int n, int x)
{
    int lb = LowerBound(arr, n, x);
    if (lb == n || arr[lb] != x)
        return {-1, -1};
    return {LowerBound(arr, n, x), UpperBound(arr, n, x) - 1};
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = Occurence(arr, n, x);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}