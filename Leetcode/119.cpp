

// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         rowIndex += 1;
//         long long temp = 1;
//         vector<int> res;
//         res.push_back(1);
//         for (int i = 1; i < rowIndex; i++) {
//             temp = temp * (rowIndex - i) / i;
//             res.push_back(temp);
//         }
//         return res;
//     }
// };