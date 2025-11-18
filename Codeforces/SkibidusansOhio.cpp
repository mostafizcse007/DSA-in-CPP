#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int size = str.size();
        // if (size == 1)
        //     cout << 1 << endl;
        int cnt = 0;
        bool flag = true;
        for (int i = 0; i < size - 1; i++)
        {
            if (str[i] == str[i + 1])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            cout << 1 << endl;
        else
            cout << size << endl;
    }
    return 0;
}