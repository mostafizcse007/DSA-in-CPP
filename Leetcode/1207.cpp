#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++; // Mapping all the frequencies.
    }
    set<int> uni;
    for (int i = 0; i < n; i++)
    {
        uni.insert(mpp[arr[i]]); // insert all the unique elements.
    }
    if (uni.size() == mpp.size())
        cout << true;
    else
        cout << false;
    return 0;
}

// class Solution {
// public:
//     bool uniqueOccurrences(vector<int>& arr) {
//         unordered_map<int,int>mpp;
//         for(int i=0;i<arr.size();i++)
//         {
//             mpp[arr[i]]++;
//         }
//         set<int>uni;
//         for(int i=0;i<arr.size();i++)
//         {
//             uni.insert(mpp[arr[i]]);
//         }
//         if(mpp.size()==uni.size())
//         return 1;
//         return 0;
//     }
// };