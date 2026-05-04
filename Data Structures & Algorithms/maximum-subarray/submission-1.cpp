class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = INT_MIN;
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(cur < 0){
                cur = nums[i];
            }
            else{
                cur = cur + nums[i];
            }
            res = max(res,cur);
        }
        return res;
    }
};
