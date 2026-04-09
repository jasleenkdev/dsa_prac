#include <vector>
#include <unordered_map>
#include <iostream> 
using namespace std;

// class Solution{
// private: 
//     int func(int day, int last, vector<vector<int>>& points){
//         if(day == 0){
//             int maxi = 0;
//             for(int i = 0; i <= 2; i++){
//                 if(i != last) maxi = max(maxi, points[0][i]);
//             }
//             return maxi; 
//         }
    
//     int maxi = 0; 

//     for (int i = 0; i <= 2; i++){
//         if(i != last){
//             int activity = points[day][i] + func(day - 1, i, points); 
//             maxi = max(maxi, activity); 
//         }
//     }
//     return maxi; 
//     }
//     public: 
//     int ninjaTraining(vector<vector<int>>& matrix){
//         int day = matrix.size() - 1;
//         int last = 3; 
//         return func(day, last, matrix);
//     }
// };

// class Solution{
//     private: 
//     int func(int day, int last, vector<vector<int>>& points, vector<vector<int>> &dp){
//         if(dp[last][day] != -1) return dp[last][day]; 
//         if (day == 0){
//             int maxi = 0;
//             for ( int i = 0; i <= 2; i++){
//                 if(i != last) maxi = max(maxi, points[0][i]);
//             }
//             return dp[last][day] = maxi;
//         }
    
//     int maxi = 0; 
//     for(int i= 0; i <= 2; i++){
//         if (i != last){
//             int activity = points[day][i] + func(day - 1, i, points, dp);
//             maxi = max(maxi, activity);
//         }
//     }
//         return dp[day][last] = maxi;
//     }
//     public: 
//     int ninjaTraining(vector<vector<int>>& matrix){
//         int day = matrix.size(); 
//         vector<vector<int>> dp(day, vector<int>(4, -1));
//         int last = 3; 
//         return func(day - 1, last, matrix, dp); 
//     }
// };

class Solution{
    int ninjaTraining(vector<vector<int>>& matrix){
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]); 
        dp[0][3] = max(matrix[0][0], matrix[0][1], matrix[0][2]); 
        for(int day = 1; day < n; day++){
            for(int last = 0; last < 4; last++){
                dp[day][last] = 0; 
                for(int task = 0; task <= 2; task++){
                    if(task != last){
                        int activity = matrix[day][task] + dp[day - 1][ task]; 
                        dp[day][task] = max(dp[day][last], activity);
                    }
                }

            }
        }
        return dp[n-1][3];
    }
};