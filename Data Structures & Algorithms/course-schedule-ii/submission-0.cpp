class Solution {
public:
    vector<int> result;
    vector<bool> selected;
    bool cycle = false;
    void dfs(int& numCourses, unordered_map<int,vector<int>>& prereq_graph, vector<bool> cur_stack, int to_take){
        if(cur_stack[to_take]==true){
            cycle = true;
            return;
        }
        if(cycle){
            return;
        }
        cur_stack[to_take]=true;
        for(int i : prereq_graph[to_take]){
            if(!selected[i]){
                dfs(numCourses,prereq_graph,cur_stack,i);
            }
        }
        selected[to_take] = true;
        result.push_back(to_take);
        cur_stack[to_take] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> prg;
        for(int i = 0; i < prerequisites.size(); i++){
            prg[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool> temp;
        for(int i = 0; i < numCourses; i++){
            selected.push_back(false);
            temp.push_back(false);
        }
        for(int i = 0; i < numCourses; i++){
            if(!selected[i]){
                dfs(numCourses,prg,temp,i);
            }
            vector<int> empty;
            if(cycle){
                return empty;
            }
        }
        return result;
    }
};
