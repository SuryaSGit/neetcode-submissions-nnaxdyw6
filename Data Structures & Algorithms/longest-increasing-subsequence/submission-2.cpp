class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[nums.size()-1] = 1;
        int res = 1;
        for(int i = nums.size()-2; i >= 0; i--){
            dp[i] = 1;
            for(int j = i; j < nums.size(); j++){
                if(nums[j] > nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};
