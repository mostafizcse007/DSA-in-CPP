#include <bits/stdc++.h>
using namespace std;
string checkSquareMatrix(vector<char> &str)
{
    int size = str.size();
    if (str.size() == 2)
    {
        int cnt = 0;
        for (int i = 0; i < size; i++)
        {
            if (str[i] == '0')
                cnt++;
        }
        if (cnt == 0)
            return "NO";
    }
    if (str.size() == 4)
    {
        int cnt = 0;
        for (int i = 0; i < size; i++)
        {
            if (str[i] == '0')
                cnt++;
        }
        if (cnt == 0)
            return "YES";
    }
    int cnt = 0;
    if ((double)sqrt(size) - (int)sqrt(size) == 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (str[i] == '0')
                cnt++;
        }
        if (cnt >= 1)
            return "YES";
    }
    return "NO";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> str(n);
        for (int i = 0; i < n; i++)
            cin >> str[i];
        cout << checkSquareMatrix(str) << endl;
    }
    return 0;
}