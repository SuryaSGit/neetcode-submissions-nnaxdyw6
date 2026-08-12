class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i++){
            res[k%nums.size()] = nums[i];
            k++;
        }
        nums = res;
    }
};