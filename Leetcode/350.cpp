

// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int,int>mpp;
//         vector<int> res;
//         for(auto it: nums1)
//             mpp[it]++;

//         for(auto it:nums2)
//         {
//             if(mpp[it]>0)
//             {
//                 res.emplace_back(it);
//                 mpp[it]--;
//             }
//         }
//         return res;
//     }
// };