class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos;
        queue<int> neg;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                neg.push(nums[i]);
            }
            else{
                pos.push(nums[i]);
            }
        }
        vector<int> res;
        while(!neg.empty()){
            res.push_back(pos.front());
            res.push_back(neg.front());
            pos.pop();
            neg.pop();
        }
        return res;
    }
};