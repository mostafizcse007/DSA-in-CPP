#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> arr(N);
vector<int> seg(N * 4, 0);
void build(int node, int start, int end)
{
    if (start == end)
    {
        seg[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    int lc = 2 * node + 1, rc = 2 * node + 2;
    build(lc, start, mid);
    build(rc, mid + 1, end);
    seg[node] = seg[lc] + seg[rc];
}
inline void update1(int node, int start, int end, int ind)
{
    if (ind < start || ind > end)
        return;
    if (start == end && start == ind)
    {
        seg[node] = 0;
        return;
    }
    int mid = (start + end) / 2;
    int lc = 2 * node + 1, rc = 2 * node + 2;
    update1(lc, start, mid, ind);
    update1(rc, mid + 1, end, ind);
    seg[node] = seg[lc] + seg[rc];
}
inline void update2(int node, int start, int end, int ind, int val)
{
    if (ind < start || ind > end)
        return;
    if (start == end && start == ind)
    {
        seg[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    int lc = 2 * node + 1, rc = 2 * node + 2;
    update2(lc, start, mid, ind, val);
    update2(rc, mid + 1, end, ind, val);
    seg[node] = seg[lc] + seg[rc];
}
inline int query(int node, int start, int end, int l, int r)
{
    if (end < l || start > r)
        return 0;
    if (start >= l && end <= r)
        return seg[node];
    int mid = (start + end) / 2;
    int lc = 2 * node + 1, rc = 2 * node + 2;
    return query(lc, start, mid, l, r) + query(rc, mid + 1, end, l, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++cs << ":" << '\n';
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        build(0, 0, n - 1);
        while (q--)
        {
            int ty;
            cin >> ty;
            if (ty == 1)
            {
                int ind;
                cin >> ind;
                cout << query(0, 0, n - 1, ind, ind) << '\n';
                update1(0, 0, n - 1, ind);
            }
            else if (ty == 2)
            {
                int ind, val;
                cin >> ind >> val;
                update2(0, 0, n - 1, ind, val);
            }
            else
            {
                int l, r;
                cin >> l >> r;
                cout << query(0, 0, n - 1, l, r) << '\n';
            }
        }
    }
    return 0;
}