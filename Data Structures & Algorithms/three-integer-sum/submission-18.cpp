class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int p1=0;
        int p2=0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i]==nums[i-1]){
                continue;
            }
            p1 = i + 1;
            p2 = nums.size()-1;
            while(p1 < p2){
                int cur = nums[p1] + nums[p2] + nums[i];
                if(cur > 0){
                    p2--;
                }
                else if(cur < 0){
                    p1++;
                }
                else{
                    result.push_back({nums[i],nums[p1],nums[p2]});
                    p1++;
                    p2--;
                    while(p1 < p2 && nums[p1] == nums[p1-1]){
                        p1++;
                    }
                }
            }
        }
        return result;
    }
    //TC: O(N^2)
    //SC: O(1) / O(N^2) for output vect
};
