#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool checkPangram(vector<char> &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    unordered_set<char> st(str.begin(), str.end());
    if (st.size() == 26)
        return 1;
    return 0;
}
int main()
{
    int n;
    cin >> n;
    vector<char> str(n);
    for (int i = 0; i < n; i++)
        cin >> str[i];
    if (checkPangram(str))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}