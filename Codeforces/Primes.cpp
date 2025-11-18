#include <iostream>
#include <vector>
using namespace std;
void checkAdd(vector<int> &arr, int n)
{
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        int sum = arr[i] + arr[j];
        if (sum == n)
        {
            cout << arr[i] << " " << arr[j] << endl;
            return;
        }
        else if (sum > n)
            j--;
        else
            i++;
    }
    cout << "-1" << endl;
}
vector<bool> createSeive(int n)
{
    vector<bool> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;
    for (int i = 4; i <= n; i += 2)
        primes[i] = false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (primes[i])
        {
            for (int j = i * i; j <= n; j += 2 * i)
                primes[j] = false;
        }
    }
    return primes;
}
int main()
{
    int n;
    cin >> n;
    vector<bool> primes = createSeive(n);
    vector<int> ans;
    for (int i = 2; i <= n; i++)
    {
        if (primes[i])
            ans.push_back(i);
    }
    checkAdd(ans, n);
    return 0;
}
