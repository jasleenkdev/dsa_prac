#include <vector>
#include <unordered_map>
#include <iostream> 
using namespace std;


class Solution{
    bool canCross(vector<int>& stones){
        int n = stones.size(); 
        unordered_map<int, int> pos; 
        for(int i = 0; i <= n; i++){
            pos[stones[i]] = i; 
        }
        vector<vector<bool>> dp(n, vector<bool>(n+1, false));
        dp[0][0] = true; 

        for(int i = 0; i < n; i++){
            for(int k = 0 ; k <= n; k++){
                if (dp[i][k]){
                    for(int steps : {k-1, k, k+1}){
                        if (steps > 0){
                            int next = stones[i] + steps; 
                            if(pos.count(next)){
                                int j = pos[next]; 
                                dp[j][steps] = true; 
                                if(j == n-1) return true; 
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};