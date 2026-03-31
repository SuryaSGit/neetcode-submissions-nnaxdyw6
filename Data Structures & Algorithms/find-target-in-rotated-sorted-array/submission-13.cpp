class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(target == nums[0]){
            return 0;
        }
        if(target == nums[nums.size()-1]){
            return nums.size()-1;
        }
        int low = 0;
        int high = nums.size() - 1;
        int mid = (low + high) / 2;
        while(low <= high){
            cout << "High: " << high << endl;
            cout << "Low: " << low << endl;
            cout << "Mid: " << mid << endl;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid] > target){
                if(nums[mid] < nums[nums.size()-1]){
                    high = mid - 1;
                }
                else if(target > nums[0]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(nums[mid] < nums[nums.size()-1]){
                    if(target > nums[nums.size()-1]){
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                else if(target > nums[0]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            mid = (low + high)/2;
        }
        return -1;
    }
};
