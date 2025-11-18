#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr(8);
    for (int i = 0; i < 8; i++)
        cin >> arr[i];
    int toast = arr[1] * arr[2];
    toast /= arr[6];
    int lime = arr[3] * arr[4];
    int salt = arr[5] / arr[7];
    int mini = INT_MAX;
    mini = min(mini, toast);
    mini = min(mini, lime);
    mini = min(mini, salt);
    mini /= arr[0];
    cout << mini << endl;
    return 0;
}