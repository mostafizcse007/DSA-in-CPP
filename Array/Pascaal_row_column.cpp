#include <bits/stdc++.h>
using namespace std;
int nCr(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
int main()
{
    int row, col;
    cin >> row >> col;
    cout << nCr(row - 1, col - 1) << endl;
    return 0;
}