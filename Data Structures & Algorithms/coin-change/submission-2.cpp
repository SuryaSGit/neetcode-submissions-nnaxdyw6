class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);
        if(amount == 0){
            return 0;
        }
        for(int i = 0 ; i < coins.size(); i++){
            if(coins[i] <= amount){
                dp[coins[i]] = 1;
            }
        }
        for(int i = 0; i <= amount; i++){
            if(dp[i] == 0){
                dp[i] = -1;
            }
            for(int j = 0; j < coins.size(); j++){
                if(i < coins[j]){
                    continue;
                }
                if(dp[i - coins[j]] == -1){
                    continue;
                }
                if(dp[i] == -1 || dp[i] > dp[i - coins[j]]){
                    dp[i] = 1 + dp[i - coins[j]];
                }
            }
        }
        return dp[amount];
    }
};
