#include <bits/stdc++.h>
using namespace std;
string addString(string &a, string &b)
{
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;
    string result = "";
    while (i >= 0 || j >= 0 || carry != 0)
    {
        int digit1 = 0, digit2 = 0;
        if (i >= 0)
        {
            digit1 = a[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            digit2 = b[j] - '0';
            j--;
        }
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.append(to_string(sum % 10));
    }
    int size = result.size();
    while (result[size - 1] == '0')
    {
        result.pop_back();
        size--;
    }
    reverse(result.begin(), result.end());
    return result;
}
string minSum(vector<int> &arr)
{
    string a = "", b = "";
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
            a.append(to_string(arr[i]));
        else
            b.append(to_string(arr[i]));
    }
    return addString(a, b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    string ans = minSum(arr);
    cout << ans;
    return 0;
}