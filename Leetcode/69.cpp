

// class Solution {
// public:
//     int binarySearch(int n) {
//         int st = 0, en = n;
//         long long int ans = -1;
//         while (st <= en) {
//             long long int mid = st + (en - st) / 2;
//             long long int sq = mid * mid;
//             if (sq == n)
//                 return mid;
//             else if (sq > n)
//                 en = mid - 1;
//             else {
//                 ans = mid;
//                 st = mid + 1;
//             }
//         }
//         return ans;
//     }
//     int mySqrt(int x) { return binarySearch(x); }
// };