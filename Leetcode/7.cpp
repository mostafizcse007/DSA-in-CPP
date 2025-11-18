#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin >> x;
    int ans = 0;
    while (x != 0)
    {
        int last = x % 10;
        if ((ans > INT_MAX / 10) || (ans < INT_MIN))
        {
            return 0;
        }
        ans = ans * 10 + last;
        x /= 10;
    }
}

// Leetcode
//  class Solution {
//  public:
//      int reverse(int x) {
//          int ans=0;
//          while(x!=0)
//          {
//              int last=x%10;
//              if((ans>INT_MAX/10)||(ans<INT_MIN/10))
//              {
//                  return 0;
//              }
//              ans=ans*10+last;
//              x/=10;
//          }
//          return ans;
//      }
//  };