class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> in_window;
        for(int i = 0; i < nums.size(); i++){
            if(in_window[nums[i]] > 0){
                return true;
            }
            if(i >= k){
                in_window[nums[i-k]]--;
            }
            in_window[nums[i]]++;
        }
        return false;
    }
};