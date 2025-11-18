#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_possible(string &s, int k)
{
    int n = s.size();
    int swaps_needed = 0;

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            swaps_needed++;
        }
    }

    return swaps_needed <= k;
}

bool is_lexicographically_smaller(string &s)
{
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    return s < reversed_s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (is_lexicographically_smaller(s) || is_possible(s, k))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}