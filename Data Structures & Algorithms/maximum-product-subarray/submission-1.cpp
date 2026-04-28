class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curmax = 1;
        int curmin = 1;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int temp = curmax*num;
            curmax = max(temp,curmin*num);
            curmax = max(curmax,num);
            curmin = min(temp, curmin * num);
            curmin = min(curmin,num);
            res = max(res,curmax);
        }
        return res;
    }
};
