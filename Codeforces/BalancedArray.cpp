#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> makeBalanced(int n)
{
    vector<int> ans;
    for (int i = 2; i <= n; i += 2)
        ans.push_back(i);
    for (int i = 1; i < n - 2; i += 2)
        ans.push_back(i);
    int temp = n / 4;
    int last = ans.size();
    ans.push_back(ans[last - 1] + (2 * temp + 2));
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if ((n / 2) & 1)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            vector<int> res = makeBalanced(n);
            for (auto x : res)
                cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}