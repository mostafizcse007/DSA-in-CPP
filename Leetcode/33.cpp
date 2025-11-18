

// class Solution {
// public:
//     int getpivot(vector<int>&nums)
//     {
//         int s=0,e=nums.size() -1;
//         while(s<e)
//         {
//             int m=s+(e-s)/2;
//             if(nums[m]>=nums[0])
//             s=m+1;
//             else
//             e=m;
//         }
//         return s;
//     }
//     int binaryS(vector<int>&nums,int s, int e, int target)
//     {
//         int st = s, en =e;
//         while(st<=en)
//         {
//             int mi = st +  (en - st)/2;
//             if(nums[mi]==target)
//             return mi;
//             else if(target>nums[mi])
//             st=mi+1;
//             else
//             en=mi-1;
//         }
//         return -1;
//     }
//     int search(vector<int>& nums, int target) {
//         int pivot=getpivot(nums);
//         int size = nums.size();
//         if(target>=nums[pivot] && target<=nums[size-1])
//         return binaryS(nums,pivot,size-1,target);
//          return binaryS(nums,0,pivot-1,target);
//     }
// };