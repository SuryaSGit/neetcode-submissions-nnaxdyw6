class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = (low+high)/2;
        if(nums[low] < nums[high]){
            return nums[low];
        }
        low = 1;
        while(low <= high){
            if(high==low){
                return nums[high];
            }
            if(nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            if(nums[mid]>nums[0]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            mid = (low + high)/2;
        }
        return nums[mid];
    }
};
