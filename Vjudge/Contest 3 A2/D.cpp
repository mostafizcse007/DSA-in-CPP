#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long> arr(n);
        vector<long> diffArray(n + 1, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int q;
        cin >> q;
        while (q--)
        {
            int s, e, w;
            cin >> s >> e >> w;
            s -= 1;
            e -= 1;
            diffArray[s] += w;
            diffArray[e + 1] -= w;
        }
        for (int i = 1; i < n; i++)
            diffArray[i] += diffArray[i - 1];
        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i] + diffArray[i];
        cout << sum << endl;
    }
    return 0;
}