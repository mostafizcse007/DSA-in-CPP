#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int cnt = 0;
    while (t--)
    {
        string s;
        cin >> s;
        if (s == "++X" || s == "X++")
            cnt++;
        else
            cnt--;
    }
    cout << cnt << endl;
    return 0;
}