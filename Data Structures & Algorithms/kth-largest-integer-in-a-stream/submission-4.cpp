class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> vals;
    int k_;
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(int i = 0; i < nums.size(); i++){
            vals.push(nums[i]);
            if(vals.size()>k_){
                vals.pop();
            }
        }

    }
    
    int add(int val) {
        vals.push(val);
        if(vals.size()>k_){
            vals.pop();
        }
        return vals.top();
    }
};
