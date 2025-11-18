#include <iostream>
using namespace std;
int findEvenSum(int n)
{
    if (n <= 2)
        return 2;
    return n + findEvenSum(n - 2);
}
int main()
{
    int n;
    cin >> n;
    cout << findEvenSum(n);
    return 0;
}