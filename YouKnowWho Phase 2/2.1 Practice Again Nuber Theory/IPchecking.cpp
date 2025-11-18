#include <bits/stdc++.h>
using namespace std;
#define ll long long
string convertDecimal(string &str)
{
    int size = str.size();
    int total = 0, p2 = 1;
    while (size--)
    {
        int num = (str[size] - '0');
        if (num == 1)
            total += p2;
        p2 *= 2;
    }
    return to_string(total);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        string main1 = "", main2 = "";
        int size_b = b.size(), i = 0, j = 0, size_a = a.size();
        while (i < size_b)
        {
            string temp_bin = "";
            while (b[i] != '.' and i < size_b)
            {
                temp_bin.push_back(b[i]);
                i++;
            }
            i++;
            string temp_num = "";
            while (a[j] != '.' and j < size_a)
            {
                temp_num.push_back(a[j]);
                j++;
            }
            j++;
            main1 += temp_num;
            main1.push_back('.');
            main2 += convertDecimal(temp_bin);
            main2.push_back('.');
        }
        main1.pop_back();
        main2.pop_back();
        if (main1 == main2)
            cout << "Case " << ++cs << ": " << "Yes" << '\n';
        else
            cout << "Case " << ++cs << ": " << "No" << '\n';
    }
    return 0;
}
