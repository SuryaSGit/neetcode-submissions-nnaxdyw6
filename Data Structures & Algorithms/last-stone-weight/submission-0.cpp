class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,less<int>> vals;
        for(int num : stones){
            vals.push(num);
        }
        while(vals.size() > 1){
            int x = vals.top();
            vals.pop();
            int y = vals.top();
            vals.pop();
            if(x > y){
                vals.push(x-y);
            }
        }
        if(vals.size() == 0){
            return 0;
        }
        return vals.top();
    }
};
