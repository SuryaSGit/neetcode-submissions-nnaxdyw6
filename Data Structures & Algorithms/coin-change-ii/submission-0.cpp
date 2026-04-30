class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        for(int i = 0; i < dp.size(); i++){
            dp[i][0] = 1; 
        }
        for(int i = coins.size() - 1; i >= 0 ;i--){
            for(int j = 1; j <= amount; j++){
                if(coins[i] <= j){
                    dp[i][j] += dp[i+1][j];
                    dp[i][j] += dp[i][j-coins[i]];
                }
            }
        }
        return dp[0][amount];
    }
};
