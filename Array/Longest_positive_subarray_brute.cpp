#include <bits/stdc++.h>
using namespace std;
int subArray(vector<int> &arr, int target)
{
    int len = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {

            sum += arr[j];
            if (sum == target)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << subArray(arr, target) << endl;
    return 0;
}