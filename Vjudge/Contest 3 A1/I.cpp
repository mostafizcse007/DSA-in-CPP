#include <bits/stdc++.h>
using namespace std;

int main()
{
    int shift;
    cin >> shift;
    string str;
    cin.ignore();
    getline(cin, str);

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != ' ')
        {
            char temp = str[i];
            temp = (temp - 'a' - shift + 26) % 26 + 'a';
            str[i] = temp;
        }
    }

    cout << str << endl;
    return 0;
}