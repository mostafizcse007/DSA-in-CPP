#include <iostream>
#include <vector>
using namespace std;
long long maxChoclate(vector<int> &arr)
{
    int n = arr.size();
    long long sum = arr[n - 1], maxi = arr[n - 1] - 1;
    if (arr[n - 1] == 1)
        return 1;
    if (n == 1)
        return arr[0];
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] == 1)
        {
            sum += 1;
            break;
        }
        else if (arr[i] >= maxi)
        {
            sum += maxi;
            maxi--;
        }
        else if (arr[i] < maxi)
        {
            sum += arr[i];
            maxi = arr[i] - 1;
        }
        if (!maxi)
            return sum;
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxChoclate(arr) << endl;
    return 0;
}