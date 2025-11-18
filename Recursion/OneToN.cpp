#include <iostream>
using namespace std;
void printNum(int n, int &cnt)
{
    if (n == cnt)
        return;
    cnt++;
    cout << cnt << endl;
    printNum(n, cnt);
}
int main()
{
    int n, cnt = 0;
    cin >> n;
    printNum(n, cnt);
    return 0;
}