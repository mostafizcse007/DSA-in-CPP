#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> leaders;
    for (int i = 0; i < n; i++)
    {
        int leader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                leader = false;
                break;
            }
        }
        if (leader == true)
            leaders.emplace_back(arr[i]);
    }
    for (auto it : leaders)
        cout << it << " ";
    return 0;
}