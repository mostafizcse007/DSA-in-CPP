#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<string, string> mpp;
    cin.ignore();
    while (n--)
    {
        string str;
        getline(cin, str);
        string seg1 = "", seg2 = "";
        int i = 0;
        while (str[i] != ' ')
        {
            seg1.push_back(str[i]);
            i++;
        }
        i++;
        while (i < str.size())
        {
            seg2.push_back(str[i]);
            i++;
        }
        mpp[seg2] = seg1;
    }

    while (m--)
    {
        string str;
        getline(cin, str);
        string seg2 = "";
        int i = 0;
        while (str[i] != ' ')
        {
            i++;
        }

        i++;
        while (i < str.size())
        {
            seg2.push_back(str[i]);
            i++;
        }
        seg2.pop_back();
        cout << str << " #" << mpp[seg2] << '\n';
    }
    return 0;
}