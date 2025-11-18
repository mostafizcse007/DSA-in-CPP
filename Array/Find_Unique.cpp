#include <bits/stdc++.h>
using namespace std;
int findUnique(int *arr, int size)
{
    int unique = 0;
    for (int i = 0; i < size; i++)
    {
        unique ^= arr[i];
    }
    return unique;
    // map<int, int> mpp;
    // for (int i = 0; i < size; i++)
    // {
    //     mpp[arr[i]]++;
    // }
    // for (auto it : mpp)
    // {
    //     if (it.second == 1)
    //         return it.first;
    // }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findUnique(arr, n);
    return 0;
}