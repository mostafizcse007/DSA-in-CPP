#include <iostream>
using namespace std;
int main()
{
    int test;
    cin >> test;
    for (int i = 0; i < test; i++)
    {
        int response, max = 0, check;
        cin >> response;
        int arr[response][2];
        for (int j = 0; j < response; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cin >> arr[j][k];
            }
        }
        for (int j = 0; j < response; j++)
        {
            if (arr[j][0] <= 10)
            {
                if (arr[j][1] > max)
                {
                    max = arr[j][1];
                    check = j;
                }
            }
        }
        cout << check + 1 << endl;
    }
    return 0;
}