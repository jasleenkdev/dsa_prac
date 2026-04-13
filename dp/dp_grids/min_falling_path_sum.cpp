#include <vector>
#include <unordered_map>
#include <iostream> 
using namespace std; 

// class Solution{
//     int func(int i, int j, int m, vector<vector<int>> &matrix){
//         if(j < 0 || j >= m) return 1e9; 
//         if (i == 0) return matrix[0][j];
//         int up = matrix[i][j] + func(i-1, j, m, matrix);
//         int leftDiagnol = matrix[i][j] + func(i-1, j-1,m,matrix);
//         int rightDiagnol = matrix[i][j] + func(i-1, j+1, m, matrix); 
//         return min(up, min(leftDiagnol, rightDiagnol));
//     }
//     public: 
//     int minFallingPathSum(vector<vector<int>> &matrix){
//         int n = matrix.size(); 
//         int m = matrix[0].size();
//         int mini = INT_MAX; 
//         for(int j = 0; j < m; j++){
//             int ans = func(n-1, j, m, matrix); 
//             mini = min(mini, ans); 
//         }
//         return mini; 
//     }
// };

// class Solution{
//     private:
//     int func(int i, int j, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
//         if(j < 0 || j >= m) return 1e9; 
//         if (i == 0) return matrix[0][j]; 
//         if (dp[i][j] != -1) return dp[i][j];
//         int up = matrix[i][j] + func(i-1, j, m, matrix, dp); 
//         int leftDiagnol = matrix[i][j] + func(i-1, j-1, m, matrix, dp); 
//         int rightDiagnol = matrix[i][j] + func(i-1, j +1, m, matrix, dp);
//         return dp[i][j] = min(up, min(leftDiagnol, rightDiagnol));
//     }
//     public: 
//     int minFallingPathSum(vector<vector<int>> &matrix){
//         int n = matrix.size();
//         int m = matrix[0].size(); 
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         int mini = INT_MAX; 
//         for(int j = 0; j < m; j++){
//             int ans = func(n-1, j, m, matrix, dp); 
//             mini = min(mini, ans);
//         }
//         return mini; 
//     }
// };

// class Solution{
//     public: 
//     int minFallingPathSum(vector<vector<int>> &matrix){
//         int n = matrix.size(); 
//         int m = matrix[0].size(); 
//         vector<vector<int>> dp(n, vector<int>(m, 0)); 
//         for(int j = 0; j < m; j++){
//             dp[0][j] = matrix[0][j]; 
//         }
//         for(int i = 1; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 int up = matrix[i][j] + dp[i-1][j]; 
//                 int leftDiagnol = matrix[i][j]; 
//                 if (j -1 >= 0) {
//                     leftDiagnol += dp[i-1][j-1]; 
//                 } else {
//                     leftDiagnol += 1e9; 
//                 }
//                 int rightDiagnol = matrix[i][j]; 
//                 if (j + 1 < m){
//                     rightDiagnol += dp[i - 1][j + 1]; 
//                 } else {
//                     rightDiagnol += 1e9; 
//                 }
//                 dp[i][j] = min(up, min(leftDiagnol, rightDiagnol)); 
//             }
//         }
//         int mini = INT_MAX; 
//         for(int j = 0; j < m; j++){
//             mini = min(mini, dp[n-1][j]); 
//         }
//         return mini; 
//     }
// };

class Solution{
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n = matrix.size(); 
        int m = matrix[0].size(); 
        vector<int> prev(m, 0); 
        vector<int> cur(m, 0); 
        for(int j = 0; j < m; j++){
            prev[j] = matrix[0][j]; 
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = matrix[i][j] + prev[j]; 
                int leftDiagnol = matrix[i][j]; 
                if(j - 1 >= 0){
                    leftDiagnol += prev[j-1]; 
                } else {
                    leftDiagnol += 1e9; 
                }
                int rightDiagnol = matrix[i][j]; 
                if(j + 1 < m){
                    rightDiagnol += prev[j+1]; 
                } else {
                    rightDiagnol += 1e9;
                }
                cur[j] = min(up, min(leftDiagnol, rightDiagnol));
            }
            prev = cur;
        }
        int mini = INT_MAX; 
        for(int j = 0; j < m; j++){
            mini = min(mini, prev[j]); 
        }
        return mini;
    }
};