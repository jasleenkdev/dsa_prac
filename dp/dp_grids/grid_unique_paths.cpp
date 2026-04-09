#include <vector>
#include <unordered_map>
#include <iostream> 
using namespace std;
// class Solution{
//     private: 
//     int func(int i, int j){
//         if (i==0 && j == 0) return 1; 
//         if(i < 0 || j < 0) return 0; 
//         int up = func(i-1, j); 
//         int left = func(i, j-1); 
//         return up + left; 
//     }
//     public: 
//     int uniquepaths(int n, int m){
//         return func(m-1, n-1); 
//     }
// };

// class Solution{
//     int func(int i, int j, vector<vector<int>>& dp){
//         if (i == 0 && j == 0) return 1; 
//         if (i < 0|| j < 0) return 0; 
//         if (dp[i][j] != -1) return dp[i][j];
//         int up = func(i-1, j, dp);
//         int left = func(i, j-1, dp); 
//         return dp[i][j] = up + left; 
//     }

//     public: 
//     int uniquePath(int m, int n){
//         vector<vector<int>> dp(m, vector<int>(n, -1)); 
//         return func(m-1, n-1, dp); 
//     }
// };
// wrong
// class Solution{
//     public: 
//     int uniquePath(int m, int n){
//         vector<vector<int>> dp(m, vector<int>(n, -1)); 
//         if (m == 0 && n == 0) return 1; 
//         if (m < 0 || n < 0) return 0; 
//         if (dp[m][n] != -1) return dp[m][n]; 
//         if(m > 0){
//             int up = dp[m-1][n]; 
//         }
//         if(n > 0){
//             int left = dp[m][n-1]; 
//         }
//         return dp[m-1][n-1]; 
//     }
// };

// correct 
 class Solution{
    public: 
    int uniquePath(int m, int n){
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1; 
                } else {
                    int up = 0; 
                    int left = 0; 
                    if (i > 0) up = dp[i-1][j]; 
                    if (j > 0) left = dp[i][j-1]; 
                    return dp[i][j] = up + left; 
                }
            }
        }
        return dp[m-1][n-1]; 
    }
};
