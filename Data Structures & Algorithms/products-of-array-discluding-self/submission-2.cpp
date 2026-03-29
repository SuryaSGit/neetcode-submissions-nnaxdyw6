class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        int sum = 1;
        int zer = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==0&&zer == -1){
                zer = i;
            }
            else if(nums[i]==0&&zer!=-1){
                return std::vector<int>(nums.size(),0);
            }
            else{
                sum = sum * nums[i];
            }
        }
        if(zer!=-1){
            result[zer]=sum;
            sum = 0;
        }
        for(int i = 0; i < nums.size(); i++){
            if(i != zer){
                result[i]=sum/nums[i];
            }
        }
        return result;
    }
};
