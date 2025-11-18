#include <bits/stdc++.h>
using namespace std;
int maxElement(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (auto it : arr)
        maxi = max(maxi, it);
    return maxi + 1;
}
int findSmallest(vector<int> &arr)
{
    unordered_set<int> st;
    int limit = maxElement(arr);
    for (auto it : arr)
        st.insert(it);
    for (int i = 1; i <= arr.size(); i++)
    {
        if (st.find(i) == st.end())
            return i;
    }
    return maxElement(arr);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findSmallest(arr) << endl;
    return 0;
}