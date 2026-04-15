class Solution {
public:
    bool result = true;
    void dfs(unordered_map<int,vector<int>>& graph, vector<int>& to_do, int to_search, unordered_set<int> visited){
        if(result == false){
            return;
        }
        if(visited.contains(to_search)){
            result = false;
            return;
        }
        if(to_do[to_search]==1){
            return;
        }
        to_do[to_search] = 1;
        for(int i : graph[to_search]){
            visited.insert(to_search);
            dfs(graph, to_do, i, visited);
            visited.erase(to_search);
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> graph;
        for(int i = 0; i < prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> to_do(numCourses);
        for(int i = 0; i < numCourses; i++){
            if(to_do[i]==0){
                unordered_set<int> temp;
                dfs(graph,to_do,i,temp);
                if(result == false){
                    return result;
                }
            }
        }
        return result;
    }
};
