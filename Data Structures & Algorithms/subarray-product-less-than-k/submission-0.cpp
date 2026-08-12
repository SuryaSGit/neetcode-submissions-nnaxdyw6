class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int cur_product = 1;
        int res = 0;
        for(int r = 0; r < nums.size(); r++){
            cur_product*=nums[r];
            while(left < r && cur_product >= k){
                cur_product/=nums[left];
                left++;
            }
            if(cur_product >= k){
                continue;
            }
            int temp = 1 + r - left;
            res = res + temp;
        }
        return res;
    }
};