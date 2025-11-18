#include <bits/stdc++.h>
using namespace std;
void Rearrange(vector<int> &arr)
{
    vector<int> positive;
    vector<int> negative;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
            negative.emplace_back(arr[i]);
        else
            positive.emplace_back(arr[i]);
    }
    int pos = 0, neg = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
        {
            arr[i] = positive[pos];
            pos++;
        }
        else
        {
            arr[i] = negative[neg];
            neg++;
        }
    }
    for (auto it : arr)
        cout << it << " ";
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> positive;
    vector<int> negative;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Rearrange(arr);
    return 0;
}