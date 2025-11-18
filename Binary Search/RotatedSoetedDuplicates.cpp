#include <iostream>
#include <vector>
using namespace std;
bool findElement(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
            return true;
        else if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
        }
        else if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (arr[mid] <= k && k <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        arr.emplace_back(el);
    }
    if (findElement(arr, n, x))
        cout << "Element found";
    else
        cout << "Element not found";
    return 0;
}