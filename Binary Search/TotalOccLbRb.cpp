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
int Occurence(vector<int> &arr, int n, int x)
{
    int lb = LowerBound(arr, n, x);
    if (lb == n || arr[lb] != x)
        return 0;
    return UpperBound(arr, n, x) - lb;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << Occurence(arr, n, x);
    return 0;
}