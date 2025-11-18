#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double sq = sqrt(5);
    double fibo = pow((1 + sq) / 2, n) - pow((1 - sq) / 2, n);
    double ans = (int)round(fibo / sq);
    cout << ans;
    return 0;
}

// class Solution {
// public:
//     int fib(int n) {
//         double sq = sqrt(5);
//     double fibo = pow((1 + sq) / 2, n) - pow((1 - sq) / 2, n);
//     return (int)round(fibo/sq);
//     }
// };