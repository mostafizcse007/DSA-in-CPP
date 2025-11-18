#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &str)
{
    int i = 0, j = str.size() - 1;
    while (i <= j)
    {
        if (str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        string str;
        cin >> str;
        if (isPalindrome(str))
            cout << "Case " << i << ": Yes" << endl;
        else
            cout << "Case " << i << ": No" << endl;
        i++;
    }
    return 0;
}