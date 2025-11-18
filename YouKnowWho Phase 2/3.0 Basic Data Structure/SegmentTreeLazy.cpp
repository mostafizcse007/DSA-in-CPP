#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lc (2 * node)
#define rc (2 * node + 1)
const int N = 1e5 + 9;
vector<int> arr(N);
struct Segment
{
    vector<long long> st, lazy;
    Segment()
    {
        st.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
    }
    inline void push(int node, int start, int end)
    {
        if (lazy[node] == 0)
            return;
        st[node] = st[node] + lazy[node] * (end - start + 1);
        if (start != end)
        {
            lazy[lc] = lazy[lc] + lazy[node];
            lazy[rc] = lazy[rc] + lazy[node];
        }
        lazy[node] = 0;
    }
    inline ll combine(ll a, ll b)
    {
        return a + b;
    }
    inline void pull(int node)
    {
        st[node] = st[lc] + st[rc];
    }
    void build(int node, int start, int end)
    {
        lazy[node] = 0;
        if (start == end)
        {
            st[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(lc, start, mid);
        build(rc, mid + 1, end);
        pull(node);
    }
    void update(int node, int start, int end, int l, int r, int val)
    {
        push(node, start, end);
        if (end < l || start > r)
            return;
        if (start >= l && end <= r)
        {
            lazy[node] = val;
            push(node, start, end);
            return;
        }
        int mid = (start = end) / 2;
        update(lc, start, mid, l, r, val);
        update(rc, mid + 1, end, l, r, val);
        pull(node);
    }
    ll query(int node, int start, int end, int l, int r)
    {
        push(node, start, end);
        if (start > r || end < l)
            return 0;
        if (start >= l && end <= r)
            return st[node];
        int mid = (start + end) / 2;
        return combine(query(lc, start, mid, l, r), query(rc, mid + 1, end, l, r));
    }
} seg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    seg.build(1, 1, n);
    cout << seg.query(1, 1, n, 1, 5) << '\n';
    return 0;
}