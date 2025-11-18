#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cntMoves(vector<int> &arr)
{
    vector<int> oddArr, evenArr;
    for (auto it : arr)
    {
        if (it & 1)
            oddArr.push_back(it);
        else
            evenArr.push_back(it);
    }
    sort(oddArr.rbegin(), oddArr.rend());
    sort(evenArr.rbegin(), evenArr.rend());
    int oddSize = oddArr.size(), evenSize = evenArr.size();
    if (abs(oddSize - evenSize) <= 1)
        return 0;
    if (oddSize > evenSize)
    {
        int sum = 0;
        int temp = evenSize + 1;
        for (int i = temp; i < oddSize; i++)
            sum += oddArr[i];
        return sum;
    }
    else
    {
        int sum = 0;
        int temp = oddSize + 1;
        for (int i = temp; i < evenSize; i++)
            sum += evenArr[i];
        return sum;
    }
    return 69;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &it : arr)
        cin >> it;
    cout << cntMoves(arr) << endl;
    return 0;
}