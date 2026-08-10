class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),1);
        //product of everything before
        prefix[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        int temp = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            prefix[i]*=temp;
            temp = temp * nums[i];
        }
        return prefix;
    }
};
