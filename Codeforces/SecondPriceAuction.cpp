#include <bits/stdc++.h>
using namespace std;
int maxInd(vector<int> &arr)
{
    int max_ind = -1;
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            max_ind = i + 1;
        }
    }
    return max_ind;
}
int getSecMax(vector<int> &arr)
{
    int maxi = INT_MIN, secmax = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
        {
            secmax = maxi;
            maxi = arr[i];
        }
        else if (arr[i] < maxi && arr[i] > secmax)
            secmax = arr[i];
    }
    return secmax;
}
void ans(vector<int> &arr)
{
    cout << maxInd(arr) << " " << getSecMax(arr) << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ans(arr);
    return 0;
}