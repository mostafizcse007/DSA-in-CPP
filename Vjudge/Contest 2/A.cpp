#include <bits/stdc++.h>
using namespace std;

vector<char> Decrypt(vector<char> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr;
    vector<char> ans;
    int index = 0;
    for (int i = 1; index < n; i++)
    {
        ans.push_back(arr[index]);
        index += i;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<char> ans = Decrypt(arr);
    for (auto it : ans)
        cout << it;
    cout << endl;
    return 0;
}