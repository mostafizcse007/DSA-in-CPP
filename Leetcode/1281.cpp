#include <iostream>
using namespace std;
int diff(int n)
{
    int product = 1, sum = 0;
    while (n != 0)
    {
        product *= n % 10;
        sum += n % 10;
        n /= 10;
    }
    return product - sum;
}
int main()
{
    int n;
    cin >> n;
    cout << diff(n) << endl;
    return 0;
}

// Leetcode
//  class Solution {
//  public:
//      int subtractProductAndSum(int n) {
//          int product = 1, sum = 0;
//      while (n != 0)
//      {
//          product *=n % 10;
//          sum += n % 10;
//          n /=10;
//      }
//      return product - sum;

//     }
// };