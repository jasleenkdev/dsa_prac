#include <vector>
#include <unordered_map>
#include <iostream> 
using namespace std;
 
// class Solution{
//     int func(int ind, vector<int> &heights, int k){
//         if(ind == 0) return 0;
//         int minStep = INT_MAX; 
//         for(int j = 1; j <= k; j++){
//             if (ind - j >= 0){
//                 int jump = func(ind - j, heights, k) + abs(heights[ind] - heights[ind - j]); 
//                 minStep = min(jump, minStep);
//             }
//         }
//         return minStep;
//     }
//     public:
//     int frogJump(vector<int> &heights, int k){
//         int ind = heights.size() - 1;
//         return func(ind, heights, k);
//     }
// };


// tc -> o(n) * k
// if there are k jumps 
// sc -> o(n) + o(n)
// recursion stack space and memoisation 

// class Solution {
//     private:
//     int func(int ind, vector<int> &heights, int k, vector<int>& dp){
//         if(ind == 0) return 0; 
//         if (dp[ind] != -1) return dp[ind]; 
//         int minStep = INT_MAX; 
//         for(int j = 1; j <= k; j++){
//             if(ind - j> 0){
//                 int jump = func(ind-j, heights, k, dp) + abs(heights[ind] - heights[ind - j]);
//                 minStep = min(jump, minStep);
//             }
//         }
//         return dp[ind] = minStep;
//     }
//     public: 
//     int frogJump(vector<int> &heights, int k){
//         int ind = heights.size() - 1; 
//         vector<int> dp(ind + 1, -1);
//         return func(ind, heights, k, dp);
//     }
// };

class Solution{
    int frogJump(vector<int> &heights, int k){
        int ind = heights.size(); 
        vector<int> dp(ind + 1, -1);
        dp[0] = 0; 
        for(int i = 0; i < ind; i++){
            int minStep = INT_MAX; 
            for(int j = 0; j < k; j++){
                if (i - j > 0){
                    int jump = dp[i - j] + abs(heights[i] - heights[i-j]); 
                    minStep = min(jump, minStep); 
                }
            }
            dp[i] = minStep; 
        }
        return dp[ind-1]; 
    }

};