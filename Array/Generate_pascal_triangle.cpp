#include <bits/stdc++.h>
using namespace std;
vector<int> generateRow(int row)
{
    vector<int> temp;
    temp.push_back(1);
    int res = 1;
    for (int i = 1; i < row; i++)
    {
        res = res * (row - i) / i;
        temp.push_back(res);
    }
    return temp;
}
vector<vector<int>> generateTriangle(int N)
{
    vector<vector<int>> result;
    for (int i = 1; i <= N; i++)
    {
        result.push_back(generateRow(i));
    }
    return result;
}
int main()
{
    int row;
    cin >> row;
    vector<vector<int>> triangle = generateTriangle(row);
    for (const auto &r : triangle)
    {
        for (int num : r)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}