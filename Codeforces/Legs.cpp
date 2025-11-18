#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int legs;
        int ch = 0, co = 0;
        cin >> legs;
        while (legs >= 2)
        {
            if (legs % 4 == 0)
            {
                co = legs / 4;
                break;
            }
            else
            {
                if (legs >= 2)
                {
                    legs -= 2;
                    ch++;
                }
                if (legs >= 4)
                {
                    legs -= 4;
                    ch++;
                }
            }
        }
        cout << ch + co << endl;
    }
}