#include <iostream>
using namespace std;
int getDifference(int hour, int min)
{
    int h = 24, m = 60;
    // int diff=0;
    if (min == 0)
        min += 60;
    if (hour == 0)
        hour += 24;
    int diff_min = m - min;
    int diff_hour = h - hour;
    diff_hour *= 60;
    return diff_hour + diff_min;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int hour, min;
        cin >> hour >> min;
        cout << getDifference(hour, min) << endl;
    }
    return 0;
}