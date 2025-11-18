#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int beef, patty, cutlet, hamB, chiB;
        cin >> beef >> patty >> cutlet >> hamB >> chiB;
        int total = 0;
        while (beef > 1)
        {
            if (((chiB >= hamB) && cutlet) || (!patty && cutlet))
            {
                if ((2 * cutlet) <= beef)
                {
                    beef -= (2 * cutlet);
                    total += (cutlet * chiB);
                    cutlet = 0;
                }
                else
                {
                    total += ((beef / 2) * chiB);
                    break;
                }
            }
            else if (patty)
            {
                if ((2 * patty) <= beef)
                {
                    beef -= (2 * patty);
                    total += (patty * hamB);
                    patty = 0;
                }
                else
                {
                    total += ((beef / 2) * hamB);
                    break;
                }
            }
            else
                break;
        }
        cout << total << endl;
    }
    return 0;
}
