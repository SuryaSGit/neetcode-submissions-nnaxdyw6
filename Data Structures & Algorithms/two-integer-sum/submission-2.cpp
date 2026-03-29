class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> temp;
        for(int i = 0; i < nums.size(); i++){
            if(temp.contains(target-nums[i])){
                vector<int> result;
                result.push_back(temp[target-nums[i]]);
                result.push_back(i);
                return result;
            }
            temp[nums[i]]=i;
        }
    }
};
