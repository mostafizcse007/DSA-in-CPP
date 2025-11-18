#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr(3);
    for (int i = 0; i < 3; i++)
        cin >> arr[i];
    if (arr[1] >= arr[0] && arr[2] >= arr[0])
        cout << "Yes" << endl;
    else
        cout << "NO" << endl;
    return 0;
}