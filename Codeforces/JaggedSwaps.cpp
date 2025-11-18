#include <iostream>
#include <vector>
using namespace std;
bool SortPermutation(vector<int> &arr)
{
    int n = arr.size();
    if (arr[0] == 1)
        return 1;
    return 0;
}
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
        if (SortPermutation(arr))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}