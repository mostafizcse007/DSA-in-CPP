#include <iostream>
#include <string>
using namespace std;
string MinizeNum(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '4')
            continue;
        if (str[i] == '5')
            str[i] = '4';
        else if (str[i] == '6')
            str[i] = '3';
        else if (str[i] == '7')
            str[i] = '2';
        else if (str[i] == '8')
            str[i] = '1';
        else if (str[i] == '9' && i != 0)
            str[i] = '0';
    }
    return str;
}
int main()
{
    string str;
    cin >> str;
    cout << MinizeNum(str) << endl;
    return 0;
}