#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> arr;
void precompute()
{
    for (int i = 0; i < 1670; i++)
    {
        if (i % 3 != 0 && i % 10 != 3)
            arr.push_back(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout<<arr[n-1]<<'\n';
    }
    return 0;
}