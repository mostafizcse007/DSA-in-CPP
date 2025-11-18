#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int part_1 = 0, part_2 = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        part_1 += a;
        part_2 += b;
    }

    if (part_1 > part_2)
        cout << "Mishka" << '\n';
    else if (part_2 > part_1)
        cout << "Chris" << '\n';
    else
        cout << "Friendship is magic!^^" << '\n';
    return 0;
}