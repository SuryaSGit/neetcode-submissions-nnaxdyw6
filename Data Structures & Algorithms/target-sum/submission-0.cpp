class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> dp(nums.size() + 1);
        dp[0][0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(auto& temp : dp[i]){
                dp[i+1][temp.first + nums[i]] += temp.second;
                dp[i+1][temp.first - nums[i]] += temp.second;
            }
        }
        return dp[nums.size()][target];
    }
};
