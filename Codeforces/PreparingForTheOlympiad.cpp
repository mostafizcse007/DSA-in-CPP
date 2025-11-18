#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr1(n), arr2(n);
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < n; i++)
            cin >> arr2[i];
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr1[i] > arr2[i + 1])
                sum += (arr1[i] - arr2[i + 1]);
        }
        sum += arr1[n - 1];
        cout << sum << endl;
    }
    return 0;
}