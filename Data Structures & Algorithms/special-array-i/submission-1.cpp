class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1){
            return true;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]%2 == 0){
                if(i > 0 && nums[i-1]%2 == 0){
                    return false;
                }
                if(i < nums.size() - 1 && nums[i + 1]%2 == 0){
                    return false;
                }
            }
            if(nums[i]%2 == 1){
                if(i > 0 && nums[i-1]%2 == 1){
                    return false;
                }
                if(i < nums.size() - 1 && nums[i + 1]%2 == 1){
                    return false;
                }
            }
        }
        return true;
    }
};