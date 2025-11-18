#include <bits/stdc++.h>
using namespace std;
int minTaxi(vector<int> &arr)
{
    sort(arr.rbegin(), arr.rend());
    int i = 0, j = arr.size() - 1;
    int cnt = 0;
    while (i <= j)
    {
        if (i == j)
        {
            cnt++;
            break;
        }
        else if (arr[i] == 1)
        {
            cnt += ceil(double(j - i + 1) / 4);
            break;
        }
        else if ((arr[j] == 4) || (arr[i] == 3 && arr[j] == 3))
        {
            cnt += (j - i + 1);
            break;
        }
        else if (arr[i] == 2 && arr[j] == 2)
        {
            cnt += ceil(double(j - i + 1) / 2);
            break;
        }
        else if ((arr[i] == 3 && arr[j] == 1))
        {
            cnt++;
            i++;
            j--;
        }
        else if ((arr[i] == 4 && arr[j] == 3))
        {
            cnt += 2;
            i++;
            j--;
        }
        else if ((arr[i] == 3 && arr[j] == 2) || (arr[i] == 4 && arr[j] == 1) || (arr[i] == 3 && arr[j] == 3) || (arr[i] == 4 && arr[j] == 2))
        {
            cnt++;
            i++;
        }
        else if (arr[i] == 2 && arr[j] == 1)
        {
            if ((j - i) > 1 && arr[j - 1] == 1)
            {
                cnt++;
                i++;
                j -= 2;
            }
            else
            {
                cnt++;
                i++;
                j--;
            }
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
    cout << minTaxi(arr) << endl;
}