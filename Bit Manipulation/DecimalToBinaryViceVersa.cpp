#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string decimal2Binary(int n)
{
    if (n == 0)
        return "0";
    string ans = "";
    while (n > 0)
    {
        ans = char('0' + (n & 1)) + ans;
        n >>= 1;
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << decimal2Binary(n) << endl;
    return 0;
}