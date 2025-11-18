#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<int> st(N * 4);
#define ll long long
void build(int node, int start, int end, vector<int> &arr)
{
    if (start == end)
    {
        st[node] = arr[start];
        return;
    }
    int left = node * 2, right = node * 2 + 1;
    int mid = (start + end) / 2;
    build(left, start, mid, arr);
    build(right, mid + 1, end, arr);
    st[node] = min(st[left], st[right]);
}
int query(int node, int start, int end, int l, int r)
{
    if (r < start or l > end)
        return 1e9;
    if (start >= l and end <= r)
        return st[node];
    int left = 2 * node, right = 2 * node + 1;
    int mid = (start + end) / 2;
    return min(query(left, start, mid, l, r), query(right, mid + 1, end, l, r));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n, arr);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << '\n';
    }
    return 0;
}