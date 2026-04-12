#include <vector>
#include <unordered_map>
#include <iostream> 
using namespace std;

// class Solution{
//     private: 
//     int func(int i, int j, vector<vector<int>>& matrix){
//         if(i >= 0 || j >= 0 || matrix[i][j] == 1) return 0; 
//         if (i == 0 && j == 0) return 1; 
//         if (i < 0 && j < 0) return 0; 
//         int up = func(i-1, j, matrix); 
//         int left = func(i, j-1, matrix); 
//         return up + left; 
//     }
//     public: 
//     int uniquePathWithObstacle(vector<vector<int>> matrix){
//         int m = matrix.size(); 
//         int n = matrix[0].size(); 
//         return func(m-1, n-1, matrix); 
//     }
// };

// class Solution{
//     private: 
//     int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         if (i < 0 || j < 0 || matrix[i][j] ==1 ) return 0; 
//         if (i == 0 && j == 0) return 1;
//         if (dp[i][j] != -1) return dp[i][j]; 
//         int up = func(i-1, j, matrix, dp); 
//         int left = func(i, j-1, matrix, dp); 
//         return dp[i][j] = up + left; 
//     }
//     public:
//     int uniquePathWithObstacle(vector<vector<int>>& matrix){
//         int m = matrix.size();
//         int n= matrix[0].size(); 
//         vector<vector<int>> dp(m, vector<int>(n, -1)); 
//         return func(m-1, n-1, matrix, dp); 
//     }
// };

// class Solution{
//     private:
//     int func(int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if (matrix[i][j] == 1){
//                     dp[i][j] = 0; 
//                     continue;
//                 }
//                 if(i == 0 && j == 0){
//                     dp[i][j] = 1; 
//                     continue; 
//                 }
//                 int up = 0;
//                 int left = 0; 
//                 if (i > 0)  up = dp[i-1][j]; 
//                 if (j > 0)  left = dp[i][j-1]; 
//                 return dp[i][j] = up + left; 
//             }
//         }
//         return dp[m-1][n-1];
//     }
//     public: 
//     int uniquePathWithObstacle(vector<vector<int>>& matrix){
//         int m = matrix.size(); 
//         int n = matrix[0].size(); 
//         vector<vector<int>> dp(m, vector<int>(n, 0)); 
//         return func(m, n, matrix, dp); 
//     }
// };

class Solution{
    private: 
    int func(int m, int n, vector<vector<int>>& matrix){
        vector<int> prev(n, 0), curr(n, 0); 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    curr[j] = 0; 
                    continue; 
                }
                if (i == 0 && j == 0){
                    curr[j] = 1;
                    continue; 
                } 
                int up = 0;
                int left = 0;
                if (i > 0) up = prev[j];
                if (j > 0) left = curr[j-1];
                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n-1];
    }
    public: 
    int uniquePathsWithObstacles(vector<vector<int>>& matrix){
        int m = matrix.size(); 
        int n = matrix[0].size(); 
        return func(m, n, matrix);
    }
};