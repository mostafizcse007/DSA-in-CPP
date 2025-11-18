#include <iostream>
#include <vector>
using namespace std;
int firstOcc(vector<int> &arr, int x)
{
    int ans = -1, low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (x > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}
int lastOcc(vector<int> &arr, int x)
{
    int ans = -1, low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (x > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}
int totalOcc(vector<int> &arr, int x)
{
    if (firstOcc(arr, x) == -1)
        return 0;
    return lastOcc(arr, x) - firstOcc(arr, x) + 1;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << totalOcc(arr, x) << endl;
    return 0;
}