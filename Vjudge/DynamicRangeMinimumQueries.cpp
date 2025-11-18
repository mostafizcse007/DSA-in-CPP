#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 9;
vector<int> arr(N);
struct DynamicRangeMinimumQueries
{
    vector<int> st;
    DynamicRangeMinimumQueries()
    {
        st.assign(N * 4, 0);
    }
    static const int inf = INT_MAX;
    void build(int node, int start, int end)
    {
        if (start == end)
        {
            st[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        int left = 2 * node, right = 2 * node + 1;
        build(left, start, mid);
        build(right, mid + 1, end);
        st[node] = min(st[left], st[right]);
    }
    int query(int node, int start, int end, int l, int r)
    {
        if (end < l || start > r)
            return inf;
        if (start >= l && end <= r)
            return st[node];
        int mid = (start + end) / 2;
        int left = 2 * node, right = 2 * node + 1;
        return min(query(left, start, mid, l, r), query(right, mid + 1, end, l, r));
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
        int mid = (start + end) / 2;
        int left = 2 * node, right = 2 * node + 1;
        update(left, start, mid, ind, val);
        update(right, mid + 1, end, ind, val);
        st[node] = min(st[left], st[right]);
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
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            seg.update(1, 1, n, b, c);
        else
            cout << seg.query(1, 1, n, b, c) << endl;
    }
    return 0;
}