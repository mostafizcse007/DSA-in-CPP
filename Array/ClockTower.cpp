#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int totalDigit(string n, int hr)
{
    vector<ll> dCnt(10, 0);
    for (char c : n)
    {
        dCnt[c - '0']++;
    }

    for (int h = 0; h < hr; h++)
    {
        vector<ll> newCnt(10, 0);
        for (int i = 0; i < 10; i++)
        {
            if (i <= 7)
            {
                newCnt[i + 2] = (newCnt[i + 2] + dCnt[i]) % MOD;
            }
            else
            {
                newCnt[(i + 2) % 10] = (newCnt[(i + 2) % 10] + dCnt[i]) % MOD;
                newCnt[1] = (newCnt[1] + dCnt[i]) % MOD;
            }
        }
        dCnt = newCnt;
    }

    ll final = 0;
    for (int i = 0; i < 10; i++)
    {
        final = (final + dCnt[i]) % MOD;
    }

    return final;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string n;
        int hr;
        cin >> n >> hr;
        cout << totalDigit(n, hr) << endl;
    }

    return 0;
}