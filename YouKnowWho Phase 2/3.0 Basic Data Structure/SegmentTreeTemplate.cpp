#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 9;
vector<int> arr(N * 4);
struct Segment
{
    vector<int> st;
    static const int inf = 1e9;
    Segment()
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
        int mid = (start + end) / 2;
        int left = 2 * node, right = 2 * node + 1;
        build(left, start, mid);
        build(right, mid + 1, end);
        st[node] = max(st[left], st[right]);
    }
    void update(int node, int start, int end, int ind, int val)
    {
        if (start > ind || end < ind)
            return;
        if (start == end && start == ind)
        {
            st[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        int left = 2 * node, right = 2 * node + 1;
        update(left, start, mid, ind, val);
        update(right, mid + 1, end, ind, val);
        st[node] = max(st[left], st[right]);
    }
    int query(int node, int start, int end, int l, int r)
    {
        if (end < l || start > r)
            return -inf;
        if (l <= start && r >= end)
            return st[node];
        int mid = (start + end) / 2;
        int left = 2 * node, right = 2 * node + 1;
        return max(query(left, start, mid, l, r), query(right, mid + 1, end, l, r));
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
    }
    return 0;
}