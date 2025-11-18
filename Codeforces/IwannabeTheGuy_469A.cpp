#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool maxInteger(const vector<int> &a, const vector<int> &b, int x)
{
    unordered_set<int> st(a.begin(), a.end());
    for (auto it : b)
        st.insert(it);
    if (st.size() >= x)
        return 1;
    return 0;
}
int main()
{
    int x, n, m;
    cin >> x >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];
    if (maxInteger(a, b, x))
        cout << "I become the guy.";
    else
        cout << "Oh, my keyboard!";
    return 0;
}