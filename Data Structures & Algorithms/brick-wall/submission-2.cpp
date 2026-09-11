class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> edges;
        int res = 0;
        for(vector<int> i : wall){
            int cur = 0;
            for(int j = 0; j < i.size()-1; j++){
                cur+=i[j];
                edges[cur]++;
                res = max(res,edges[cur]);
            }
        }
        return wall.size()-res;
    }
};