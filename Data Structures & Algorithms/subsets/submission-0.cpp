class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() == 0){
            result.push_back({});
            return result;
        }
        int temp = nums[0];
        nums.erase(nums.begin());
        result = subsets(nums);
        int temp2 = result.size();
        for(int i = 0; i < temp2; i++){
            vector<int> temp3 = result[i];
            temp3.push_back(temp);
            result.push_back(temp3);
        }
        return result;
    }
};
