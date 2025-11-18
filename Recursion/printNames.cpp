#include <iostream>
using namespace std;
void printNames(int n, int &cnt)
{
    if (cnt == n)
        return;
    cout << "Antu" << endl;
    cnt++;
    printNames(n, cnt);
}
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    printNames(n, cnt);
    return 0;
}