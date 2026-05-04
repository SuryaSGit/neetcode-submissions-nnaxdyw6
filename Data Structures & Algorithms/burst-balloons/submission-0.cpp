class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 2,vector<int>(nums.size() + 2));
        int n = nums.size(); 
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        for(int l = n; l >= 1; l--){
            for(int r = l; r <= n; r++){
                for(int i = l; i <= r; i++){
                    int temp = nums[l - 1] * nums[i] * nums[r + 1];
                    temp = temp + dp[l][i-1];
                    temp = temp + dp[i+1][r];
                    dp[l][r] = max(dp[l][r],temp);
                }
            }
        }
        return dp[1][n];
    }
};
