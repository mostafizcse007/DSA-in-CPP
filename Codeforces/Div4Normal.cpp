#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        reverse(str.begin(), str.end());
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'p')
                str[i] = 'q';
            else if (str[i] == 'q')
                str[i] = 'p';
        }
        cout << str << endl;
    }
    return 0;
}