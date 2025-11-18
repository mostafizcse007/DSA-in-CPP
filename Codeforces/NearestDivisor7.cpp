#include <bits/stdc++.h>
using namespace std;
int LowerBound(vector<int> &arr, int num)
{
    int ans = -1, low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= num)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int UpperBound(vector<int> &arr, int num)
{
    int ans = -1, low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > num)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int checkDivisor(vector<int> &arr, int num)
{
    if (num >= 14 && num <= 994 && num % 7 == 0)
        return num;
    int low = LowerBound(arr, num);
    int high = UpperBound(arr, num);
    int ch1 = num - low;
    int ch2 = high - num;
    if (num <= 14)
        return 14;
    if (num >= 994)
        return 994;
    if (ch1 <= ch2)
        return low;
    else
        return high;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> arr;
        int num;
        cin >> num;
        for (int i = 14; i <= 994; i++)
        {
            if (i % 7 == 0)
                arr.emplace_back(i);
        }
        cout << checkDivisor(arr, num) << endl;
    }
    return 0;
}