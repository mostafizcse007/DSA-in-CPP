#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++)
        cin >> str[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == "Tetrahedron")
            cnt += 4;
        else if (str[i] == "Cube")
            cnt += 6;
        else if (str[i] == "Octahedron")
            cnt += 8;
        else if (str[i] == "Dodecahedron")
            cnt += 12;
        else
            cnt += 20;
    }
    cout << cnt << endl;
    return 0;
}