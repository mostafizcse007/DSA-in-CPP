

// class Solution {
// public:
//     vector<int> generateRow(int N) {
//         int res = 1;
//         vector<int> temp;
//         temp.emplace_back(1);
//         for (int i = 1; i < N; i++) {
//             res = res * (N - i) / i;
//             temp.emplace_back(res);
//         }
//         return temp;
//     }
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> final;
//         for (int i = 1; i <= numRows; i++) {
//             final.emplace_back(generateRow(i));
//         }
//         return final;
//     }
// };