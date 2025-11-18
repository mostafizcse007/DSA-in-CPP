#include <iostream>
#include <vector>
using namespace std;

int countHelped(vector<int> &arr, int n, int k)
{
    int robinGold = 0;
    int peopleHelped = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= k)
        {
            robinGold += arr[i];
        }
        else if (arr[i] == 0 && robinGold > 0)
        {
            robinGold--;
            peopleHelped++;
        }
    }

    return peopleHelped;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << countHelped(arr, n, k) << endl;
    }
    return 0;
}
