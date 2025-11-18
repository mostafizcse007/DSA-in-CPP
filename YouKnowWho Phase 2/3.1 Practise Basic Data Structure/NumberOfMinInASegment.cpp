#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
const int inf = 1e9 + 9;
vector<int> arr(N);
struct node
{
    int mini, cnt;
};
vector<node> seg(N * 4);
node merge(node l, node r)
{
    node ans;
    ans.mini = min(l.mini, r.mini);
    ans.cnt = 0;
    if (ans.mini == l.mini)
        ans.cnt += l.cnt;
    if (ans.mini == r.mini)
        ans.cnt += r.cnt;
    return ans;
}
void build(int vertex, int start, int end)
{
    if (start == end)
    {
        seg[vertex].mini = arr[start];
        seg[vertex].cnt = 1;
        return;
    }
    int mid = start + (end - start) / 2;
    int lc = 2 * vertex, rc = 2 * vertex + 1;
    build(lc, start, mid);
    build(rc, mid + 1, end);
    seg[vertex] = merge(seg[lc], seg[rc]);
}
void update(int vertex, int start, int end, int ind, int val)
{
    if (ind < start || ind > end)
        return;
    if (start == end)
    {
        seg[vertex].mini = val;
        seg[vertex].cnt = 1;
        return;
    }
    int lc = 2 * vertex, rc = 2 * vertex + 1;
    int mid = start + (end - start) / 2;
    update(lc, start, mid, ind, val);
    update(rc, mid + 1, end, ind, val);
    seg[vertex] = merge(seg[lc], seg[rc]);
}
node query(int vertex, int start, int end, int l, int r)
{
    if (start > r or end < l)
        return {inf, 1};
    if (start >= l && end <= r)
        return seg[vertex];
    int lc = 2 * vertex, rc = 2 * vertex + 1;
    int mid = start + (end - start) / 2;
    return merge(query(lc, start, mid, l, r), query(rc, mid + 1, end, l, r));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int l, r;
            cin >> l >> r;
            ++l;
            update(1, 1, n, l, r);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            ++l;
            node ans = query(1, 1, n, l, r);
            cout << ans.mini << ' ' << ans.cnt << '\n';
        }
    }
    return 0;
}