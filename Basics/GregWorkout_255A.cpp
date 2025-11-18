#include <bits/stdc++.h>
using namespace std;
int main()
{
    int chest = 0, bicep = 0, back = 0;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i % 3 == 0)
        {
            chest += arr[i];
        }
        else if (i % 3 == 1)
        {
            bicep += arr[i];
        }
        else
        {
            back += arr[i];
        }
    }
    if (chest > bicep && chest > back)
        cout << "chest" << endl;
    else if (bicep > chest && bicep > back)
        cout << "biceps" << endl;
    else
        cout << "back" << endl;
    return 0;
}