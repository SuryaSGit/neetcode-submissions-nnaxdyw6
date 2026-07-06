class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int minsqrpos = 0;
        int minsqr = nums[0]*nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]*nums[i] < minsqr){
                minsqrpos = i;
                minsqr = nums[i] * nums[i];
            }
        }
        int p1 = minsqrpos;
        int p2 = minsqrpos;
        vector<int> res;
        res.push_back(minsqr);
        while(p1 > 0 || p2 < nums.size() - 1){
            int temp1 = INT_MAX;
            int temp2 = INT_MAX;
            if(p1 > 0){
                temp1 = nums[p1-1] * nums[p1 - 1];
            }
            if(p2 < nums.size() - 1){
                temp2 = nums[p2+1] * nums[p2 + 1];
            }
            if(temp1 < temp2){
                res.push_back(temp1);
                p1--;
            }
            else{
                res.push_back(temp2);
                p2++;
            }
        }
        return res;
    }
};