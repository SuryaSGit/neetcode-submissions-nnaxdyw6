class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left_pointer = 0;
        int right_pointer = 0;
        int cur_sum = nums[0];
        int res = nums.size() + 1;
        while(right_pointer < nums.size()){
            if(cur_sum >= target){
                res = min(res, 1+right_pointer - left_pointer);
                cur_sum = cur_sum - nums[left_pointer];
                left_pointer++;
            }
            else{
                right_pointer++;
                if(right_pointer < nums.size()){
                    cur_sum += nums[right_pointer];
                }
            }
        }
        if(res==nums.size() + 1){
            return 0;
        }
        return res;
    }
};