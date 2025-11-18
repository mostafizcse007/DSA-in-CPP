

// class Solution {
// public:
//     int first(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1, ans = -1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] == target) {
//                 ans = mid;
//                 right = mid - 1;
//             } else if (target > nums[mid])
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }
//         return ans;
//     }

//     int last(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1, ans = -1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] == target) {
//                 ans = mid;
//                 left = mid + 1;
//             } else if (target > nums[mid])
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }
//         return ans;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         int a = first(nums,target);
//         int b = last(nums,target);
//         return {a,b};
//     }
// };