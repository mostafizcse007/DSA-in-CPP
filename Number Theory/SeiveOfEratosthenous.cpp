#include <iostream>
#include <vector>
using namespace std;
vector<bool> createSeive(int n)
{
    vector<bool> seive(n + 1, true);
    seive[0] = false;
    seive[1] = false;
    for (int i = 4; i <= n; i += 2)
        seive[i] = false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (seive[i])
            for (int j = i * i; j <= n; j += 2 * i)
                seive[j] = false;
    }
    return seive;
}
int main()
{
    int n;
    cin >> n;
    vector<bool> ans = createSeive(n);
    for (int i = 2; i <= n; i++)
    {
        if (ans[i])
            cout << i << " ";
    }
    return 0;
}
