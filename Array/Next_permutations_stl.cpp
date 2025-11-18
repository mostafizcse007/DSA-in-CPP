#include <bits/stdc++.h>
using namespace std;
vector<int> nxtPermute(vector<int> &arr)
{
    next_permutation(arr.begin(), arr.end());
    return arr;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> res = nxtPermute(arr);
    for (auto it : res)
        cout << it << " ";
    return 0;
}