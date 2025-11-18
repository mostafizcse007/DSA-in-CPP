

// class Solution {
// public:
//     int romanToInt(string s) {
//         int count = 0;
//         for (int i = 0; i < s.size();) {
//             if (s[i] == 'I' && s[i + 1] == 'V') {
//                 count += 4;
//                 i += 2;
//             }

//             else if (s[i] == 'I' && s[i + 1] == 'X') {
//                 count += 9;
//                 i += 2;
//             } else if (s[i] == 'X' && s[i + 1] == 'L') {
//                 count += 40;
//                 i += 2;
//             } else if (s[i] == 'X' && s[i + 1] == 'C') {
//                 count += 90;
//                 i += 2;
//             } else if (s[i] == 'C' && s[i + 1] == 'D') {
//                 count += 400;
//                 i += 2;
//             } else if (s[i] == 'C' && s[i + 1] == 'M') {
//                 count += 900;
//                 i += 2;
//             } else if (s[i] == 'I') {
//                 count += 1;
//                 i++;
//             } else if (s[i] == 'V') {
//                 count += 5;
//                 i++;
//             }

//             else if (s[i] == 'X') {
//                 count += 10;
//                 i++;
//             }

//             else if (s[i] == 'L') {
//                 count += 50;
//                 i++;
//             }

//             else if (s[i] == 'C') {
//                 count += 100;
//                 i++;
//             }

//             else if (s[i] == 'D') {
//                 count += 500;
//                 i++;
//             }

//             else if (s[i] == 'M') {
//                 count += 1000;
//                 i++;
//             }
//         }
//         return count;
//     }
// };