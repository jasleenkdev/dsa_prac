#include <vector>
#include <unordered_map>
#include <iostream> 
using namespace std;

// class Solution{
//     private:
//     int func(int ind, vector<int> &arr){
//         if (ind == 0) return arr[ind]; 
//         if (ind < 0) return 0;
//         int pick = arr[ind] + func(ind - 2, arr); 
//         int notPick =  func(ind - 1, arr); 
//         return max(pick, notPick); 
//     }
//     public: 
//     int houseRobber(vector<int>& money){
//         int n = money.size(); 
//         vector<int> arr1; 
//         vector<int> arr2; 
//         if (n == 1) return money[0]; 
//         for(int i = 0; i < n ; i++){
//             if (i != n - 1) arr1.push_back(money[i]); 
//             if (i != 0) arr2.push_back(money[i]); 
//         }
//         int ans1 = func(arr1.size() - 1, arr1); 
//         int ans2 = func(arr2.size() - 1, arr2); 
//         return max(ans1, ans2); 
//     }
// };

// class Solution{
//     int func(int ind, vector<int> &arr, vector<int> &dp){
//         if (ind == 0) return arr[ind]; 
//         if (ind < 0) return 0;
//         if (dp[ind] != -1) return dp[ind]; 
//         int pick = func(ind - 2, arr, dp) + dp[ind]; 
//         int notpick = func(ind - 1, arr, dp);
//         return dp[ind] = max(pick, notpick);
//     }
//     public:
//     int houseRobber(vector<int>& money){
//         int n = money.size(); 
//         vector<int> arr1; 
//         vector<int> arr2;
//         if (n==1) return money[0]; 
//         for(int i = 0; i < n ; i++){
//             if (i != n - 1) arr1.push_back(money[i]); 
//             if (i != 0) arr2.push_back(money[i]); 
//         }
//         vector<int> dp(n, -1); 
//         int ans1 = func(arr1.size() - 1, arr1, dp); 
//         vector<int> dp1(n , -1); 
//         int ans2 = func(arr2.size()-1, arr2, dp1); 
//         return max(ans1, ans2); 
//     }
// };

class Solution{
    int func(vector<int> &nums){
        int ind = nums.size(); 
        vector<int> dp(ind, 0); 
        dp[0] = nums[0]; 
        for(int i = 0; i < ind; i++){
            int pick = nums[i]; 
            if (i > 1){
                pick += dp[i-2]; 
            }
            int notpick = dp[i-1]; 
            dp[i] = max(pick, notpick); 
        }
        return dp[ind - 1];
    }
    public: 
    int houseRobber(vector<int>& money){
        int n = money.size(); 
        vector<int> arr1; 
        vector<int> arr2; 
        if (n == 1) return money[0]; 
        for(int i = 0; i < n; i++){
            if(i != n - 1) arr1.push_back(money[i]); 
            if(i != 0) arr2.push_back(money[i]); 
        }
        int ans1 = func(arr1); 
        int ans2 = func(arr2); 
        return max(ans1, ans2); 
    }
};