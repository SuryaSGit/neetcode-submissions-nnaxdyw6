class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> alr_seen;
        int write_pointer=0;
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(alr_seen.contains(nums[i])){
                continue;
            }
            nums[write_pointer] = nums[i];
            write_pointer++;
            k = write_pointer;
            alr_seen.insert(nums[i]);
        }
        int num_pops = nums.size() - k;
        for(int i = 0; i < num_pops; i++){
            nums.pop_back();
        }
        return k;
    }
};