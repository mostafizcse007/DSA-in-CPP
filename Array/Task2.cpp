#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node
{
    int x1, x2, x3;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<node> arr(n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i].x1 = a;
        arr[i].x2 = b;
        arr[i].x3 = c;
    }
    for (auto it : arr)
        cout << it.x1 << ' ' << it.x2 << ' ' << it.x3 << '\n';
    return 0;
}