#include <vector>
#include <unordered_map>
#include <iostream> 
using namespace std;

// class Solution {
//     int func(int n, vector<int> &arr){
//         int pick = func(n - 2, arr) + arr[n];
//         int nonPick = func(n - 1, arr); 
//         return max(pick, nonPick);
//     }
//     public: 
//     int nonAdjacents(vector<int> &nums){
//         int n = nums.size(); 
//         return func(n, nums);
//     }
// };

// class Solution{
//     int func(int n, vector<int> &arr, vector<int>& dp){
//         if (n == 0) return arr[n]; 
//         if ( n < 0) return -1; 
//         if (dp[n] != -1) return dp[n]; 
//         int pick = arr[n] + func(n-2, arr, dp); 
//         int notpick = func(n-1, arr, dp);
//         return dp[n] = max(pick, notpick); 
//     }
//     public: 
//     int nonAdjacent(vector<int> nums){
//         int n = nums.size() - 1; 
//         vector<int> dp(n + 1, -1); 
//         return func(n, nums, dp)
//     }

// };

// class Solution{
//     int nonAdjacent(vector<int>& nums){
//         int ind = nums.size(); 
//         vector<int> dp(ind, 0); 
//         dp[0] = nums[0]; 
//         for(int i = 1; i < ind; i++){
//             int pick = nums[i]; 
//             if(i > 1){
//                 pick += dp[i-2]; 
//             }
//             int nonPick = dp[i-1];
//             dp[i] = max(pick, nonPick); 
//         }
//         return dp[ind -1]; 
//     }
// }; 