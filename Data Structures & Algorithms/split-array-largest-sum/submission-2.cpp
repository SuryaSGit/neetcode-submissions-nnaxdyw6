class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int temp=0;
        for(int i = 0; i < nums.size(); i++){
            temp = temp + nums[i];
        }
        return binary_search(0,temp,temp,k,nums);
    }
    int binary_search(int low, int high, int nums_sum, int k, vector<int>& nums){
        int mid = (low + high)/2;
        if(low > high){
            return -1;
        }
        if(check_valid(mid,nums,k)){
            if(!check_valid(mid-1,nums,k)){
                return mid;
            }
            return binary_search(low,mid-1,nums_sum,k,nums);
        }
        else{
            return binary_search(mid+1,high,nums_sum,k,nums);
        }
    }

    bool check_valid(int max_sum, vector<int>& nums, int k){
        int count = 1;
        int temp_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max_sum){
                return false;
            }
            if(temp_sum + nums[i] > max_sum){
                count++;
                temp_sum = 0;
            }
            temp_sum = temp_sum + nums[i];
        }
        if(count <= k){
            return true;
        }
        return false;
    }
};