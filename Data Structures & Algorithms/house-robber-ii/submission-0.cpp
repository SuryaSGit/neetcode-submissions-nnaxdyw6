class Solution {
public:
    int rob(vector<int>& nums) {
        int max_1 = 0;
        int max_2 = 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size() -1 ; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        max_1 = dp[dp.size()-2];
        dp[1]=nums[1];
        dp[2] = max(nums[1],nums[2]);
        for(int i = 3; i < nums.size(); i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        max_2 = dp[dp.size()-1];
        return max(max_1,max_2);
    }
};
