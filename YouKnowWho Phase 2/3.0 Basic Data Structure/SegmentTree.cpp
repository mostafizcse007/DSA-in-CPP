#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> st(N * 4, 0);
#define ll long long
void build(int node, int start, int end, vector<int> &arr)
{
    if (start == end)
    {
        st[node] = arr[start];
        return;
    }
    int left = 2 * node, right = 2 * node + 1;
    int mid = (start + end) / 2;
    build(left, start, mid, arr);
    build(right, mid + 1, end, arr);
    st[node] = st[left] + st[right];
}
int query(int node, int start, int end, int l, int r)
{
    if (start > r or end < l)
        return 0;
    if (start >= l and end <= r)
        return st[node];
    int left = 2 * node, right = 2 * node + 1;
    int mid = (start + end) / 2;
    return query(left, start, mid, l, r) + query(right, mid + 1, end, l, r);
}
void update(int node, int start, int end, int ind, int val)
{
    if (start > ind or end < ind)
        return;
    if (start == end or start == ind)
    {
        st[node] = val;
        return;
    }
    int left = 2 * node, right = 2 * node + 1;
    int mid = (start + end) / 2;
    update(left, start, mid, ind, val);
    update(right, mid + 1, end, ind, val);
    st[node] = st[left] + st[right];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n, arr);
    // while (q--)
    // {
    //     int l, r;
    //     cin >> l >> r;
    //     cout << query(1, 1, n, l, r) << '\n';
    // }
    update(1, 1, n, 3, 69);
    for (int i = 1; i <= 10; i++)
        cout << st[i] << ' ';
    return 0;
}