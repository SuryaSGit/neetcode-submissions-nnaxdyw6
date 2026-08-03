class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <= 2){
            return true;
        }
        bool is_increasing = false;
        bool both = false;
        if(nums[1] > nums[0]){
            is_increasing = true;
        }
        if(nums[1] == nums[0]){
            both = true;
        }
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i+1] != nums[i]){
                if(both){
                    if(nums[i+1] > nums[i]){
                        is_increasing = true;
                    }
                }
                both = false;
            }
            if(!both && is_increasing && nums[i+1] < nums[i]){
                return false;
            }
            if(!both && !is_increasing && nums[i+1] > nums[i]){
                return false;
            }
        }
        return true;
    }
};