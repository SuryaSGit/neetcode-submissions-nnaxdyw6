class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> jumps_away(nums.size(),10001);
        jumps_away[nums.size() - 1] = 0;
        for(int i = nums.size() - 2; i >= 0; i --){
            for(int j = i + 1; j <= i + nums[i]; j++){
                jumps_away[i] = min(jumps_away[i], 1+jumps_away[j]);
            }
        }
        return jumps_away[0];
    }
};
