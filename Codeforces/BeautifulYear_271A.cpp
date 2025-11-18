#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int findYear(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    int year;
    cin >> year;
    vector<int> distinct;
    for (int i = 1023; i <= 9012; i++)
    {
        int num = i;
        unordered_set<int> st;
        while (num != 0)
        {
            int last = num % 10;
            num /= 10;
            st.insert(last);
        }
        if (st.size() == 4)
            distinct.push_back(i);
    }
    cout << findYear(distinct, year) << endl;
    return 0;
}