class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int k : nums){
            sum = sum + k;
        }
        if(sum%2==1){
            return false;
        }
        int target = sum/2;
        unordered_set<int> can_form;
        can_form.insert(0);
        for(int i = 0; i < nums.size(); i++){
            unordered_set<int> temp;
            for(int j : can_form){
                temp.insert(j);
                temp.insert(nums[i] + j);
            }
            can_form = temp;
            if(temp.contains(target)){
                return true;
            }
        }
        return false;
    }
};
