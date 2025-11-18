#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int count = 0;
    while (num != 0)
    {
        if (num & 1)
        {
            count++;
        }
        num >>= 1;
    }
    cout << count;
    return 0;
}

// Leetcode
// class Solution {
// public:
//     int hammingWeight(uint32_t n) {
//         int count=0;
//         while(n!=0)
//         {
//             if(n&1)
//             {
//                 count++;
//             }
//             n>>=1;
//         }
//         return count;
//     }
// };