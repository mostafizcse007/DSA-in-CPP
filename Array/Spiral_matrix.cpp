#include <bits/stdc++.h>
using namespace std;
void spiralMatrix(vector<vector<int>> &arr)
{
    int row = arr.size(), col = arr[0].size();
    int left = 0, top = 0, right = col - 1, bottom = row - 1;
    vector<int> store;
    while (left <= right && bottom >= top)
    {
        for (int i = left; i <= right; i++)
            store.emplace_back(arr[top][i]);
        top++;
        for (int i = top; i <= bottom; i++)
            store.emplace_back(arr[i][right]);
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                store.emplace_back(arr[bottom][i]);
        }
        bottom--;
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                store.emplace_back(arr[i][left]);
        }

        left++;
    }
    for (auto it : store)
        cout << it << " ";
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    spiralMatrix(arr);
    return 0;
}