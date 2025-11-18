#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int max_1 = INT_MIN, max_0 = INT_MIN, cnt_1 = 0, cnt_0 = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '1')
        {
            cnt_1++;
            cnt_0 = 0;
        }

        else if (str[i] == '0')
        {
            cnt_0++;
            cnt_1 = 0;
        }
        max_0 = max(max_0, cnt_0);
        max_1 = max(max_1, cnt_1);
    }
    for (int i = 0; i < str.size(); i++)
    {
    }
    if (max_0 >= 7 || max_1 >= 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}