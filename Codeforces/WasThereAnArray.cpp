#include <iostream>
#include <vector>

using namespace std;

bool isValidArray(int n, const vector<int> &b)
{
    vector<int> a(n, -1);
    int current_num = 1;

    for (int i = 0; i < n; ++i)
    {
        if (i == 0 || i == n - 1)
        {
            a[i] = current_num++;
        }
        else
        {
            if (b[i - 1] == 0)
            {
                current_num++;
            }
            a[i] = current_num;
        }
    }
    for (int i = 1; i < n - 1; ++i)
    {
        if ((b[i - 1] == 1 && !(a[i] == a[i - 1] && a[i] == a[i + 1])) ||
            (b[i - 1] == 0 && a[i] == a[i - 1] && a[i] == a[i + 1]))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> b(n - 2);

        for (int i = 0; i < n - 2; ++i)
        {
            cin >> b[i];
        }

        if (isValidArray(n, b))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}