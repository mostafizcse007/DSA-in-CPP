#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long factorial(int num)
{
    long long fact = 1;
    for (int i = 2; i <= num; i++)
    {
        if (fact > 1e18)
            return 1e18;
        fact *= i;
    }
    return fact;
}

string findPer(string s, long long k)
{
    int n = s.size();
    sort(s.begin(), s.end());
    string final = "";

    vector<bool> track(n, false);

    --k;
    for (int i = 0; i < n; i++)
    {
        long long fact = factorial(n - 1 - i);

        int index = k / fact;
        if (index >= n)
            return "-1";
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (!track[j])
            {
                if (count == index)
                {
                    final += s[j];
                    track[j] = 1;
                    break;
                }
                count++;
            }
        }
        k = k % fact;
    }

    return final;
}

int main()
{
    int n;
    long long k;
    string s;
    cin >> n >> k >> s;
    cout << findPer(s, k) << endl;

    return 0;
}
