#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int countValidTriangle(vector<int> &arr)
{
    int cnt = 0;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        int k = i + 2;
        for (int j = i + 1; j < n - 1; j++)
        {
            while (k < n && arr[i] + arr[j] > arr[k])
                k++;
            cnt += k - j - 1;
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countValidTriangle(arr) << endl;
    return 0;
}