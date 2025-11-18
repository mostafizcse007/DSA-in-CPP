// #include <bits/stdc++.h>
// using namespace std;
// int minTime(int n, int x, int y)
// {
//     int cnt = 0;
//     if (x >= y)
//         return (n / y) + (n % y);

//     else
//     {
//         n = n / x;
//         cnt = cnt + 1;
//         while (n)
//         {
//             cnt++;
//             n /= y;
//         }
//     }
//     return cnt;
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int x, y;
//         cin >> x >> y;
//         cout << minTime(n, x, y) << endl;
//     }
//     return 0;
// }
