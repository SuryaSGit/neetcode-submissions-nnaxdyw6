class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int,int> vals;
        for(int i = 0; i < k; i++){
            vals[nums[i]]++;
        }
        vector<int> result;
        result.push_back(vals.rbegin()->first);
        for(int i = k; i < nums.size(); i++){
            vals[nums[i-k]]--;
            if(vals[nums[i-k]]==0){
                vals.erase(nums[i-k]);
            }
            vals[nums[i]]++;
            result.push_back(vals.rbegin()->first);
        }
        return result;
    }
};
