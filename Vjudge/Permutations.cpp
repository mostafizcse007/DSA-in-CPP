#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> solve(int n)
{
    if (n == 1)
        return {1};
    if (n <= 3)
        return {};
    vector<int> ans;

    for (int i = 2; i <= n; i += 2)
        ans.push_back(i);
    for (int i = 1; i <= n; i += 2)
        ans.push_back(i);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> ans = solve(n);
    if (ans.empty())
    {
        cout << "NO SOLUTION";
        return 0;
    }
    for (auto x : ans)
        cout << x << ' ';
    return 0;
}