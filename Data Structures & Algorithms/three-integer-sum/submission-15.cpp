class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        int p1;
        int p2;
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
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[p1]);
                    temp.push_back(nums[p2]);
                    p1++;
                    while(nums[p1]==nums[p1-1]){
                        p1++;
                    }
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};
