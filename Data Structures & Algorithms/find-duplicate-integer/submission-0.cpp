class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        fast = nums[nums[fast]];
        slow = nums[slow];
        while(slow != fast){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        while(slow != fast){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};
