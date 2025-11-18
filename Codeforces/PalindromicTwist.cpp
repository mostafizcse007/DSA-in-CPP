#include <bits/stdc++.h>
using namespace std;
bool palindromicTwist(vector<char> &arr)
{
    map<char, char> mp1;
    for (char i = 'a'; i <= 'y'; i++)
        mp1[i] = char(i + 1);
    mp1['z'] = 'y';
    map<char, char> mp2;
    for (char i = 'b'; i <= 'z'; i++)
        mp2[i] = char(i - 1);
    mp2['a'] = 'b';
    int low = 0, high = arr.size() - 1;
    while (low < high)
    {
        char x = arr[low];
        char y = arr[high];
        if ((x == y) || (mp1[x] == mp2[y]) || (mp1[y] == mp2[x]))
        {
            low++;
            high--;
        }
        else
            return 0;
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (palindromicTwist(arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}