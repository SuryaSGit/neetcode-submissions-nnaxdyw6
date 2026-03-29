class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> temp;
        for(int i = 0; i < nums.size(); i++){
            if(temp.contains(nums[i])){
                return true;
            }
            temp.insert(nums[i]);
        }
        return false;
    }
};