#include <bits/stdc++.h>
using namespace std;
int powerNum(int n)
{
    string temp = to_string(n);
    reverse(temp.begin(), temp.end());
    int num = stoi(temp);
    return pow(num, num);
}
int main()
{
    int n;
    cin >> n;
    cout << powerNum(n) << endl;
    return 0;
}