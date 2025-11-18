#include <bits/stdc++.h>
using namespace std;

void printDigits(int n)
{
    if (n < 10)
    {
        cout << n << " ";
        return;
    }
    printDigits(n / 10);
    cout << n % 10 << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        if (N == 0)
        {
            cout << "0\n";
        }
        else
        {
            printDigits(N);
            cout << '\n';
        }
    }

    return 0;
}
