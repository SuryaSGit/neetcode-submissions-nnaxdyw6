class Solution {
public:
    bool canJump(vector<int>& nums) {
        queue<int> to_visit;
        unordered_set<int> visited;
        to_visit.push(0);
        while(!to_visit.empty()){
            int cur = to_visit.front();
            to_visit.pop();
            if(visited.contains(cur)){
                continue;
            }
            visited.insert(cur);
            if(cur == nums.size() -1){
                return true;
            }
            for(int i = cur + 1; i <= nums[cur] + cur; i++){
                if(i == nums.size()){
                    return true;
                }
                to_visit.push(i);
            }
        }
        return false;
    }
};
