class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in_degree(n+1);
        vector<int> out_degree(n+1);
        for(int i = 0; i < trust.size(); i++){
            in_degree[trust[i][1]]++;
            out_degree[trust[i][0]]++;
        }
        for(int i = 1; i <= n; i++){
            if(in_degree[i] == n - 1 && out_degree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};