#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int low, high;
        cin >> low >> high;
        int cnt = 0;
        for (int i = low; i <= high; i++)
        {
            int temp = i % 10;
            if (temp == 2 or temp == 3 or temp == 9)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}