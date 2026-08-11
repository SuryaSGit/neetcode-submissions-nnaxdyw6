class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                nums[i] = 0;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            int cur = abs(nums[i]);
            if(cur >= 1 && cur <= nums.size()){
                if(nums[cur-1] > 0){
                    nums[cur-1] = -nums[cur-1];
                }
                else if(nums[cur-1] == 0){
                    nums[cur-1] = -nums.size() - 1;
                }
            }
        }
        for(int i = 1; i <= nums.size(); i++){
            if(nums[i-1] >= 0){
                return i;
            }
        }
        return nums.size()+1;
    }
};