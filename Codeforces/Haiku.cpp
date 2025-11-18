#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check_string(vector<string> &arr) {
    vector<int> list;
    for (auto it : arr) {
        int cnt = 0;
        for (auto x : it) {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                cnt++;
        }
        list.push_back(cnt);
    }
    if (list[0] == 5 && list[1] == 7 && list[2] == 5)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);c
    cin.tie(NULL);

    vector<string> arr(3);

    for (int i = 0; i < 3; i++)
        getline(cin, arr[i]);

    if (check_string(arr))
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}