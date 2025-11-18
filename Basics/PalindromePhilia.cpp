#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int cnt = 0;
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
            cnt++;
        i++;
        j--;
    }
    cout << cnt << endl;
    return 0;
}