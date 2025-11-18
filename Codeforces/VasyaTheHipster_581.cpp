#include <bits/stdc++.h>
using namespace std;
int main()
{
    int red, blue;
    cin >> red >> blue;
    int mini = min(red, blue);
    int maxi = max(red, blue);
    cout << mini << " " << (maxi - mini) / 2;
    return 0;
}