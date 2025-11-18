#include <bits/stdc++.h>
using namespace std;
int numSize(int n)
{
    return log10(n) + 1;
}
vector<int> roundSumNum(int n)
{
    vector<int> ans;
    while (n)
    {
        int ex = numSize(n);
        if (ex == 5)
        {
            int temp = n % 10000;
            ans.push_back(n - temp);
            n = temp;
        }
        else if (ex == 4)
        {
            int temp = n % 1000;
            ans.push_back(n - temp);
            n = temp;
        }
        else if (ex == 3)
        {
            int temp = n % 100;
            ans.push_back(n - temp);
            n = temp;
        }
        else if (ex == 2)
        {
            int temp = n % 10;
            ans.push_back(n - temp);
            n = temp;
        }
        else if (ex == 1 && n != 0)
        {

            ans.push_back(n);
            n = 0;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> res = roundSumNum(n);
        cout << res.size() << endl;
        for (auto it : res)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}