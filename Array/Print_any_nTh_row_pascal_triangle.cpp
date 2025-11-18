#include <bits/stdc++.h>
using namespace std;
vector<int> nthRow(int row)
{
    vector<int> res;
    res.emplace_back(1);
    int temp = 1;
    for (int i = 1; i < row; i++)
    {
        temp = temp * (row - i);
        temp = temp / i;
        res.emplace_back(temp);
    }
    return res;
}
int main()
{
    int row;
    cin >> row;
    vector<int> result = nthRow(row);
    for (auto it : result)
        cout << it << " ";
    return 0;
}