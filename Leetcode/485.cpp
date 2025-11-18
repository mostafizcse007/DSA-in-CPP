

// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int count_1 = 0, count_2 = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == 1) {
//                 count_1++;
//                 if (count_1 > count_2)
//                     count_2 = count_1;
//             } else
//                 count_1 = 0;
//         }
//         return count_2;
//     }
// };