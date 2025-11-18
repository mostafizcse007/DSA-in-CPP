#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> arr(N);
struct SegmentTreeForTheMinimum
{
    vector<int> st;
    const int inf = 1e9;
    SegmentTreeForTheMinimum()
    {
        st.assign(N * 4, 0);
    }
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            st[node] = arr[start];
            return;
        }
        int left = 2 * node + 1, right = 2 * node + 2, mid = (start + end) / 2;
        build(left, start, mid);
        build(right, mid + 1, end);
        st[node] = min(st[left], st[right]);
    }
    void update(int node, int start, int end, int ind, int val)
    {
        if (ind < start || ind > end)
            return;
        if (start == end && ind == start)
        {
            st[node] = val;
            return;
        }
        int left = 2 * node + 1, right = 2 * node + 2, mid = (start + end) / 2;
        update(left, start, mid, ind, val);
        update(right, mid + 1, end, ind, val);
        st[node] = min(st[left], st[right]);
    }
    int query(int node, int start, int end, int l, int r)
    {
        if (start > r || end < l)
            return inf;
        if (start >= l && end <= r)
            return st[node];
        int left = 2 * node + 1, right = 2 * node + 2, mid = (start + end) / 2;
        return min(query(left, start, mid, l, r), query(right, mid + 1, end, l, r));
    }
} seg;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    seg.build(0, 0, n - 1);
    while (q--)
    {
        int a, l, r;
        cin >> a >> l >> r;
        if (a == 1)
            seg.update(0, 0, n - 1, l, r);
        else
            cout << seg.query(0, 0, n - 1, l, r - 1) << '\n';
    }
    return 0;
}