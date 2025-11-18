#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> str = {'1', '0', '1'};
    string binstring(str.begin(), str.end());
    int decimal = stoi(binstring, nullptr, 2);
    cout << decimal << endl;
    return 0;
}