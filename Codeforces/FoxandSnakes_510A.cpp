#include <iostream>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    for (int i = 1; i <= row; i++)
    {
        if (i % 2 == 0)
        {
            if (i % 4 == 0)
            {
                cout << "#";
                for (int j = 1; j < col; j++)
                {
                    cout << ".";
                }
                cout << endl;
            }
            else
            {
                for (int j = 1; j < col; j++)
                {
                    cout << ".";
                }
                cout << "#" << endl;
            }
        }
        else
        {
            for (int j = 1; j <= col; j++)
            {
                cout << "#";
            }
            cout << endl;
        }
    }
    return 0;
}