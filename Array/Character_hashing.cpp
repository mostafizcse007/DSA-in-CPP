#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }
    int que;
    cin >> que;
    while (que--)
    {
        char ch;
        cin >> ch;
        cout << ch << " " << hash[ch] << endl;
    }
    return 0;
}