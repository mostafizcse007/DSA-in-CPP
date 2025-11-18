#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &arr)
{
    int element, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            element = arr[i];
            count++;
        }
        else if (element == arr[i])
            count++;
        else
            count--;
    }
    int check = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == element)
            check++;
    }
    if (check > arr.size() / 2)
        return element;
    return -1;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        arr.emplace_back(el);
    }
    cout << majorityElement(arr) << endl;
    return 0;
}