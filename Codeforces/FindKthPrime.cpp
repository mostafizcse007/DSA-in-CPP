#include <bits/stdc++.h>
using namespace std;
const int N = 86028121;
bool seive[N + 1];
vector<int> store;
void createSeive()
{
    for (int i = 2; i <= N; i++)
        seive[i] = true;
    for (int i = 2; i * i <= N; i++)
    {
        if (seive[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                seive[j] = false;
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (seive[i] == true)
            store.push_back(i);
    }
}
int main()
{
    createSeive();
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        cout << store[num - 1] << endl;
    }
    return 0;
}