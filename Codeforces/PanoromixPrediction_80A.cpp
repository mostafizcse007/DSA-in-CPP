#include <bits/stdc++.h>
using namespace std;
const int N = 50;
bool seive[N + 1];
vector<int> store;
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
    for (int i = 2; i <= N; i++)
    {
        if (seive[i] == true)
            store.push_back(i);
    }
}
int main()
{
    createSeive();
    int num1, num2;
    cin >> num1 >> num2;
    int temp = -1;
    for (int i = 0; i <= N; i++)
    {
        if (store[i] > num1)
        {
            temp = i;
            break;
        }
    }
    if (store[temp] == num2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}