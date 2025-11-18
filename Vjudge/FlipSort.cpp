#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n)
    {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            bool flag = false;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    cnt++;
                    swap(arr[j], arr[j + 1]);
                    flag = true;
                }
            }
            if (!flag)
                break;
        }
        cout << "Minimum exchange operations : " << cnt << endl;
    }
    return 0;
}