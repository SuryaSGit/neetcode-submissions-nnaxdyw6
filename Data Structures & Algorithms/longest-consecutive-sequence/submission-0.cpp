class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> vals;
        for(int i = 0; i < nums.size(); i++){
            vals.insert(nums[i]);
        }
        int max_length = 0;
        int length = 0;
        for(int i = 0; i < nums.size(); i++){
            if(vals.contains(nums[i]-1)==false){
                length = 0;
                while(vals.contains(nums[i]+length)){
                    length++;
                }
                max_length = max(max_length,length);
            }
        }
        return max_length;
    }
};
