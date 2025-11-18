#include <bits/stdc++.h>
using namespace std;
int maxTravel(vector<char> &arr)
{
    int size = arr.size();
    int cntZ = 0;
    for (auto it : arr)
    {
        if (it == '0')
            cntZ++;
    }
    if (cntZ == size)
        return size;
    int front = 0, back = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == '1')
        {
            front = max(i, size - i);
            break;
        }
    }
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] == '1')
        {
            back = max(i + 1, size - i - 1);
            break;
        }
    }
    return max(front, back) * 2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxTravel(arr) << endl;
    }
    return 0;
}