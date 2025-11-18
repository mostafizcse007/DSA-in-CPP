#include <iostream>
#include <vector>
using namespace std;
vector<int> &prefixPrimes(vector<int> &arr)
{
    int n = arr.size();
    int cntTwo = 0, cntOne = 0;
    for (auto it : arr)
    {
        if (it == 1)
            cntOne++;
        else
            cntTwo++;
    }
    if (cntOne == n || cntTwo == n)
        return arr;
    arr.clear();
    if (cntTwo)
    {
        arr.push_back(2);
        cntTwo--;
    }
    if (cntOne)
    {
        arr.push_back(1);
        cntOne--;
    }
    while (cntTwo)
    {
        arr.push_back(2);
        cntTwo--;
    }
    while (cntOne)
    {
        arr.push_back(1);
        cntOne--;
    }
    return arr;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = prefixPrimes(arr);
    for (auto it : ans)
        cout << it << " ";
    cout << endl;
    return 0;
}