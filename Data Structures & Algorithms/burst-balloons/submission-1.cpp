//Assume you pick one balloon to pop last in an interval (l,r). Then, since everything else
//is gone, you will get (l-1 * r + 1) coins for that balloon. To pop everything else, that is 
//2 seperate intervals. So, add the dp of those to get the result. Now do this for all the balloons
//in the interval, and find the max. Work up to find dp(1,nums.size()).
//Add 1 at the beginning and end to make things easier. Do DP from bottom right 
//to top left. Result will be in dp[1][n].
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
