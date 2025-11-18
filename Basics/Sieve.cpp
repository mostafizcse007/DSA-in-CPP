#include <iostream>
#include <vector>
using namespace std;
int N = 1000000;
bool seive[1000001];
void createSeive()
{
    for (int i = 2; i <= N; i++)
        seive[i] = true;
    for (int i = 2; i * i <= N; i++)
    {
        if (seive[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                seive[j] = false;
        }
    }
}
int main()
{
    createSeive();
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        if (seive[num] == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}