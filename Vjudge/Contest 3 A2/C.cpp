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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        long long product = 1;
        for (auto it : arr)
            product *= it;
        cout << product << endl;
    }
    return 0;
}