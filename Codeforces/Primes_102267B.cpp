#include <bits/stdc++.h>
using namespace std;
const int N = 10000000;
vector<bool> seive(N + 1, true);
vector<int> checkPrimeSum(vector<int> &arr, int num)
{
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        long long sum = arr[i] + arr[j];
        if (sum == num)
            return {arr[i], arr[j]};
        else if (sum > num)
            j--;
        else
            i++;
    }
    return {-1};
}

int main()
{
    seive[0] = false;
    seive[1] = false;
    vector<int> primes;
    int x;
    cin >> x;
    for (int i = 2; i * i <= x; i++)
    {
        if (seive[i])
        {
            for (int j = i * i; j <= x; j += i)
            {
                seive[j] = false;
            }
        }
    }

    for (int i = 2; i <= x; i++)
    {
        if (seive[i])
            primes.push_back(i);
    }

    vector<int> result = checkPrimeSum(primes, x);

    for (auto it : result)
        cout << it << " ";
    cout << endl;

    return 0;
}
