#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &arr)
{
    int cn1 = 0, cn2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (cn1 == 0 && el2 != arr[i])
        {
            el1 = arr[i];
            cn1 = 1;
        }
        else if (cn2 == 0 && el2 != arr[i])
        {
            el2 = arr[i];
            cn2 = 1;
        }
        else if (el1 == arr[i])
        {
            cn1++;
        }
        else if (el2 == arr[i])
        {
            cn2++;
        }
        else
        {
            cn1--;
            cn2--;
        }
    }
    int ch1 = 0, ch2 = 0;
    int mini = (arr.size() / 3) + 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (el1 == arr[i])
            ch1++;
        if (el2 == arr[i])
            ch2++;
    }
    vector<int> res;
    if (ch1 >= mini)
        res.push_back(el1);
    if (ch2 >= mini)
        res.push_back(el2);
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = majorityElement(arr);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}