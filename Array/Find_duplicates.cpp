#include <bits/stdc++.h>
using namespace std;
vector<int> findDupli(int arr[], int n)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    vector<int> uni;
    for (auto it : mpp)
    {
        if (it.second > 1)
            uni.emplace_back(it.first);
    }
    return uni;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> du = findDupli(arr, n);
    for (auto it : du)
    {
        cout << it << " ";
    }
}

// Bruteforce
//  int findDuplicate(vector<int> &arr)
//  {
//      for(int i=0;i<arr.size()-1;i++)
//      {
//          for(int j=i+1;j<arr.size();j++)
//          {
//              if(arr[i]==arr[j])
//              return arr[i];
//          }
//      }

// }

// Optimal
// int findDuplicate(vector<int> &arr)
// {
//     int ans=0;
//     for(int i=0;i<arr.size();i++)
//     {
//         ans^=arr[i];
//     }
// 	for(int i=1;i<arr.size();i++)
//     {
//         ans^=i;
//     }
//     return ans;
// }
