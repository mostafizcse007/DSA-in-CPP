#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<char> str(5);
        for (int i = 0; i < 5; i++)
            cin >> str[i];
        unordered_map<char, int> mpp;
        for (auto it : str)
            mpp[it]++;
        int maxi = -1;
        char max_char = '\0';
        for (auto it : mpp)
        {
            if (it.second > maxi)
            {
                maxi = it.second;
                max_char = it.first;
            }
        }
        cout << max_char << endl;
    }
    return 0;
}